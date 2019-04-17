/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_powillu.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shorwood <shorwood@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/09 21:23:47 by shorwood     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/05 10:51:06 by shorwood    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

long long	ft_powill(long long x, unsigned int n)
{
	long long y;

	y = 1LL;
	while (n--)
		y *= x;
	return (y);
}
