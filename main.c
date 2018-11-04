/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shorwood <shorwood@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/03 22:35:33 by shorwood     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/03 23:38:06 by shorwood    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

/*
** typedef uint16_t t_tetriminos;
*/

uint16_t	flt_strtotetrimino(const char *str)
{
	uint16_t	tertrimino;
	const char	*buf;

	if (!str)
		return (0);
	buf = str;
	while (*buf)
		buf++;
	if (buf - str != 16)
		return (0);
	tertrimino = 0;
	while (*--buf)
	{
		if (*buf == '#')
			tertrimino++;
		tertrimino <<= 1;
		printf("%d\n",tertrimino);
	}
	return (tertrimino);
}

int		main(int argc, char **argv)
{
	argc = 0;
	argv = NULL;
	printf("%hu", flt_strtotetrimino("####............"));
}