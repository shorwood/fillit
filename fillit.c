/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shorwood <shorwood@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/03 22:35:33 by shorwood     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/09 22:32:27 by shorwood    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

/*
** *****************************************************************************
*/

int main(int argc, char **argv)
{
	t_lst lst;

	/* FOR DEBUG PURPOSES. PLEASE DO NOT FORGET TO DELETE */
	argc = 2;
	argv = 0;
	if (argc != 2 || !(lst = flt_import("sample/03.txt")))//argv[1])))
	{
		ft_putendl("error");
		return (0);
	};
	flt_print(lst, flt_solve(lst));
	ft_lstclr(lst, FT_LCLR_ALL);
	return (0);
}
