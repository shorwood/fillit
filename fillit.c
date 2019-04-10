/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shorwood <shorwood@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/03 22:35:33 by shorwood     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/10 02:58:38 by shorwood    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include "../LibFt/src/list/ft_lstclr.c"

/*
** *****************************************************************************
*/

int main(int argc, char **argv)
{
	t_lst tris;

	/* FOR DEBUG PURPOSES. PLEASE DO NOT FORGET TO DELETE */
	argc = 2;
	argv = 0;

	if (argc != 2 || !(tris = flt_import("sample/01.txt")))//argv[1])))
	{
		ft_putendl("error");
		return (0);
	};
	flt_print(tris, flt_solve(tris));
	ft_lstclr(tris, FT_LCLR_ALL);
	return (0);
}
