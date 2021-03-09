/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memmove.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 16:19:17 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/04 19:07:12 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*tmp_dest;
	unsigned char	*tmp_src;

	tmp_dest = dest;
	tmp_src = (void*)src;
	if (tmp_dest == tmp_src)
		return (NULL);
	else if (tmp_dest < tmp_src)
		ft_memcpy(tmp_dest, tmp_src, n);
	else
	{
		tmp_dest += n - 1;
		tmp_src += n - 1;
		while (n--)
			*tmp_dest-- = *tmp_src--;
	}
	return (dest);
}
