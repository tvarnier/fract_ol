/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memccpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 15:59:33 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/05 22:55:33 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	int		i;

	i = 0;
	while (n--)
	{
		(((unsigned char *)dest)[i]) = (((unsigned char *)src)[i]);
		if ((((unsigned char *)dest)[i]) == (unsigned char)c)
			return (&dest[i + 1]);
		i++;
	}
	return (NULL);
}
