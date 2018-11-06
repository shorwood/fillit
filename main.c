/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shorwood <shorwood@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/03 22:35:33 by shorwood     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/06 08:59:10 by shorwood    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

/*
** typedef uint16_t t_tetriminos;
*/

uint16_t	flt_strtotri(const char *str)
{
	uint16_t	tri;
	const char	*buf;

	if (!str || ft_strlen(str) > 16)
		return (0);
	buf = str;
	tri = 0;
	while (*buf)
	{
		tri <<= 1;
		if (*buf++ == '#')
			tri++;
	}
	return (tri);
}

uint16_t	flt_tri_align(uint16_t tri)
{
	if (tri & 0xeeee)

}

uint16_t	flt_tri_offset_y(uint16_t tri, int off)
{
	if (off == 0)
		return (tri);
	if (off > 0)
		return (tri >> off * 4);
	return (tri);
}

uint16_t	flt_tri_offset_x(uint16_t tri, int off)
{
	if (off == 0)
		return (tri);
	if (off > 0)
		return (tri >> off);
	return (tri << -off);
}

int		main(int argc, char **argv)
{

	uint16_t 		*fld;
	uint16_t 		*tri;
	unsigned int 	cnt;

	fld = NULL;
	tri = NULL;
	cnt = 0;
	argc = 0;
	argv = NULL;


	uint16_t var = flt_strtotri(".##..##.........");
	ft_putbits(&var, sizeof(var));
	ft_putendl("");
	var = flt_tri_offset_y(var, 3);
	ft_putbits(&var, sizeof(var));
}
