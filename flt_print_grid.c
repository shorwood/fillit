/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   flt_print_grid.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shorwood <shorwood@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/15 00:22:01 by shorwood     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/10 08:13:59 by shorwood    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

void flt_print_grid(__uint128_t grid, unsigned int siz)
{
	unsigned int i;

	i = 0;
	while (i++ < siz)
	{
		ft_putnbits(&grid, sizeof(grid), siz);
		ft_putchar('\n');
		grid <<= 11;
	}
	ft_putchar('\n');
}
