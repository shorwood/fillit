/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shorwood <shorwood@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/03 22:35:33 by shorwood     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/29 18:16:00 by shorwood    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	t_lst	tris;
	int		siz;

	tris = NULL;
	if (argc != 2
		|| !(tris = flt_import(argv[1]))
		|| !(siz = flt_solve(tris))
		|| !flt_print(tris, siz))
		ft_putendl("error");
	ft_lstclr(tris, FT_LCLR_ALL);
	return (EXIT_SUCCESS);
}
