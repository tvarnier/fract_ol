/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlcat.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 13:42:38 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/03 17:30:45 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int		i;
	int		y;
	int		length;

	i = 0;
	y = 0;
	while (dst[i])
		i++;
	while (src[y])
		y++;
	length = i > (int)size ? y + (int)size : i + y;
	y = -1;
	while (src[++y] && y + i < (int)size - 1)
		dst[i + y] = src[y];
	dst[i + y] = '\0';
	return (length);
}
