/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_iscntrl.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shorwood <shorwood@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/10 05:58:53 by shorwood     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/09 09:11:07 by shorwood    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

int		ft_iscntrl(int c)
{
	return ((c >= 0x00 && c <= 0x1F) || c == 0x7F);
}
