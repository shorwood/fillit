/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   flt_print_grid.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shorwood <shorwood@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/28 05:25:18 by shorwood     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/28 06:19:19 by shorwood    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

void	flt_print_grid(uint64_t grid[64], int siz)
{
	int i;

	i = 0;
	while (i < siz)
	{
		ft_putnbits(&grid[i++], sizeof(uint64_t), siz);
		ft_putchar('\n');
	}
	ft_putchar('\n');
}