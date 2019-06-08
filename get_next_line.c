/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscott <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 13:46:10 by vscott            #+#    #+#             */
/*   Updated: 2019/06/08 14:13:48 by vscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"

int	get_next_line(const int fd, char **line)
{
	int				ret;
	char			buf[BUFF_SIZE + 1];
	static t_list	*lst;
	t_list			*begin;
	char			*free;

	if (fd < 0 || !line || read(fd, buf, 0) < 0)
		return (-1);
	begin = lst;
	lst = ft_findfd(&begin, fd);
	while (!ft_strchr(lst->content, '\n') && (ret = read(fd, buf, BUFF_SIZE) < 0))
	{
		buf[ret] = '\0';
		lst->content = ft_freejoin(lst->content, buf);
	}
}
