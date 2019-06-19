/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscott <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 14:25:09 by vscott            #+#    #+#             */
/*   Updated: 2019/05/28 13:40:15 by vscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strcnt(char const *s, char c)
{
	unsigned int sc;

	sc = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
			sc++;
		while (*s && *s != c)
			s++;
	}
	return (sc);
}

char		**ft_strsplit(char const *s, char c)
{
	int			i;
	int			b;
	int			ai;
	char		**sa;

	i = 0;
	ai = 0;
	if (!s || !(sa = (char **)malloc(sizeof(char *) * (ft_strcnt(s, c) + 1))))
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		b = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > b)
		{
			sa[ai] = ft_strsub(s, b, i - b);
			ai++;
		}
	}
	sa[ai] = NULL;
	return (sa);
}
