/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   flt_solve.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shorwood <shorwood@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/05 04:13:14 by shorwood     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/29 18:44:04 by shorwood    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"

/*
** *****************************************************************************
** Place or unplace the tetrimino grid on the input grid.
** *****************************************************************************
*/

static int	set(uint16_t *grid, t_tri *tri, int val)
{
	if (val)
		if (grid[tri->y] & tri->grid[0] >> tri->x
			|| grid[tri->y + 1] & tri->grid[1] >> tri->x
			|| grid[tri->y + 2] & tri->grid[2] >> tri->x
			|| grid[tri->y + 3] & tri->grid[3] >> tri->x)
			return (0);
	grid[tri->y] ^= tri->grid[0] >> tri->x;
	grid[tri->y + 1] ^= tri->grid[1] >> tri->x;
	grid[tri->y + 2] ^= tri->grid[2] >> tri->x;
	grid[tri->y + 3] ^= tri->grid[3] >> tri->x;
	return (val);
}

/*
** *****************************************************************************
** Try to insert a tetrimino into a grid by finding the valid first position.
** If no position is found, 0 is returned.
** *****************************************************************************
*/

static int	insert(uint16_t *grid, t_tri *tri, int siz, t_int2 *off)
{
	tri->y = off->y;
	tri->x = off->x;
	while (tri->y < siz)
	{
		while (tri->x < siz)
		{
			off->x++;
			if (set(grid, tri, 1))
				return (1);
			tri->x++;
		}
		tri->x = 0;
		off->x = 0;
		off->y++;
		tri->y++;
	}
	return (0);
}

/*
** *****************************************************************************
** Tell if a tetrimino figure has already been used. If not already used, the
** function will register the figure for future use.
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
** Will try to pack as many tetriminos into a fixed size grid. If it hasn't
** found
** *****************************************************************************
*/

static int	pack(uint16_t *grid, t_lst tris, int siz)
{
	uint64_t	old[24];
	t_lsti		lsti;
	t_int2		off;
	int			i;

	if (!*tris)
		return (1);
	i = 0;
	old[0] = 0;
	while ((lsti = ft_lstidel(tris, i)))
	{
		off = (t_int2){0, 0};
		if (unique(old, lsti->data))
		{
			while (insert(grid, (t_tri*)lsti->data, siz, &off))
				if (pack(grid, tris, siz)
				|| set(grid, (t_tri*)lsti->data, 0))
					return (1);
				else if (siz > 6)
					break ;
		}
		ft_lstiins(tris, lsti, i++);
	}
	return (0);
}

/*
** *****************************************************************************
** Will try to pack as many tetriminos into a grid. Will increase size of the
** grid if necessary.
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
	buf = ft_lstcpy(tris);
	siz = ft_sqrtillu(ft_lstlen(tris) * 4);
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
	ft_lstclr(buf, FT_LCLR_LIST | FT_LCLR_ITEM);
	return (siz);
}
