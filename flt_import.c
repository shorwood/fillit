/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   flt_import.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shorwood <shorwood@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/15 00:19:25 by shorwood     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/15 11:11:05 by shorwood    ###    #+. /#+    ###.fr     */
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

	n = (t_flt_parser){0, 0, 0, 0};
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
	t_tri		*tri;
	uint16_t	grid;

	if (!(tri = (t_tri*)malloc(sizeof(t_tri))))
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
	tri->grid[0] = ft_bit16clamp(grid, 16, 12);
	tri->grid[1] = ft_bit16clamp(grid, 12, 8) << 4;
	tri->grid[2] = ft_bit16clamp(grid, 8, 4) << 8;
	tri->grid[3] = ft_bit16clamp(grid, 4, 0) << 12;
	return (tri);
}

/*
** *****************************************************************************
*/

t_lst			flt_import(const char *file)
{
	int		fd;
	char	str[22];
	t_lst	lst;
	t_tri	*tri;

	if (!(lst = ft_lstnew(0)))
		return (NULL);
	ft_memset(str, '\0', 22 * sizeof(char));
	fd = open(file, O_RDONLY);
	while (read(fd, str, 21) != 0)
		if (!validate(str)
			|| !(tri = parse(str))
			|| !ft_lstpush(lst, tri))
		{
			ft_lstclr(lst, FT_LCLR_ALL);
			return (NULL);
		}
	return (lst);
}
