/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscott <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 13:46:10 by vscott            #+#    #+#             */
/*   Updated: 2019/06/13 10:25:57 by vscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"
#include <stdio.h>	//DELETE THIS!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

static t_list	*ft_findfd(t_list **begin, int fd)
{
	t_list *tmp;

	tmp = *begin;
	if (tmp)
	{
		while (tmp)
		{
			printf("tmp->content_size is :%zu\n", tmp->content_size);//DELETE THIS!!!
			if (fd == (int)tmp->content_size)
				return (tmp);
			tmp = tmp->next;
		}
	}
		tmp = ft_lstnew("\0", 1);
		tmp->content_size = fd;
		printf("tmp->content_size is :%zu\n", tmp->content_size);//DELETE THIS!!!!!!!!
		ft_lstadd(begin, tmp);
		return (tmp);
}

static char	*ft_freejoin_lst(char *tmp, char *buf)
{
	char	*fr;

	if (/*!tmp || */!buf)
		return (NULL);
	fr = tmp;
	tmp = ft_strjoin(tmp, buf);
	free(fr);
	return (tmp);
}

static char	*ft_makeline(char **line, char *tmp)
{
	size_t	nwln;
	char	*fr;

	nwln = 0;
	while (tmp[nwln] != '\0' && tmp[nwln] != '\n')
		nwln++;
	*line = ft_strsub(tmp, 0, (nwln));
	if (ft_strcmp(*line, tmp) == 0)
		tmp = NULL;
	else
	{
		fr = tmp;
		tmp = ft_strsub(tmp, nwln + 1, ft_strlen(tmp + nwln + 1));
		free(fr);
	}
	return (tmp);
}

int		get_next_line(const int fd, char **line)
{
	int				ret;
	char			buf[BUFF_SIZE + 1];
	static t_list	*lst; 
	t_list			*begin;

	if (fd < 0 || !line || read(fd, buf, 0) < 0)
		return (-1);
	begin = lst;
	lst = ft_findfd(&begin, fd);
	while (!ft_strchr(lst->content, '\n') && ((ret = read(fd, buf, BUFF_SIZE)) > 0))
	{
//		printf(" ret is %i\n", ret);//DELETE THIS!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		buf[ret] = '\0';
		lst->content = ft_freejoin_lst(lst->content, buf);
	}

//	printf("%s is lst->cntent\n",lst->content);// DELETE THIS !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//	printf("%s is buf.\n", buf);// DELETE THIS !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//	printf("%i is ret.\n", ret);// DELETE THIS !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	if (ret < BUFF_SIZE && !ft_strlen(lst->content))
	{
		lst = begin;
		return (0);
	}
	lst->content = ft_makeline(line, lst->content);
	lst = begin;
	return (1);
}
