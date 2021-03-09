/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strncat.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 12:19:06 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/03 12:44:44 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	int		i;
	size_t	y;

	i = 0;
	y = 0;
	while (dest[i])
		i++;
	while (src[y] && y < n)
	{
		dest[i + y] = src[y];
		y++;
	}
	dest[i + y] = '\0';
	return (dest);
}
