/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscott <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 14:47:04 by vscott            #+#    #+#             */
/*   Updated: 2019/05/23 17:04:49 by vscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t n_len;

	if (!*needle)
		return ((char *)haystack);
	n_len = ft_strlen(needle);
	if (ft_strlen(haystack) < len)
		len = ft_strlen(haystack);
	while (*haystack && n_len <= len)
	{
		if (!ft_strncmp(haystack, needle, n_len))
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (NULL);
}
