/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtrim.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 20:29:48 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/05 17:56:34 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static size_t		length_str(char const *s)
{
	size_t	len;
	size_t	nbr_space;
	size_t	i;

	len = ft_strlen(s);
	i = 0;
	nbr_space = 0;
	while (s[i] && (s[i] == '\n' || s[i] == '\t' || s[i] == ' '))
	{
		nbr_space++;
		i++;
	}
	if (s[i] != '\0')
	{
		i = 0;
		while (i < len && (s[len - i - 1] == '\n' || s[len - i - 1] == '\t'
					|| s[len - i - 1] == ' '))
		{
			nbr_space++;
			i++;
		}
	}
	return (len - nbr_space);
}

char				*ft_strtrim(char const *s)
{
	size_t	len;
	char	*tmp;
	int		i;
	int		y;

	if (s)
	{
		len = length_str(s);
		tmp = NULL;
		if (!(tmp = (char*)malloc(sizeof(*tmp) * (len + 1))))
			return (NULL);
		i = 0;
		while (s[i] && (s[i] == '\n' || s[i] == '\t' || s[i] == ' '))
			i++;
		y = 0;
		while (len-- > 0)
			tmp[y++] = s[i++];
		tmp[y] = '\0';
		return (tmp);
	}
	return (NULL);
}
