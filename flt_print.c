/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   flt_print.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shorwood <shorwood@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/15 00:22:01 by shorwood     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/18 19:25:08 by shorwood    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

/*
** *****************************************************************************
*/

static char	*init(int siz)
{
	char	*str;
	size_t	len;
	int		i;

	len = siz * siz + siz - 1;
	if (!(str = ft_strnew(len)))
		return (NULL);
	ft_memset(str, '.', len);
	i = siz;
	while (i < siz * siz)
	{
		str[i] = '\n';
		i += siz + 1;
	}
	return (str);
}

/*
** *****************************************************************************
*/

static void	layer(char *str, t_tri *tri, int siz, char c)
{
	int x;
	int y;

	y = -1;
	while (++y < 4)
	{
		x = -1;
		while (++x < 4)
			if (tri->grid[y] >> (15 - x) & 1)
				str[(x + tri->x) + (y + tri->y) * (siz + 1)] = c;
	}
}

/*
** *****************************************************************************
*/

int			flt_print(t_lst tris, int siz)
{
	t_lsti	tri;
	char	*str;
	char	c;

	if (ft_lstnull(tris) || !(str = init(siz)))
		return (0);
	c = 'A';
	tri = *tris;
	while (tri)
	{
		layer(str, tri->data, siz, c++);
		tri = tri->next;
	}
	ft_putendl(str);
	free(str);
	return (1);
}
