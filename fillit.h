/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shorwood <shorwood@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/03 22:35:33 by shorwood     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/05 11:34:04 by shorwood    ###    #+. /#+    ###.fr     */
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
	uint8_t			w;
	uint8_t			h;
	uint8_t			x;
	uint8_t			y;
	uint8_t			o;
}					t_tri;

typedef struct		s_flt_parser
{
	uint8_t			sym;
	uint8_t			hsh;
	uint8_t			dot;
	uint8_t			lnk;
}					t_flt_parser;


t_tri		*flt_strtotri(const char *str);
int			flt_prevalidate(const char *str);

int			flt_solve_iterative(t_lst tris);
int			flt_solve_backtrack(t_lst tris);

void		flt_print_tri(t_tri *tri);
void		flt_print_grid(uint64_t grid[64], int siz);
void 		flt_print_symbol(t_lst tris, int siz);

#endif
