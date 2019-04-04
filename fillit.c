/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shorwood <shorwood@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/03 22:35:33 by shorwood     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/04 05:36:05 by shorwood    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

void		flt_print_triset_letters(t_lst tris, int siz)
{
	char 		*str;
	size_t		len;
	int 		x;
	int 		y;
	int			i;
	char		sym;
	t_tri		*tri;
	t_lsti		lsti;

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

	sym = '1';
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
				if (tri->grid[y] >> (63 - x) & 1)
				{
					str[(x + tri->x) + (y + tri->y) * (siz + 1)] = sym;
				}
				x++;
			}
			y++;
		}
		sym++;
		lsti = lsti->next;
	}

	ft_putstr(str);
	ft_putendl("\033[0m");
	free(str);
}

/*
** *****************************************************************************
*/
#define TRI_SQR 	"##..\n##..\n....\n....\n\n"
#define TRI_LINE	"####\n....\n....\n....\n\n"
#define TRI_I 		"#...\n#...\n#...\n#...\n\n"
#define TRI_L 		"#...\n#...\n##..\n....\n\n"
#define TRI_N	 	".#..\n##..\n#...\n....\n\n"
#define TRI_S	 	".##.\n##..\n....\n....\n\n"

#define BUFFSIZE 1

int	flt_place(uint64_t grid[64], t_tri *tri, int x, int y)
{
	int	i;

	i = -1;
	while (++i < tri->h)
		if (grid[y + i] & tri->grid[i] >> x)
			return (0);
	i = -1;
	while (++i < tri->h)
		grid[y + i] |= tri->grid[i] >> x;
	return (1);
}

/* ************************************************************************** */

int	flt_store2(uint64_t grid[64], t_tri *tri, int siz)
{
	int	x;
	int	y;
 
	y = 0;
	while (y < siz)
	{
		x = 0;
		while (x < siz)
		{
			if (flt_place(grid, tri, x, y))
			{
				tri->x = x;
				tri->y = y;
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

/* ************************************************************************** */

int	flt_store(t_lst tris, int siz)
{
	t_lsti		lsti;
	uint64_t	grid[64];

	flt_grid_init(grid, siz);
	lsti = *tris;

	while (lsti)
	{
		if (!flt_store2(grid, lsti->data, siz))
			return (0);
		lsti = lsti->next;
	}

	return (1);
}

/* ************************************************************************** */

#include <math.h>

int	flt_nani(t_lst tris)
{
	t_lsti	lsti;
	t_lst	prm;
	int		siz;

	//--- Get the minimum size of the Grid.
	//siz = sqrtl(ft_lstlen(tris) * 4);
	siz = 4;

	while (siz < 16)
	{

		//--- Generate all permutations.
		//---prm = ft_lstprm(tris);
		prm = ft_lstnew(1, tris);
		lsti = *prm;

		while (lsti)
		{
			if(flt_store(lsti->data, siz))
			{
				flt_print_triset_letters(tris, siz);
				return (1);
			}
			lsti = lsti->next;
		}
		siz++;
	}

	return (0);
}


/* ************************************************************************** */

int main(int argc, char **argv)
{
	argc = 0;
	argv = 0;

	t_lst tris = ft_lstnew(9,
		flt_strtotri(TRI_N),
		flt_strtotri(TRI_S),
		flt_strtotri(TRI_L),
		flt_strtotri(TRI_N),
		flt_strtotri(TRI_S),
		flt_strtotri(TRI_L),
		flt_strtotri(TRI_N),
		flt_strtotri(TRI_S),
		flt_strtotri(TRI_L));

	flt_nani(tris);

}
