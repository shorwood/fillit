/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_bitset.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shorwood <shorwood@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/04 03:44:19 by shorwood     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/04 04:38:21 by shorwood    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_bitset(uint8_t *ptr, int i)
{
	if (i == 0)
		*ptr |= 0b00000001;
	else if (i == 1)
		*ptr |= 0b00000010;
	else if (i == 2)
		*ptr |= 0b00000100;
	else if (i == 3)
		*ptr |= 0b00001000;
	else if (i == 4)
		*ptr |= 0b00010000;
	else if (i == 5)
		*ptr |= 0b00100000;
	else if (i == 6)
		*ptr |= 0b01000000;
	else if (i == 7)
		*ptr |= 0b10000000;
}
