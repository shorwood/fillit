/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   flt_solve_order.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shorwood <shorwood@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/05 04:13:14 by shorwood     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/10 02:58:21 by shorwood    ###    #+. /#+    ###.fr     */
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
	__uint128_t tri_grid;
	
	tri_grid = tri->grid >> (tri->x + tri->y * 11);
	if (*grid & tri_grid)
		return (0);
	*grid |= tri_grid;
	return (1);
}

static void	unplace(__uint128_t *grid, t_tri *tri)
{
	*grid ^= tri->grid >> (tri->x + tri->y * 11);
}

static t_lst tr;

/*
** *****************************************************************************
*/

static int	insert(__uint128_t *grid, t_lsti lsti, int siz, int deep)
{
	t_tri	*tri;

	tri = lsti->data;
	tri->y = -1;
	while (++tri->y < siz)
	{	
		tri->x = -1;
		while (++tri->x < siz)
		{
			if (place(grid, tri))
			{
				if (!lsti->next || insert(grid, lsti->next, siz, deep + 1))
					return (1);
				else
					unplace(grid, tri);
			}
		}
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
	__uint128_t	grid;

	tr = tris;

	if (!tris)
		return (0);
	siz = ft_sqrtillu(ft_lstlen(tris) * 4);
	while (siz < 63)
	{
		i = 0;
		grid = ~0;
		while (i++ < siz)
			grid = grid >> 11 | ft_bit128clamp((__uint128_t)~0, 128 - siz, 117);
		if (insert(&grid, *tris, siz, 0))
			break;
		siz++;
	}
	return (siz);
}