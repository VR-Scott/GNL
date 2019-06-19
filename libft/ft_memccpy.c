/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscott <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 13:41:30 by vscott            #+#    #+#             */
/*   Updated: 2019/05/28 11:48:54 by vscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char *cd;
	char *cs;

	cd = (char*)dst;
	cs = (char*)src;
	while (n--)
	{
		*(cd++) = *(cs);
		if (*(cs++) == (char)c)
			return (cd);
	}
	return (NULL);
}
