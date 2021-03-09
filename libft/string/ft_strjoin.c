/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strjoin.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 20:22:11 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/05 17:56:04 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*tmp;
	int		i;
	int		y;

	if (s1 && s2)
	{
		len1 = ft_strlen(s1);
		len2 = ft_strlen(s2);
		tmp = NULL;
		if (!(tmp = (char*)malloc(sizeof(*tmp) * (len1 + len2 + 1))))
			return (NULL);
		i = -1;
		while (s1[++i])
			tmp[i] = s1[i];
		y = -1;
		while (s2[++y])
			tmp[i + y] = s2[y];
		tmp[i + y] = '\0';
		return (tmp);
	}
	return (NULL);
}
