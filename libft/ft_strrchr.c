/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscott <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 11:56:42 by vscott            #+#    #+#             */
/*   Updated: 2019/05/23 14:27:33 by vscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	cc = (char)c;
	char		*rs;

	rs = NULL;
	while (*s)
	{
		if (*s == cc)
			rs = (char*)s;
		++s;
	}
	if (*s == cc)
		return ((char*)s);
	return (rs);
}
