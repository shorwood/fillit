/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   flt_print_color.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shorwood <shorwood@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/15 00:22:01 by shorwood     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/10 08:26:43 by shorwood    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>
#include <time.h>

void	flt_print_color(t_lst tris, int siz)
{
	char 		*str;
	size_t		len;
	int 		x;
	int 		y;
	int			i;
	t_lsti		lsti;
	t_tri		*tri;

	len = siz * siz * 23;
	str = ft_strnew(len);
	//str = (char*)malloc(len * sizeof(char));

	char tmp[] = "\x1b[38;2;000;000;000m▪ ";
	//char tmp2[] = "\x1b[38;2;000;255;000m█";

	i = 0;
	while(i < siz * siz)
		ft_memcpy(str + i++ * 23, tmp, 23);

	i = 1;
	while(i < siz)
		str[i++ * 23 * siz - 1] = '\n';

	str[len - 1] = '\0';

	char		buf[27];
	int 		c[3];
	lsti = *tris;
	while (lsti)
	{
		c[0] = (rand() % 8) * 32;
		c[1] = (rand() % 8) * 32;
		c[2] = (rand() % 8) * 32;

		tri = lsti->data;
		y = 0;
		while (y < 4)
		{
			x = 0;
			while (x < 4)
			{
				if ((tri->grid >> (127 - x - y * 11) & 1))
				{
					sprintf(buf, "\033[38;2;%03d;%03d;%03dm█", c[0], c[1], c[2]);
					ft_memcpy(str +
						(x + tri->x) * (0b1 * 23) +
						(y + tri->y) * (siz * 23), buf, 22); 
					
					//str[(x + tri->x) + (y + tri->y) * (siz + 1)] = sym;
				}
				x++;
			}
			y++;
		}
		lsti = lsti->next;
	}

	ft_putstr(str);
	ft_putendl("\033[0m");
	free(str);
}