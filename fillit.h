/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shorwood <shorwood@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/03 22:35:33 by shorwood     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/30 03:06:22 by shorwood    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef _FILLIT_H
# define _FILLIT_H
# include "libft/include/libft.h"

typedef struct		s_flt_tri
{
	uint_fast16_t	grid[4];
	int				x;
	int				y;
}					t_flt_tri;

typedef struct		s_flt_parser
{
	int				nln;
	int				hsh;
	int				dot;
	int				lnk;
}					t_flt_parser;

/*
** Return a list of imported and parsed tetriminos from a text file.
*/
t_lst				flt_import(const char *file);

/*
** Store tetriminos in the most compact grid and return the grid size.
*/
int					flt_solve(t_lst tris);

/*
** Output a grid of letters from a list of placed tetriminos.
*/
int					flt_print(t_lst tris, int siz);

#endif
