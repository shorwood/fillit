/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shorwood <shorwood@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/03 22:35:33 by shorwood     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/10 08:21:46 by shorwood    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

/*
** *****************************************************************************
*/

int		main(int argc, char **argv)
{
	t_lst	tris;
	int		(*user_solve)(t_lst);
	void	(*user_print)(t_lst, int);

	tris = NULL;
	user_solve = flt_solve;
	user_print = flt_print;
	while (argc > 2)
	{
		argc--;
		if (!ft_strcmp(argv[argc], "--permutation"))
			user_solve = flt_solve_permutation;
		else if (!ft_strcmp(argv[argc], "--position"))
			user_solve = flt_solve_position;
		else if (!ft_strcmp(argv[argc], "--color"))
			user_print = flt_print_color;
		else
			argc = 0;
	}
	if (argc != 2 || !(tris = flt_import(argv[1])))
		ft_putendl("error");
	else
		user_print(tris, user_solve(tris));
	ft_lstclr(tris, FT_LCLR_ALL);
	return (EXIT_SUCCESS);
}
