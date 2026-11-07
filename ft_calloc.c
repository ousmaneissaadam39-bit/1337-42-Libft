/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isousman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 15:50:53 by isousman          #+#    #+#             */
/*   Updated: 2026/10/17 15:51:14 by isousman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*a;
	size_t	total;

	if (nmemb == 0 || size == 0)
	{
		return (malloc(0));
	}
	if (size != 0 && nmemb > 9223372036854775807L / size)
		return (NULL);
	total = nmemb * size;
	if (total / size != nmemb)
		return (NULL);
	a = malloc(total);
	if (!a)
		return (NULL);
	ft_bzero(a, total);
	return (a);
}
