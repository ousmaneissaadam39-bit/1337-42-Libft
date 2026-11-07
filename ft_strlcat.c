/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isousman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 11:49:54 by isousman          #+#    #+#             */
/*   Updated: 2026/10/17 11:50:46 by isousman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	lentgh_src;
	size_t	lentgh_dst;

	i = 0;
	lentgh_src = ft_strlen(src);
	if (dst == NULL && dstsize == 0)
		return (lentgh_src);
	lentgh_dst = ft_strlen(dst);
	if (lentgh_dst >= dstsize)
		return (dstsize + lentgh_src);
	while ((lentgh_dst + i + 1) < dstsize && src[i] != '\0')
	{
		dst[lentgh_dst + i] = src[i];
		i++;
	}
	dst[lentgh_dst + i] = '\0';
	return (lentgh_dst + lentgh_src);
}
