/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   flt_parse.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shorwood <shorwood@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/15 00:19:25 by shorwood     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/15 04:46:43 by shorwood    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int		flt_parse_prevalidate(const char *str)
{
	t_flt_parse_helper n;

	n = (t_flt_parse_helper){0, 0 ,0, 0};
	while (*str)
	{
		if (*str == '#')
{	

			n.sym = n.dot + n.hsh;
			n.lnk += (n.sym > 3 && *(str - 5) == '#') +
					(n.sym > 0 && *(str - 1) == '#') +
					(n.sym < 14 && *(str + 1) == '#') +
					(n.sym < 12 && *(str + 5) == '#');
			n.hsh++;
		}
		else if (*str == '.')
			n.dot++;
		else if (*str != '\n')
			return (0);
		str++;
	}
	return (n.dot == 12 && n.hsh == 4 && (n.lnk == 8 || n.lnk == 6));
}

void	flt_parse_convert(t_flt_tri *tri, const char *str)
{
	t_flt_row buf;

	buf = 0ULL;
	while (*str)
	{
		if (*str != '\n')
			buf <<= 1;
		if (*str == '#')
			buf |= 1;
		str++;
	}

	if (!(buf & 0xfff0))
		buf <<= 12;
	else if (!(buf & 0xff00))
		buf <<= 8;
	else if (!(buf & 0xf000))
		buf <<= 4;
	if (!(buf & 0xeeee))
		buf <<= 3;
	else if (!(buf & 0xcccc))
		buf <<= 2;
	else if (!(buf & 0x8888))
		buf <<= 1;

	if (buf & 0x1111)
		tri->w = 4;
	else if (buf & 0x3333)
		tri->w = 3;
	else if (buf & 0x7777)
		tri->w = 2;
	else
		tri->w = 1;

	if (buf & 0x1000)
		tri->o = 4;
	else if (buf & 0x3000)
		tri->o = 3;
	else if (buf & 0x7000)
		tri->o = 2;
	else
		tri->o = 1;

	if (buf & 0x000f)
		tri->h = 4;
	else if (buf & 0x00ff)
		tri->h = 3;
	else if (buf & 0x0fff)
		tri->h = 2;
	else
		tri->h = 1;

	tri->grid[0] = (buf & 0xf000) << (60 - 12);
	tri->grid[1] = (buf & 0x0f00) << (60 - 8);
	tri->grid[2] = (buf & 0x00f0) << (60 - 4);
	tri->grid[3] = (buf & 0x000f) << (60);
}