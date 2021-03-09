/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsub.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 20:16:36 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/17 03:29:50 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*tmp;

	if (s)
	{
		tmp = NULL;
		if (!(tmp = (char*)malloc(sizeof(*tmp) * (len + 1))))
			return (NULL);
		tmp = ft_strncpy(tmp, &(s[start]), len);
		tmp[len] = '\0';
		return (tmp);
	}
	return (NULL);
}
