/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strins.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/21 04:16:54 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/21 05:03:00 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_strins(char *str, char *ins, int start)
{
	int		i;

	i = -1;
	while (ins[++i])
		str[start + i] = ins[i];
	return (start + i);
}
