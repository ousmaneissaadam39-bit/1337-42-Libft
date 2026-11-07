/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isousman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 14:26:05 by isousman          #+#    #+#             */
/*   Updated: 2026/11/07 12:10:54 by isousman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**free_split(char **array, int i)
{
	while (i > 0)
	{
		i--;
		free(array[i]);
	}
	free(array);
	return (0);
}

static int	count_words(char const *str, char delim)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == delim)
			i++;
		else
		{
			count++;
			while (str[i] && str[i] != delim)
				i++;
		}
	}
	return (count);
}

static char	*copy_word(char *dest, char const *s, int i, int len)
{
	int	j;

	j = 0;
	while (len > 0)
	{
		dest[j] = s[i - len];
		j++;
		len--;
	}
	dest[j] = '\0';
	return (dest);
}

static char	**fill_words(char const *s, char c, char **tab, int n)
{
	int	i;
	int	word;
	int	len;

	i = 0;
	word = 0;
	len = 0;
	while (word < n)
	{
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			i++;
			len++;
		}
		tab[word] = (char *)malloc(sizeof(char) * (len + 1));
		if (!tab[word])
			return (free_split(tab, word));
		copy_word(tab[word], s, i, len);
		len = 0;
		word++;
	}
	tab[word] = 0;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char			**array;
	unsigned int	num_words;

	if (!s)
		return (0);
	num_words = count_words(s, c);
	array = (char **)malloc(sizeof(char *) * (num_words + 1));
	if (!array)
		return (0);
	array = fill_words(s, c, array, num_words);
	return (array);
}
/*#include <stdio.h>
int	main(void)
{
	char	**array;
	char const	s[] = "Bulbasaur is the best";
	char	c = '/';
	int		i;

	array = ft_split(s, c);
	if (!array)
	{
		printf("L'allocation du tableau a échoué.\n");
		return (1);
	}

	printf("Nombre de mots détectés : %d\n\n", count_words(s, c));

	i = 0;
	while (array[i])
	{
		printf("Mot [%d] : %s\n", i, array[i]);
		free(array[i]); // On libère chaque mot après l'avoir affiché
		i++;
	}
	free(array); // On libère le tableau principal à la fin
	return (0);
}
*/
