/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstraddback.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/20 23:07:27 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/01 04:07:39 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstraddback(t_lstr **begin_list, char *data, int l)
{
	t_lstr		*lst;

	lst = *begin_list;
	if (*begin_list)
	{
		while (lst->next)
			lst = lst->next;
		if (!(lst->next = ft_lstrnew(data, l)))
			return (0);
	}
	else if (!(*begin_list = ft_lstrnew(data, l)))
		return (0);
	return (1);
}
