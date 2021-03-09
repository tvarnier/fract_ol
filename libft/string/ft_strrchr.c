/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strrchr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 17:59:36 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/04 19:20:50 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	if (s[i] == '\0' && s[i] == c)
		return ((char *)&(s[i]));
	while (i >= 0)
	{
		if (s[i] == c)
			return ((char *)&(s[i]));
		i--;
	}
	return (NULL);
}
