/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_round.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/08 17:04:05 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/09 19:11:48 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

long double		ft_round(long double rounded_number, int decimal)
{
	long double		nbr;

	nbr = 0.5f;
	while (--decimal >= 0)
		nbr = nbr * 0.1f;
	rounded_number += (rounded_number >= 0) ? nbr : nbr * -1.0f;
	return (rounded_number);
}
