/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstaddback.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/20 02:14:14 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/20 23:30:46 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstaddback(t_list **begin_list, void *data, size_t content_size)
{
	t_list	*lst;

	lst = *begin_list;
	if (*begin_list)
	{
		while (lst->next)
			lst = lst->next;
		if (!(lst->next = ft_lstnew(data, content_size)))
			return (0);
	}
	else if (!(*begin_list = ft_lstnew(data, content_size)))
		return (0);
	return (1);
}
