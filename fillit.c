/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shorwood <shorwood@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/03 22:35:33 by shorwood     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/05 15:04:40 by shorwood    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

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

/* ************************************************************************** */

int main(int argc, char **argv)
{
	argc = 0;
	argv = 0;
	int siz;

	t_lst tris = ft_lstnew(60,
		flt_strtotri(TRI_L),
		flt_strtotri(TRI_N),
		flt_strtotri(TRI_S),
		flt_strtotri(TRI_N),
		flt_strtotri(TRI_L),
		flt_strtotri(TRI_N),
		flt_strtotri(TRI_L),
		flt_strtotri(TRI_S),
		flt_strtotri(TRI_L),
		flt_strtotri(TRI_I),
		flt_strtotri(TRI_L),
		flt_strtotri(TRI_I),
		flt_strtotri(TRI_L),
		flt_strtotri(TRI_I),
		flt_strtotri(TRI_L),
		flt_strtotri(TRI_I),
		flt_strtotri(TRI_L),
		flt_strtotri(TRI_I),
		flt_strtotri(TRI_L),
		flt_strtotri(TRI_I),
		flt_strtotri(TRI_L),
		flt_strtotri(TRI_N),
		flt_strtotri(TRI_S),
		flt_strtotri(TRI_N),
		flt_strtotri(TRI_L),
		flt_strtotri(TRI_N),
		flt_strtotri(TRI_L),
		flt_strtotri(TRI_S),
		flt_strtotri(TRI_L),
		flt_strtotri(TRI_I),
		flt_strtotri(TRI_L),
		flt_strtotri(TRI_I),
		flt_strtotri(TRI_L),
		flt_strtotri(TRI_I),
		flt_strtotri(TRI_L),
		flt_strtotri(TRI_I),
		flt_strtotri(TRI_L),
		flt_strtotri(TRI_I),
		flt_strtotri(TRI_L),
		flt_strtotri(TRI_I),
		flt_strtotri(TRI_S),
		flt_strtotri(TRI_N),
		flt_strtotri(TRI_L),
		flt_strtotri(TRI_N),
		flt_strtotri(TRI_L),
		flt_strtotri(TRI_S),
		flt_strtotri(TRI_L),
		flt_strtotri(TRI_I),
		flt_strtotri(TRI_L),
		flt_strtotri(TRI_I),
		flt_strtotri(TRI_L),
		flt_strtotri(TRI_I),
		flt_strtotri(TRI_L),
		flt_strtotri(TRI_I),
		flt_strtotri(TRI_L),
		flt_strtotri(TRI_I),
		flt_strtotri(TRI_L),
		flt_strtotri(TRI_I),
		flt_strtotri(TRI_L),
		flt_strtotri(TRI_N),
		flt_strtotri(TRI_S),
		flt_strtotri(TRI_N),
		flt_strtotri(TRI_L),
		flt_strtotri(TRI_N),
		flt_strtotri(TRI_L),
		flt_strtotri(TRI_S),
		flt_strtotri(TRI_L),
		flt_strtotri(TRI_I),
		flt_strtotri(TRI_L),
		flt_strtotri(TRI_I),
		flt_strtotri(TRI_L),
		flt_strtotri(TRI_I),
		flt_strtotri(TRI_L),
		flt_strtotri(TRI_I),
		flt_strtotri(TRI_L),
		flt_strtotri(TRI_I),
		flt_strtotri(TRI_L),
		flt_strtotri(TRI_I),
		flt_strtotri(TRI_L));

	/*siz = flt_solve_iterative(tris);
	flt_print_symbol(tris, siz);*/

	ft_putendl("\n-----");
	siz = flt_solve_backtrack(tris);
	flt_print_symbol(tris, siz);

}
