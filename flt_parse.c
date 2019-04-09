/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   flt_parse.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shorwood <shorwood@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/15 00:19:25 by shorwood     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/09 23:09:26 by shorwood    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <fcntl.h>
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
	uint16_t	buf;

	if(!(tri = (t_tri*)malloc(sizeof(t_tri))))
		return (NULL);
	buf = 0;
	while (*str)
	{
		if (*str != '\n')
			buf <<= 1;
		if (*str == '#')
			buf |= 1;
		str++;
	}
	while (!(buf & 0xf000))
		buf <<= 4;
	while (!(buf & 0x8888))
		buf <<= 1;
	if (buf & 0x000f)
		tri->h = 4;
	else if (buf & 0x00ff)
		tri->h = 3;
	else if (buf & 0x0fff)
		tri->h = 2;
	else
		tri->h = 1;
	tri->grid[0] = (uint64_t)(buf & 0xf000) << 48;
	tri->grid[1] = (uint64_t)(buf & 0x0f00) << 52;
	tri->grid[2] = (uint64_t)(buf & 0x00f0) << 56;
	tri->grid[3] = (uint64_t)(buf & 0x000f) << 60; 
	return (tri);
}

/*
** *****************************************************************************
*/

t_lst		flt_import(const char *file)
{
	int		fd;
	t_lst	lst;
	char	buf[22];
	size_t	len;

	buf[21] = '\0';
	if (!(lst = ft_lstnew(0)))
		return (NULL);
	fd = open(file, O_RDONLY);
	while ((len = read(fd, buf, 21)) > 0)
		if (!validate(buf) || !ft_lstpush(lst, parse(buf)))
		{
			ft_lstclr(lst, FT_LCLR_ALL);
			return (NULL);
		}
	return (lst);	
}