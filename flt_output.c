/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   flt_output.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shorwood <shorwood@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/15 00:22:01 by shorwood     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/28 05:29:57 by shorwood    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

#include <stdio.h>
/*
void		flt_print_triset_color(t_flt_tri *tri, int siz)
{
	char 		*str;
	size_t		len;
	int 		x;
	int 		y;
	int			i;

	len = siz * siz * 23;
	str = ft_strnew(len);
	//str = (char*)malloc(len * sizeof(char));

	char tmp[] = "\x1b[38;2;000;000;128m▪ ";
	//char tmp2[] = "\x1b[38;2;000;255;000m█";

	i = 0;
	while(i < siz * siz)
		ft_memcpy(str + i++ * 23, tmp, 23);

	i = 1;
	while(i < siz)
		str[i++ * 23 * siz - 1] = '\n';

	str[len - 1] = '\0';

	char		buf[27];
	int c = 255;
	while (tri->w)
	{
		y = 0;
		while (y < 4)
		{
			x = 0;
			while (x < 4)
			{
				if (tri->grid[y] >> (63 - x) & 1)
				{
					sprintf(buf, "\033[38;2;%03d;%03d;%03dm█", c % 255, (c + 85) % 255, (c - 85) % 255);
					ft_memcpy(str +
						(x + tri->x) * (0b1 * 23) +
						(y + tri->y) * (siz * 23), buf, 22); 
					
					//str[(x + tri->x) + (y + tri->y) * (siz + 1)] = sym;
				}
				x++;
			}
			y++;
		}
		c += 101;
		tri++;
	}

	ft_putstr(str);
	ft_putendl("\033[0m");
	free(str);
}


void		flt_print_triset_letters(t_flt_tri *tri, int siz)
{
	char 		*str;
	size_t		len;
	int 		x;
	int 		y;
	int			i;
	char		sym;

	len = siz * siz + siz - 1;
	str = ft_strnew(len);
	ft_memset(str, '.', len);

	i = siz;
	while(i < siz * siz)
	{
		str[i] = '\n';
		i += siz + 1;
	}

	str[len] = '\0';

	sym = 'A';
	while (tri->w)
	{
		y = 0;
		while (y < 4)
		{
			x = 0;
			while (x < 4)
			{
				if (tri->grid[y] >> (63 - x) & 1)
				{
					str[(x + tri->x) + (y + tri->y) * (siz + 1)] = sym;
				}
				x++;
			}
			y++;
		}
		sym++;
		tri++;
	}

	ft_putstr(str);
	ft_putendl("\033[0m");
	free(str);
}
*/