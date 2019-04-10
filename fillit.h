/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shorwood <shorwood@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/03 22:35:33 by shorwood     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/10 08:13:12 by shorwood    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef _FILLIT_H
# define _FILLIT_H
# include "libft.h"

/*
** *****************************************************************************
*/

typedef struct		s_tri
{
	__uint128_t		grid;
	uint_fast8_t	x;
	uint_fast8_t	y;
	uint_fast8_t	h;
}					t_tri;

typedef struct		s_flt_parser
{
	uint_fast8_t	sym;
	uint_fast8_t	hsh;
	uint_fast8_t	dot;
	uint_fast8_t	lnk;
}					t_flt_parser;

/*
** Return a list of imported and parsed tetriminos from a text file.
*/
t_lst		flt_import(const char *file);

/*
** Store tetriminos in the most compact grid and return the grid size.
*/
int			flt_solve(t_lst tris);
int			flt_solve_permutation(t_lst tris);
int			flt_solve_position(t_lst tris);

/*
** Output a grid of letters from a list of placed tetriminos.
*/
void 		flt_print(t_lst tris, int siz);
void		flt_print_color(t_lst tris, int siz);
void		flt_print_grid(__uint128_t grid, unsigned int siz);

#endif
