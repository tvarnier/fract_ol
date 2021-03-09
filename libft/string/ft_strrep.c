/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_realloc.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/20 03:31:55 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/25 20:53:38 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrep(char *src, char *newb)
{
	char	*tmp;

	if (src)
	{
		tmp = src;
		src = newb;
		ft_strdel(&tmp);
	}
	else
		src = newb;
	return (src);
}
