/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   flt_solve2.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shorwood <shorwood@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/15 00:22:01 by shorwood     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/03 20:26:25 by shorwood    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"
/*
size_t	flt_solve(t_flt_grid	)
{

}
*/
/*

int			flt_solve2_collide_tri(t_flt tri, t_flt_grid grid, int siz)
{
	uint8_t		yt;
	uint8_t		yg;

	yt = 0;
	yg = tri.y;
	while (yt < tri.siz && yg <= siz)
	{
		if (grid[yg] & tri.grid[yt] >> tri.x)
			return (1);
		grid[yg++] |= tri.grid[yt++] >> tri.x;
	}
	return (0);
}

int			flt_solve2_collide_triset(t_flt *triset, int *idx, int siz)
{
	int i;
	t_flt_grid grid;

	i = 0;
	flt_solve2_grid_reset(grid, siz);
	while (triset->siz)
	{
		if (flt_solve2_collide_tri(*triset++, grid, siz))
			return (1);
		*idx = ++i;
	}
	return (0);
}

void		flt_solve2_triset_reset(t_flt *triset)
{
	while (triset->siz)
	{
		triset->x = 0;
		triset->y = 0;
		triset++;
	}
}

int			flt_solve2(t_flt *triset)
{
	int	idx;
	int siz;

	idx = 0;
	siz = 2;
	while (siz < 64)
	{
		flt_solve2_triset_reset(triset);



		while (triset[idx].y < siz)
		{
			triset[idx].x = 0;


			while (triset[idx].x < siz)
			{


				if (!flt_solve2_collide_triset(triset, &idx, siz))
					return (siz);


				triset[idx].x++;
			}
			triset[idx].y++;
		}




		siz++;
		idx = 0;
	}
	return (0);
}
*/