/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   flt_print_tri.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shorwood <shorwood@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/28 05:25:18 by shorwood     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/28 05:37:53 by shorwood    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

void	flt_print_tri(t_tri *tri)
{
	int i;

	i = 0;
	while (i < 4)
	{
		ft_putnbits(&tri->grid[i++], sizeof(*tri->grid), 4);
		ft_putchar('\n');
	}
	ft_putchar('\n');
}