/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memalloc.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 18:58:21 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/03 19:09:23 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*tmp;
	size_t	i;

	tmp = NULL;
	if (!(tmp = (char*)malloc(sizeof(*tmp) * size)))
		return (NULL);
	i = 0;
	while (i < size)
	{
		tmp[i] = 0;
		i++;
	}
	return ((void*)tmp);
}
