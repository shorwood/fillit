/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   flt_solve_backtrack.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shorwood <shorwood@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/05 04:13:14 by shorwood     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/05 15:03:21 by shorwood    ###    #+. /#+    ###.fr     */
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

int			flt_solve_backtrack2(uint64_t grid[64], t_lsti lsti, int siz)
{
	t_tri		*tri;
	uint64_t	*snap;
		
	tri = lsti->data;
	tri->y = 0;
	while (tri->y < siz)
	{
		tri->x = 0;
		while (tri->x < siz)
		{
			snap = (uint64_t*)malloc(64 * sizeof(uint64_t));
			ft_memcpy(snap, grid, sizeof(snap));
			if (place_tri(grid, tri))
				if (!lsti->next || flt_solve_backtrack2(grid, lsti->next, siz))
					return (1);
			ft_memcpy(grid, snap, sizeof(snap));
			free(snap);
			tri->x++;
		}
		tri->y++;
	}
	return (0);
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

int			flt_solve_backtrack(t_lst tris)
{
	int			i;
	int			siz;
	uint64_t	grid[64];

	siz = 4;//ft_sqrtillu(ft_lstlen(tris) * 4) -1;
	while (siz < 64)
	{
		i = 0;
		while (i < siz)
			grid[i++] = (uint64_t)~0 >> siz;
		while (i < 64)
			grid[i++] = ~0;
		if (flt_solve_backtrack2(grid, *tris, siz))
			return (siz);
		siz++;
	}
	return (0);
}