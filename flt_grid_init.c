/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   flt_grid_init.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shorwood <shorwood@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/28 06:07:00 by shorwood     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/03 20:29:49 by shorwood    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

void	flt_grid_init(uint64_t grid[64], int siz)
{
	int			i;
	uint64_t	val;

	i = 0;
	val = (uint64_t)~0 >> siz;
	while (i < siz)
		grid[i++] = val;
	while (i < 64)
		grid[i++] = ~0;
}
