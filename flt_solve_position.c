/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   flt_solve_position.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shorwood <shorwood@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/05 04:13:14 by shorwood     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/10 06:59:47 by shorwood    ###    #+. /#+    ###.fr     */
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

static int	pack(__uint128_t *grid, t_lsti lsti, int siz)
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
				if (!lsti->next || pack(grid, lsti->next, siz))
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

int			flt_solve_position(t_lst tris)
{
	int			i;
	int			siz;
	__uint128_t	grid;

	if (!tris)
		return (0);
	siz = ft_sqrtillu(ft_lstlen(tris) * 4);
	while (siz < 12)
	{
		i = 0;
		grid = ~0;
		while (i++ < siz)
			grid = grid >> 11 | ft_bit128clamp((__uint128_t)~0, 128 - siz, 117);
		if (pack(&grid, *tris, siz))
			break;
		siz++;
	}
	return (siz);
}