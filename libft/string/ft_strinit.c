/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strinit.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/21 03:28:31 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/21 04:12:35 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strinit(char c, size_t len)
{
	char		*tmp;
	size_t		i;

	if (!(tmp = ft_strnew(len)))
		return (NULL);
	i = 0;
	while (i < len)
	{
		tmp[i] = c;
		i++;
	}
	return (tmp);
}
