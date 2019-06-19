/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscott <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 13:00:05 by vscott            #+#    #+#             */
/*   Updated: 2019/05/28 13:47:20 by vscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t l;
	size_t b;
	size_t e;

	if (!s)
		return (NULL);
	l = ft_strlen(s);
	b = 0;
	while (s[b] && (s[b] == ' ' || s[b] == '\n' || s[b] == '\t'))
		b++;
	if (b == l)
		return (ft_strnew(0));
	e = 0;
	while ((s[l - e - 1] == ' ' || s[l - e - 1] == '\n' || s[l - e - 1] == '\t')
			&& l - e - 1 > 0)
		++e;
	return (ft_strsub(s, b, l - e - b));
}
