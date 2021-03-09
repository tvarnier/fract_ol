/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnew.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 19:12:52 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/05 14:12:08 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*tmp;
	size_t	i;

	tmp = NULL;
	if (!(tmp = (char*)(malloc(sizeof(*tmp) * (size + 1)))))
		return (NULL);
	i = 0;
	while (i <= size)
	{
		tmp[i] = '\0';
		i++;
	}
	return (tmp);
}
