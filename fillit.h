/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shorwood <shorwood@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/03 22:35:33 by shorwood     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/15 10:00:33 by shorwood    ###    #+. /#+    ###.fr     */
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

typedef uint64_t	t_flt_row;
typedef uint8_t		t_flt_idx;

typedef t_flt_row	t_flt_tri_grid[4];

typedef struct		s_flt_tri
{
	t_flt_tri_grid	grid;
	t_flt_idx		w;
	t_flt_idx		h;
	t_flt_idx		x;
	t_flt_idx		y;
	t_flt_idx		o;
}					t_flt_tri;

typedef t_flt_row	t_flt_grid[64];

typedef struct		s_flt_parse_helper
{
	uint8_t			sym;
	uint8_t			hsh;
	uint8_t			dot;
	uint8_t			lnk;
}					t_flt_parse_helper;

int			flt_parse_prevalidate(const char *str);
void		flt_parse_convert(t_flt_tri *tri, const char *str);

void		flt_print_tri(uint16_t *tri);
void		flt_print_triset_debug(t_flt_tri *tri, int siz);
void		flt_print_triset_color(t_flt_tri *tri, int siz);
void		flt_print_triset_letters(t_flt_tri *tri, int siz);

int			flt_tri_collide(t_flt_tri *tri, t_flt_grid grid, int siz);

#endif
