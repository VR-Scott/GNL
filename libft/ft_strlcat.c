/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscott <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 13:51:45 by vscott            #+#    #+#             */
/*   Updated: 2019/05/30 10:42:16 by vscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t d;
	size_t s;

	d = 0;
	s = 0;
	while (dst[d] && d < dstsize)
		d++;
	while ((src[s] && (d + s + 1) < dstsize))
	{
		dst[d + s] = src[s];
		s++;
	}
	if (d != dstsize)
		dst[d + s] = '\0';
	return (d + ft_strlen(src));
}
