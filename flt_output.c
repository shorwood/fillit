/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   flt_output.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shorwood <shorwood@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/15 00:22:01 by shorwood     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/15 04:59:54 by shorwood    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

void		flt_print_tri(uint16_t *tri)
{
	int	i;

	i = 16;
	while (i--)
	{
		ft_putchar(((*tri >> i) & 1) ? '1' : '0');
		if (i % 4 == 0)
			ft_putchar('\n');
	}
}

void		flt_print_triset_debug(t_flt_tri *tri, int siz)
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
void		flt_put_triset_color(t_flt_tri *tri, int siz)
{
	char *str;

	str = (char*)malloc((siz + siz * siz * 35) * sizeof(char));

	t_flt_grid grid;


	int x;

	while (tri->w)
	{	
		y = 4;
		while (y < 3)
		{
			x = 4;
			while (x--)
			{
				if (tri->grid[0])
			}
		}
	}

	i = 0;
	while (tri[i].w)
		flt_tri_collide(&tri[i++], grid, siz);
	
	i = 0;
	while (i < siz)
	{
		ft_putnbits(&grid[i++], sizeof(*grid), siz);
		ft_putchar('\n');
	}
}*/


// \033[38;2;255;255;000m\033██
// \033[0m