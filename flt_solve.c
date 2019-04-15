/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   flt_solve.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shorwood <shorwood@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/05 04:13:14 by shorwood     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/15 13:21:03 by shorwood    ###    #+. /#+    ###.fr     */
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

static int	unique(uint64_t *old, t_tri *tri)
{
	while (*old)
		if (*old++ == *(uint64_t*)tri->grid)
			return (0);
	*old = *(uint64_t*)tri->grid;
	*++old = 0;
	return (1);
}

/*
** *****************************************************************************
*/

static int	pack(uint16_t *grid, t_lst tris, int siz)
{
	t_lsti		lsti;
	uint64_t	old[24];
	int			i;

	old[0] = 0;
	if (ft_lstnull(tris))
		return (1);
	i = 0;
	while ((lsti = ft_lstidel(tris, i)))
	{
		if (unique(old, lsti->data)
			&& insert(grid, (t_tri*)lsti->data, siz)
			&& (pack(grid, tris, siz)
			|| place(grid, (t_tri*)lsti->data, 1)))
		{
			ft_lstiins(tris, lsti, i);
			return (1);
		}
		ft_lstiins(tris, lsti, i++);
	}
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

	if (!tris)
		return (0);
	siz = ft_sqrtillu(ft_lstlen(tris) * 4);
	while (siz < 16)
	{
		i = 0;
		while (i < siz)
			grid[i++] = (uint16_t)~0 >> siz;
		grid[i] = (uint16_t)~0;
		if (pack(grid, tris, siz))
			break ;
		siz++;
	}
	return (siz);
}
