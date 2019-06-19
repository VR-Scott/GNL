/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscott <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 08:12:56 by vscott            #+#    #+#             */
/*   Updated: 2019/05/28 11:46:32 by vscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*a;
	int		l;
	int		n_tmp;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	l = ((n <= 0) ? 1 : 0);
	n_tmp = n;
	while (++l && n_tmp)
		n_tmp /= 10;
	if (!(a = (char*)malloc(sizeof(char) * l)))
		return (NULL);
	a[--l] = '\0';
	n_tmp = n * ((n < 0) ? -1 : 1);
	while (l >= 0)
	{
		a[--l] = '0' + (n_tmp % 10);
		n_tmp /= 10;
	}
	if (n < 0)
		*a = '-';
	return (a);
}
