/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   flt_solve.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shorwood <shorwood@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/05 04:13:14 by shorwood     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/15 11:18:04 by shorwood    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"

/*
** *****************************************************************************
*/

static int	place(uint16_t *grid, t_tri *tri, int unplace)
{
	if (!unplace)
		if (grid[tri->y] & tri->grid[0] >> tri->x
			|| grid[tri->y + 1] & tri->grid[1] >> tri->x
			|| grid[tri->y + 2] & tri->grid[2] >> tri->x
			|| grid[tri->y + 3] & tri->grid[3] >> tri->x)
			return (0);
	grid[tri->y] ^= tri->grid[0] >> tri->x;
	grid[tri->y + 1] ^= tri->grid[1] >> tri->x;
	grid[tri->y + 2] ^= tri->grid[2] >> tri->x;
	grid[tri->y + 3] ^= tri->grid[3] >> tri->x;
	return (!unplace);
}

/*
** *****************************************************************************
*/

static int	insert(uint16_t *grid, t_tri *tri, int siz)
{
	tri->y = -1;
	while (++tri->y < siz)
	{
		tri->x = -1;
		while (++tri->x < siz)
			if (place(grid, tri, 0))
				return (1);
	}
	return (0);
}

/*
** *****************************************************************************
*/

static int	unique(t_lst lst, uint16_t *grid)
{
	t_lsti	lsti;

	lsti = *lst;
	while (lsti)
	{
		if (*(uint64_t*)((t_tri*)(lsti->data)) == *(uint64_t*)grid)
			return (0);
		lsti = lsti->next;
	}
	ft_lstadd(lst, grid);
	return (1);
}

/*
** *****************************************************************************
*/

static int	pack(uint16_t *grid, t_lst tris, int siz)
{
	t_tri		*tri;
	t_lst		uni;
	int			i;

	if (!*tris)
		return (1);
	uni = ft_lstnew(0);
	i = 0;
	while (1)
	{
		if (!(tri = ft_lstdel(tris, i)))
			break ;
		if (unique(uni, tri->grid)
			&& insert(grid, tri, siz)
			&& (pack(grid, tris, siz)
			|| place(grid, tri, 1)))
		{
			ft_lstclr(uni, FT_LCLR_ITEM | FT_LCLR_LIST);
			return (1);
		}
		ft_lstins(tris, tri, i++);
	}
	ft_lstclr(uni, FT_LCLR_ITEM | FT_LCLR_LIST);
	return (0);
}

/*
** *****************************************************************************
*/

int			flt_solve(t_lst tris)
{
	int			i;
	int			siz;
	uint16_t	grid[16];
	t_lst		buf;

	if (!tris)
		return (0);
	if (!(buf = ft_lstcpy(tris)))
		return (0);
	siz = ft_sqrtillu(ft_lstlen(buf) * 4);
	while (siz < 16)
	{
		i = 0;
		while (i < siz)
			grid[i++] = (uint16_t)~0 >> siz;
		grid[i] = (uint16_t)~0;
		if (pack(grid, buf, siz))
			break ;
		siz++;
	}
	ft_lstclr(buf, FT_LCLR_ITEM | FT_LCLR_LIST);
	return (siz);
}
