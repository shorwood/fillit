/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   flt_print.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shorwood <shorwood@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/15 00:22:01 by shorwood     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/10 08:12:33 by shorwood    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

void	flt_print(t_lst tris, int siz)
{
	char 		*str;
	size_t		len;
	int 		x;
	int 		y;
	int			i;
	char		sym;
	t_tri		*tri;
	t_lsti		lsti;

	if (!tris)
		return ;
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
	lsti = *tris;
	while (lsti)
	{
		tri = lsti->data;
		y = 0;
		while (y < 4)
		{
			x = 0;
			while (x < 4)
			{
				if ((tri->grid >> (127 - x - y * 11) & 1))
				{
					if ((x + tri->x) < siz)
						str[(x + tri->x) + (y + tri->y) * (siz + 1)] = sym;
				}
				x++;
			}
			y++;
		}
		sym++;
		lsti = lsti->next;
	}
	ft_putendl(str);
	free(str);
}
