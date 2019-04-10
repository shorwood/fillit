/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   flt_import.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shorwood <shorwood@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/15 00:19:25 by shorwood     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/10 08:06:50 by shorwood    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "libft.h"
#include "fillit.h"

/*
** *****************************************************************************
*/

static int		validate(const char *str)
{
	t_flt_parser n;

	n = (t_flt_parser){0, 0 ,0, 0};
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

/*
** *****************************************************************************
*/

static t_tri	*parse(const char *str)
{
	t_tri 		*tri;
	uint16_t	grid;

	if(!(tri = (t_tri*)malloc(sizeof(t_tri))))
		return (NULL);
	grid = 0;
	while (*str)
	{
		if (*str != '\n')
			grid <<= 1;
		if (*str == '#')
			grid++;
		str++;
	}
	while (!(grid & 0xf000))
		grid <<= 4;
	while (!(grid & 0x8888))
		grid <<= 1;
	tri->grid = (__uint128_t)ft_bit16clamp(grid, 16, 12) << 112
		| (__uint128_t)ft_bit16clamp(grid, 12, 8) << 105
		| (__uint128_t)ft_bit16clamp(grid, 8, 4) << 98
		| (__uint128_t)ft_bit16clamp(grid, 4, 0) << 91;
	tri->x = UINT8_MAX;
	tri->y = UINT8_MAX;
	return (tri);
}

/*
** *****************************************************************************
*/

t_lst		flt_import(const char *file)
{
	int		fd;
	t_lst	lst;
	char	str[22];
	size_t	len;

	str[21] = '\0';
	if (!(lst = ft_lstnew(0)))
		return (NULL);
	fd = open(file, O_RDONLY);
	while ((len = read(fd, str, 21)) > 0)
		if (!validate(str) || !ft_lstpush(lst, parse(str)))
			return (lst);
	return (lst);	
}