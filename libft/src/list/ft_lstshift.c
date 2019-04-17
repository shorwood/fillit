/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstshift.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shorwood <shorwood@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/15 17:57:57 by shorwood     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/10 05:34:52 by shorwood    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_lstshift(t_list **lst)
{
	t_list	*lsti;
	void	*ptr;

	if (ft_lstnull(lst))
		return (NULL);
	lsti = ft_lstishift(lst);
	ptr = lsti->data;
	free(lsti);
	return (ptr);
}
