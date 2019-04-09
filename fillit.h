/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shorwood <shorwood@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/03 22:35:33 by shorwood     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/09 21:59:09 by shorwood    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef _FILLIT_H
# define _FILLIT_H
# include "libft.h"
# include <stdlib.h>

/*
** *****************************************************************************
*/

typedef struct		s_tri
{
	uint64_t		grid[4];
	uint8_t			x;
	uint8_t			y;
	uint8_t			h;
}					t_tri;

typedef struct		s_flt_parser
{
	uint8_t			sym;
	uint8_t			hsh;
	uint8_t			dot;
	uint8_t			lnk;
}					t_flt_parser;

/*
** Return a list of imported and parsed tetriminos from a text file.
*/
t_lst		flt_import(const char *file);

/*
** Store tetriminos in the most compact grid and return the grid size.
*/
int			flt_solve(t_lst tris);
int			flt_solve_iterative(t_lst tris);

/*
** Output a grid with placed tetriminos.
*/
void 		flt_print(t_lst tris, int siz);

#endif
