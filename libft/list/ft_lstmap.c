/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstmap.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 17:34:28 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/05 23:15:07 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*begin;

	tmp = NULL;
	begin = NULL;
	while (lst)
	{
		if (!(begin))
		{
			tmp = f(lst);
			begin = tmp;
		}
		else
		{
			tmp->next = f(lst);
			tmp = tmp->next;
		}
		lst = lst->next;
	}
	return (begin);
}
