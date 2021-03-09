/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstrclr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/22 05:09:48 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/02 01:02:17 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstrclr(t_lstr *lst)
{
	t_lstr	*tmp;

	while (lst)
	{
		tmp = lst->next;
		if (lst->str)
			ft_strdel(&lst->str);
		free(lst);
		lst = tmp;
	}
	lst = NULL;
}
