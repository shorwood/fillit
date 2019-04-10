/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   flt_solve_permutation.c                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shorwood <shorwood@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/05 04:13:14 by shorwood     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/10 07:22:34 by shorwood    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
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

static int	pack(t_lst tris, int siz)
{
	t_lsti		lsti;
	__uint128_t	grid;
	int			i;

	i = 0;
	grid = ~0;
	while (i++ < siz)
		grid = grid >> 11 | ft_bit128clamp((__uint128_t)~0, 128 - siz, 117);
	lsti = *tris;
	while (lsti)
	{
		if (!insert(&grid, (t_tri*)lsti->data, siz))
			return (0);
		lsti = lsti->next;
	}
	return (1);
}

/*
** *****************************************************************************
** This algorithm will try all possible orders / permutations of tetrimino and
** stop as soon as it has found an order that fits into the grid. If it has
** tried all permutations, it will increase the size of the grid and try again.
** When the function exits, the tetriminos will have their 'x' and 'y'
** coordinates set to the last position they were tested on.
** *****************************************************************************
*/

int			flt_solve_permutation(t_lst tris)
{
	t_lsti	lsti;
	t_lst	prm;
	int		siz;

	if (!tris)
		return (0);
	siz = ft_sqrtillu(ft_lstlen(tris) * 4);
	while (siz < 16)
	{
		prm = ft_lstprm(tris);
		lsti = *prm;
		while (lsti)
		{
			if(pack((t_lst)lsti->data, siz))
				return (siz);
			lsti = lsti->next;
		}
		ft_lstclr(prm, FT_LCLR_ITEM | FT_LCLR_LIST);
		siz++;
	}
	return (0);
}
