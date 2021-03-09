/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsplit.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 21:22:34 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/05 17:57:09 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int		alloc_words(char const *s, char **tab, char c, int nbr_words)
{
	int		i;
	int		length;
	int		verif;
	int		count_words;

	verif = 0;
	count_words = 0;
	i = -1;
	length = 0;
	while (s[++i] && count_words < nbr_words)
	{
		if (s[i] != c && (verif = 1))
			length++;
		if ((s[i] == c || s[i + 1] == '\0') && verif == 1)
		{
			verif = 0;
			tab[count_words] = NULL;
			if (!(tab[count_words++] = (char*)malloc(sizeof(*tab)
							* (length + 1))))
				return (0);
			length = 0;
		}
	}
	return (1);
}

static int		ft_count_words(char const *s, char c)
{
	int		i;
	int		nbr_words;
	int		verif;

	verif = 1;
	nbr_words = 0;
	i = -1;
	while (s[++i])
	{
		if (s[i] != c && verif == 1)
		{
			nbr_words++;
			verif = 0;
		}
		else if (s[i] == c && verif == 0)
			verif = 1;
	}
	return (nbr_words);
}

static void		ft_insert_words(char const *s, char c, char **tab)
{
	int		i;
	int		count_words;
	int		y;
	int		verif;

	i = -1;
	count_words = 0;
	verif = 0;
	y = 0;
	while (s[++i])
	{
		if (s[i] != c && (verif = 1))
			tab[count_words][y++] = s[i];
		if ((s[i] == c || s[i + 1] == '\0') && verif == 1)
		{
			verif = 0;
			tab[count_words][y] = '\0';
			count_words++;
			y = 0;
		}
	}
}

char			**ft_strsplit(char const *s, char c)
{
	int		nbr_words;
	char	**tab;

	if (s)
	{
		nbr_words = ft_count_words(s, c);
		tab = NULL;
		if (!(tab = (char**)malloc(sizeof(*tab) * (nbr_words + 1))))
			return (NULL);
		tab[nbr_words] = 0;
		if ((alloc_words(s, tab, c, nbr_words)) == 0)
			return (NULL);
		ft_insert_words(s, c, tab);
		return (tab);
	}
	return (NULL);
}
