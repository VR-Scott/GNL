/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscott <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 14:05:22 by vscott            #+#    #+#             */
/*   Updated: 2019/05/28 11:49:14 by vscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *sp;
	unsigned char uc;

	sp = (unsigned char*)s;
	uc = (unsigned char)c;
	while (n--)
	{
		if (*sp == uc)
			return (sp);
		sp++;
	}
	return (NULL);
}
