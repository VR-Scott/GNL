/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscott <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 08:09:56 by vscott            #+#    #+#             */
/*   Updated: 2019/06/20 15:40:48 by vscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	const char cc = (char)c;

	if (!s)
		return (NULL);
	while (*s && *s != cc)
		++s;
	if (*s == cc)
		return ((char *)s);
	return (NULL);
}
