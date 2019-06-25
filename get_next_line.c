/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscott <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 13:46:10 by vscott            #+#    #+#             */
/*   Updated: 2019/06/25 16:55:17 by vscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"

static t_list	*ft_findfd(t_list **begin, int fd)
{
	t_list *tmp;

	tmp = *begin;
	if (tmp)
	{
		while (tmp)
		{
			if (fd == (int)tmp->content_size)
				return (tmp);
			tmp = tmp->next;
		}
	}
	tmp = ft_lstnew("\0", 1);
	tmp->content_size = fd;
	ft_lstadd(begin, tmp);
	return (tmp);
}

static char		*ft_freejoin_lst(char *tmp, char *buf)
{
	char	*fr;

	if (!buf)
		return (NULL);
	fr = tmp;
	tmp = ft_strjoin(tmp, buf);
	free(fr);
	return (tmp);
}

static char		*ft_makeline(char **line, char *tmp)
{
	size_t	nwln;
	char	*fr;

	nwln = 0;
	while (tmp[nwln] != '\0' && tmp[nwln] != '\n')
		nwln++;
	*line = ft_strsub(tmp, 0, (nwln));
	if (ft_strcmp(*line, tmp) == 0)
		ft_strdel(&tmp);
	else
	{
		fr = tmp;
		tmp = ft_strsub(tmp, nwln + 1, ft_strlen(tmp + nwln + 1));
		free(fr);
	}
	return (tmp);
}

int				get_next_line(const int fd, char **line)
{
	int				ret;
	char			buf[BUFF_SIZE + 1];
	static t_list	*lst;
	t_list			*begin;

	if (BUFF_SIZE < 1 || fd < 0 || !line || read(fd, buf, 0) < 0)
		return (-1);
	begin = lst;
	lst = ft_findfd(&begin, fd);
	while (!ft_strchr(lst->content, '\n') &&
			((ret = read(fd, buf, BUFF_SIZE)) > 0))
	{
		buf[ret] = '\0';
		lst->content = ft_freejoin_lst(lst->content, buf);
	}
	if (ret < BUFF_SIZE && !ft_strlen(lst->content))
	{
		lst = begin;
		return (0);
	}
	lst->content = ft_makeline(line, lst->content);
	lst = begin;
	return (1);
}
