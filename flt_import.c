/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   flt_import.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shorwood <shorwood@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/15 00:19:25 by shorwood     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/30 03:06:50 by shorwood    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "fillit.h"

/*
** *****************************************************************************
** This function will take a single tetrimino's string at a time and make sure
** it is valid. It will count the number of square, the number of new lines and
** the number of voids. We use the structure 't_flt_parse' to get around the
** maximum lines limitation of the 42 norm. Return 0 if the tetrimino is invalid
** *****************************************************************************
*/

static int			validate(const char *str)
{
	int				i;
	t_flt_parser	n;

	i = 0;
	if (str[4] != '\n' || str[9] != '\n' || str[14] != '\n' || str[19] != '\n')
		return (0);
	n = (t_flt_parser){0, 0, 0, 0};
	while (str[i])
	{
		if (str[i] == '#')
		{
			n.lnk += (i > 4 && str[i - 5] == '#') + (i > 0 && str[i - 1] == '#')
					+ (str[i + 1] == '#') + (i < 15 && str[i + 5] == '#');
			n.hsh++;
		}
		else if (str[i] == '.')
			n.dot++;
		else if (str[i] == '\n')
			n.nln++;
		else
			return (0);
		i++;
	}
	return (n.dot == 12 && (n.nln == 5 || n.nln == 4)
		&& n.hsh == 4 && (n.lnk == 8 || n.lnk == 6));
}

/*
** *****************************************************************************
** This function will take a string and output a tetrimino as a bitfield.
** Output tetrimino will be align at the top-most, left-most position.
** *****************************************************************************
*/

static t_flt_tri	*parse(const char *str)
{
	t_flt_tri		*tri;
	uint16_t	grid;

	if (!(tri = (t_flt_tri*)malloc(sizeof(t_flt_tri))))
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
** Take a list of string and transform them in a list of tetriminos. If any
** tetrinino is invalid, the function returns 0 and the program will output
** 'error\n'
** *****************************************************************************
*/

static int			convert(t_lst lst)
{
	t_lsti	lsti;
	char	*buf;

	if (ft_lstnull(lst))
		return (0);
	lsti = *lst;
	while (lsti)
	{
		if ((buf = lsti->data)
			&& !!lsti->next != (ft_strlen(buf) == 20)
			&& validate(buf)
			&& (lsti->data = parse(buf)))
		{
			free(buf);
			lsti = lsti->next;
		}
		else
			return (0);
	}
	return (1);
}

/*
** *****************************************************************************
** This function will take a file path as the input string. This file will be
** Opened and all tetriminos will be imported as a structure in a list.
** If all goes well, the list will of tetriminos will be returned; If not,
** everything is freed and the 'NULL' is returned.
** *****************************************************************************
*/

t_lst				flt_import(const char *file)
{
	int		fd;
	char	*buf;
	t_lst	lst;
	size_t	len;

	if (!(lst = ft_lstnew(0))
		|| !(buf = ft_strnew(21))
		|| (fd = open(file, O_RDONLY)) < 0)
		return (NULL);
	while ((len = read(fd, buf, 21)) > 0)
		ft_lstpush(lst, ft_strndup(buf, len));
	close(fd);
	if (!convert(lst))
		ft_lstclr(lst, FT_LCLR_ALL);
	else
		return (lst);
	return (NULL);
}
