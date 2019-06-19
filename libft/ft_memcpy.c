/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscott <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 11:59:29 by vscott            #+#    #+#             */
/*   Updated: 2019/06/05 07:40:55 by vscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned long *ld;
	unsigned long *ls;
	unsigned char *cd;
	unsigned char *cs;

	if (!dst && !src)
		return (NULL);
	ld = (unsigned long*)dst;
	ls = (unsigned long*)src;
	while (n >= sizeof(unsigned long))
	{
		*(ld++) = *(ls++);
		n -= sizeof(unsigned long);
	}
	cd = (unsigned char*)ld;
	cs = (unsigned char*)ls;
	while (n--)
		*(cd++) = *(cs++);
	return (dst);
}
