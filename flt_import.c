/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   flt_import.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shorwood <shorwood@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/15 00:19:25 by shorwood     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/17 16:30:11 by shorwood    ###    #+. /#+    ###.fr     */
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

static int		convert(t_lst lst)
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
*/

t_lst			flt_import(const char *file)
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
