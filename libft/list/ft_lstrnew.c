/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstrnew.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/20 22:58:01 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/01 04:12:20 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_lstr		*ft_lstrnew(char *str, int l)
{
	t_lstr		*tmp;
	int			i;

	tmp = NULL;
	if (!(tmp = (t_lstr*)malloc(sizeof(*tmp))))
		return (NULL);
	tmp->str = NULL;
	if (!(tmp->str = ft_strnew(l)))
		return (NULL);
	i = -1;
	while (++i < l)
		(tmp->str)[i] = str[i];
	tmp->l = l;
	tmp->next = NULL;
	return (tmp);
}
