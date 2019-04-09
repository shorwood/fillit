/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   flt_solve.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shorwood <shorwood@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/05 04:13:14 by shorwood     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/09 23:09:08 by shorwood    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"

/*
** *****************************************************************************
*/

static int	place(uint64_t grid[64], t_tri *tri)
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

static int	unplace(uint64_t grid[64], t_tri *tri)
{
	int	i;

	i = -1;
	while (++i < tri->h)
		grid[tri->y + i] ^= tri->grid[i] >> tri->x;
	return (1);
}

int tricmp(t_tri *t1, t_tri *t2)
{
	int i;

	i = -1;
	while (t1->grid[i] == t2->grid[i] && i < 4)
		i++;
	return (i == 4);
}

/*
** *****************************************************************************
*/
static t_lst tr;

#include <stdio.h>

static int	insert(uint64_t *grid, t_lsti lsti, int siz, int deep)
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
	uint64_t	grid[64];

	tr = tris;

	if (!tris)
		return (0);
	siz = ft_sqrtillu(ft_lstlen(tris) * 4);
	while (siz < 63)
	{
		i = 0;
		while (i < siz)
			grid[i++] = (uint64_t)~0 >> siz;
		grid[i] = ~0;
		if (insert(grid, *tris, siz, 0))
			break;
		siz++;
	}
	return (siz);
}