/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscott <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 13:50:15 by vscott            #+#    #+#             */
/*   Updated: 2019/05/23 14:53:12 by vscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t n_len;
	size_t hs_len;

	if (!*needle)
		return ((char *)haystack);
	n_len = ft_strlen(needle);
	hs_len = ft_strlen(haystack);
	while (*haystack && n_len <= hs_len)
	{
		if (!ft_strncmp(haystack, needle, n_len))
			return ((char *)haystack);
		haystack++;
		hs_len--;
	}
	return (NULL);
}
