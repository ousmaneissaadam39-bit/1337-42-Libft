/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isousman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 00:36:34 by isousman          #+#    #+#             */
/*   Updated: 2026/10/17 00:37:33 by isousman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*a1;
	const unsigned char	*a2;
	size_t				i;

	i = 0;
	a1 = (const unsigned char *)s1;
	a2 = (const unsigned char *)s2;
	if (n == 0)
		return (0);
	while (i < n && a1[i] == a2[i])
		i++;
	if (i == n)
		return (0);
	return (a1[i] - a2[i]);
}
