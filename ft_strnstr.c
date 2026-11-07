/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isousman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 20:18:46 by isousman          #+#    #+#             */
/*   Updated: 2026/10/16 20:19:28 by isousman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *need, size_t len)
{
	size_t	i;
	size_t	j;

	if (!*need)
		return ((char *)s1);
	i = 0;
	while (i < len && s1[i])
	{
		j = 0;
		while (i + j < len && s1[i + j] == need[j] && need[j])
			j++;
		if (need[j] == '\0')
			return ((char *)&s1[i]);
		i++;
	}
	return (NULL);
}
