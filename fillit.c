/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shorwood <shorwood@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/03 22:35:33 by shorwood     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/15 05:00:14 by shorwood    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"


/* 
** *****************************************************************************
*/

int			flt_tri_collide(t_flt_tri *tri, t_flt_grid grid, int siz)
{
	uint8_t		yt;
	uint8_t		ym;

	ym = tri->y;
	yt = 0;

	while (yt < 4 /*tri->siz*/ && ym <= siz)
	{
		if (grid[ym] & tri->grid[yt] >> tri->x)
			return (1);
		grid[ym++] |= tri->grid[yt++] >> tri->x;

	}
	return (0);
}

void		flt_map_wall(t_flt_grid grid, int siz)
{
	int	i;

	i = 0;
	grid[i] = ~0ULL >> siz;
	while (++i < siz)
		grid[i] = grid[i - 1];
	while (i < 64)
		grid[i++] = ~0ULL;
}

int			flt_triset_collide(t_flt_tri *tri, int *idx, int siz)
{
	int i;
	t_flt_grid grid;

	flt_map_wall(grid, siz);

	i = 0;
	while (tri->w)
	{
		if (flt_tri_collide(tri++, grid, siz))
			return (0);
		*idx = ++i;
	}
	return (1);
}
/*
void		flt_triset_reset(t_flt_tri *tri, t_flt_idx siz)
{
	int i;

	i = 0;
	while (tri->w)
	{
		tri->x = i % siz;
		tri->y = i / siz;
		tri++;
	}
}
*/

void		flt_triset_reset(t_flt_tri *tri, t_flt_idx siz)
{
	int i;

	i = 0;
	tri->x = 0;
	tri->y = 0;
	while ((++tri)->w)
	{
		i += (tri - 1)->o;
		tri->x = i % siz;
		tri->y = i / siz;
	}
}

int			flt_triset_store(t_flt_tri *tri)
{
	int	idx;
	int siz;

	idx = 0;
	siz = 2;
	while (siz < 64)
	{
		flt_triset_reset(tri, siz);
		while (tri[idx].y < siz)
		{
			tri[idx].x = 0;
			while (tri[idx].x < siz)
			{
				if (flt_triset_collide(tri, &idx, siz))
					return (siz);
				tri[idx].x++;
			}
			tri[idx].y++;
		}
		siz++;
	}
	return (0);
}

/*
** *****************************************************************************
*/

void 		flt_tri_push(t_flt_tri *tri, const char *str)
{
	if (flt_parse_prevalidate(str))
		flt_parse_convert(tri, str);
}


void		flt_output_triset(t_flt_tri *tri, int siz)
{
	t_flt_grid grid;

	int i = 0;
	while (i < siz)
		grid[i++] = 0;

	i = 0;
	while (tri[i].w)
		flt_tri_collide(&tri[i++], grid, siz);
	
	i = 0;
	while (i < siz)
	{
		ft_putnbits(&grid[i++], sizeof(*grid), siz);
		ft_putchar('\n');
	}
}

/*
** *****************************************************************************
*/

#define BUFFSIZE 200

int			main(int argc, char **argv)
{
	t_flt_tri	tri[BUFFSIZE + 10];

	argc = 0;
	argv = NULL;

	int i = 0;
	while (i < BUFFSIZE)
		//flt_tri_push(tri + i++, "###.\n#...\n....\n....\n\n");
		flt_tri_push(tri + i++, "....\n##..\n##..\n....\n\n");
		/*flt_tri_push(tri + i++, ".#..\n###.\n....\n....\n\n");
		flt_tri_push(tri + i++, "....\n###.\n.#..\n....\n\n");
		flt_tri_push(tri + i++, "####\n....\n....\n....\n\n");
		flt_tri_push(tri + i++, "....\n##..\n.##.\n....\n\n");
		flt_tri_push(tri + i++, "#...\n#...\n#...\n#...\n\n");
		flt_tri_push(tri + i++, "....\n#...\n###.\n....\n\n");*/

	int siz = flt_triset_store(tri);
	flt_print_triset_debug(tri, siz);
	ft_putnbr(siz);
	ft_putendl(siz ? " - SOLVED" : " - UNSOLVED");
}
