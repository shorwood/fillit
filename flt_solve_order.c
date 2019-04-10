/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   flt_solve_order.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shorwood <shorwood@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/05 04:13:14 by shorwood     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/10 07:32:34 by shorwood    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"

/*
** *****************************************************************************
*/

static int	place(__uint128_t *grid, t_tri *tri)
{
	if (*grid & tri->grid >> (tri->x + tri->y * 11))
		return (0);
	*grid |= tri->grid >> (tri->x + tri->y * 11);
	return (1);
}

/*
** *****************************************************************************
*/

static void	unplace(__uint128_t *grid, t_tri *tri)
{
	*grid ^= tri->grid >> (tri->x + tri->y * 11);
}

/*
** *****************************************************************************
*/

static int	insert(__uint128_t *grid, t_tri *tri, int siz)
{
	tri->y = -1;
	while (++tri->y < siz)
	{
		tri->x = -1;
		while (++tri->x < siz)
			if (place(grid, tri))
				return (1);
	}
	return (0);
}

/*
** *****************************************************************************
*/

int 		unique(t_lst lst, __uint128_t *grid)
{
	t_lsti lsti;

	lsti = *lst;
	while (lsti)
	{
		if (*(__uint128_t*)(lsti->data) == *grid)
			return (0);
		lsti = lsti->next;
	}
	ft_lstadd(lst, grid);
	return (1);
}

/*
** *****************************************************************************
*/

static t_lst tr;
static int	pack(__uint128_t *grid, t_lst tris, int siz)
{
	t_tri	*tri;
	t_lst	out;
	int 	len;
	int		i;

	out = ft_lstnew(0);
	if ((len = ft_lstlen(tris)) < 1)
		return (1);
	i = 0;
	while(1)
	{
		if (!(tri = ft_lstdel(tris, i)))
			break;
		if (unique(out, &(tri->grid)) && insert(grid, tri, siz))
		{
			if (pack(grid, tris, siz))
			{
				ft_lstclr(out, FT_LCLR_ITEM | FT_LCLR_LIST);
				return (1);
			}
			else
				unplace(grid, tri);
		}
		ft_lstins(tris, tri, i++);
	}
	ft_lstclr(out, FT_LCLR_ITEM | FT_LCLR_LIST);
	return (0);
}

/*
** *****************************************************************************
*/


int			flt_solve(t_lst tris)
{
	int			i;
	int			siz;
	__uint128_t	grid;
	t_lst 		tmp;

	tmp = ft_lstcpy(tris);
	tr = tmp;
	if (!tris)
		return (0);
	siz = ft_sqrtillu(ft_lstlen(tmp) * 4);
	while (siz < 11)
	{
		i = 0;
		grid = ~0;
		while (i++ < siz)
			grid = grid >> 11 | ft_bit128clamp((__uint128_t)~0, 128 - siz, 117);
		if (pack(&grid, tmp, siz))
			break;
		siz++;
	}
	return (siz);
}
