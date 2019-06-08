/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscott <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 13:46:10 by vscott            #+#    #+#             */
/*   Updated: 2019/06/08 16:05:32 by vscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"

static char	ft_findfd(t_list **begin, int fd)
{
	t_list *tmp;

	tmp = *begin;
	if(tmp)
	{
		while (tmp)
		{
			if (fd == (int)tmp->content_size)
				return (tmp);
			tmp = tmp->next;
		}
		tmp = ft_lstnew("\0", 1);
		tmp->content_size = fd;
		ft_lstadd(begin, tmp);
		return (tmp);
	}
}

static char *ft_freejoin_lst(char *tmp, char *buf)
{
	size_t	len;
	char	*fr;
	
	if (!tmp || !buf)
		return (NULL);
	free = tmp;
	tmp = ft_strjoin(tmp, buf, ret);
	free(fr);
	return (tmp);
}

int			get_next_line(const int fd, char **line)
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
