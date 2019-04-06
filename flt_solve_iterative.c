/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   flt_solve_iterative.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shorwood <shorwood@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/05 04:13:14 by shorwood     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/05 14:55:50 by shorwood    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"

/*
** *****************************************************************************
*/

static int	place_tri(uint64_t grid[64], t_tri *tri)
{
	int	i;

	i = -1;
	while (++i < tri->h)
		if (grid[tri->y + i] & tri->grid[i] >> tri->x)
			return (0);
	i = -1;
	while (++i < tri->h)
		grid[tri->y + i] |= tri->grid[i] >> tri->x;
	return (1);
}

/*
** *****************************************************************************
*/

static int	insert_tri(uint64_t grid[64], t_tri *tri, int siz)
{ 
	while (tri->y < siz)
	{
		while (tri->x < siz)
		{
			if (place_tri(grid, tri))
				return (1);
			tri->x++;
		}
		tri->y++;
		tri->x = 0;
	}
	return (0);
}

/*
** *****************************************************************************
*/

static int	test_order(t_lst tris, int siz)
{
	t_lsti		lsti;
	uint64_t	grid[64];
	int			i;

	i = 0;
	while (i < siz)
		grid[i++] = (uint64_t)~0 >> siz;
	while (i < 64)
		grid[i++] = ~0;
	i = 0;
	lsti = *tris;
	while (lsti)
	{
		((t_tri*)lsti->data)->x = i % siz;
		((t_tri*)lsti->data)->y = i / siz;
		i += ((t_tri*)lsti->data)->o;
		lsti = lsti->next;
	}
	lsti = *tris;
	while (lsti)
	{
		if (!insert_tri(grid, lsti->data, siz))
			return (0);
		lsti = lsti->next;
	}
	return (1);
}

/*
** *****************************************************************************
** This algorithm will try all possible orders / permutations of tetrimino and
** stop as soon as it has found an order that fits into the grid. If it has
** tried all permutations, it will increase the size of the grid. When the
** function exits, the tetriminos will have their 'x' and 'y' coordinates set
** to the last position they were tested on.
** *****************************************************************************
*/

int			flt_solve_iterative(t_lst tris)
{
	t_lsti	lsti;
	t_lst	prm;
	int		siz;

	siz = ft_sqrtillu(ft_lstlen(tris) * 4);
	while (siz < 16)
	{
		prm = ft_lstprm(tris);
		lsti = *prm;
		while (lsti)
		{
			if(test_order(lsti->data, siz))
				return (siz);
			lsti = lsti->next;
		}
		siz++;
	}
	return (0);
}