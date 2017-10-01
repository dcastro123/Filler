/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <dcastro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 16:42:41 by dcastro-          #+#    #+#             */
/*   Updated: 2017/09/30 20:59:19 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// int		send_help(char **buf_keep, char **line)
// {
// 	char	*temp;
// 	size_t	len;

// 	if (ft_strlen(*buf_keep))
// 	{
// 		len = ft_wdlen(*buf_keep, '\n');
// 		if (ft_strchr(*buf_keep, '\n'))
// 		{
// 			*line = ft_strsub(*buf_keep, 0, len);
// 			temp = ft_strdup(*buf_keep + len + 1);
// 			free(*buf_keep);
// 			*buf_keep = temp;
// 			return (1);
// 		}
// 		*line = ft_strdup(*buf_keep);
// 		free(*buf_keep);
// 		*buf_keep = NULL;
// 		return (1);
// 	}
// 	return (0);
// }

// int		get_next_line(const int fd, char **line)
// {
// 	static	char	*buf_keep;
// 	char			buff[BUFF_SIZE + 1];
// 	int				byte_count;
// 	char			*tmp;

// 	if (fd < 0 || !line || read(fd, buff, 0) < 0)
// 		return (-1);
// 	while ((byte_count = read(fd, buff, BUFF_SIZE)) > 0)
// 	{
// 		buff[byte_count] = '\0';
// 		if (!buf_keep)
// 			buf_keep = ft_strnew(0);
// 		tmp = ft_strjoin(buf_keep, buff);
// 		free(buf_keep);
// 		buf_keep = tmp;
// 		if (ft_strchr(buff, '\n'))
// 			break ;
// 	}
// 	if (buf_keep == NULL)
// 		return (0);
// 	if (send_help(&buf_keep, line))
// 		return (1);
// 	if (byte_count == 0)
// 		return (0);
// 	return (0);
// }


// int		ft_new_line(char **s, char **line, int fd, int ret)
// {
// 	char	*tmp;
// 	int		len;

// 	len = 0;
// 		write(2, "hello4\n", 7);
// 	while (s[fd][len] != '\n' && s[fd][len] != '\0')
// 		len++;
// 	if (s[fd][len] == '\n')
// 	{
// 		*line = ft_strsub(s[fd], 0, len);
// 		tmp = ft_strdup(s[fd] + len + 1);
// 		free(s[fd]);
// 		s[fd] = tmp;
// 	}
// 	else if (s[fd][len] == '\0')
// 	{
// 		if (ret == BUFF_SIZE)
// 			return (get_next_line(fd, line));
// 		*line = ft_strdup(s[fd]);
// 		free(s[fd]);
// 		s[fd] = NULL;
// 	}
// 	return (1);
// }
// #include <stdio.h>
// int		get_next_line(const int fd, char **line)
// {
// 	static char	*s[255];
// 	char		buf[BUFF_SIZE + 1];
// 	char		*tmp;
// 	int			ret;

// 	write(2, "hello1\n", 7);
// 	if (fd < 0 || line == NULL)
// 		return (-1);
// 	write(2, "hello1-1\n", 9);
// 	fprintf(stderr, "%d %s\n", fd, buf);
// 	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
// 	{
// 		write(2, "ret: ", 5);
// 		ft_putnbr_fd(ret, 2);
// 		write(2, " hello2\n", 7);
// 		buf[ret] = '\0';
// 		if (s[fd] == NULL)
// 			s[fd] = ft_strnew(1);
// 		tmp = ft_strjoin(s[fd], buf);
// 		free(s[fd]);
// 		s[fd] = tmp;
// 		if (ft_strchr(buf, '\n'))
// 			break ;
// 	}
// 	write(2, "hello3\n", 7);
// 	if (ret < 0)
// 		return (-1);
// 	else if (ret == 0 && (s[fd] == NULL || s[fd][0] == '\0'))
// 		return (0);
// 	return (ft_new_line(s, line, fd, ret));
// }







static void	*ft_realloc(void *src, size_t srcsize, size_t newsize)
{
	void *ret;

	if (!src)
		return (NULL);
	ret = ft_memalloc(newsize);
	ft_memcpy(ret, src, MIN(srcsize, newsize));
	free(src);
	return (ret);
}

static t_list		*create_node(int fd)
{
	t_list		*ret;
	t_file_buff *cont;

	cont = (t_file_buff *)ft_memalloc(sizeof(t_file_buff));
	cont->fd = fd;
	cont->str = ft_strnew(BUFF_SIZE);
	cont->start = cont->str;
	ret = ft_lstnew(cont, sizeof(t_file_buff));
	return (ret);
}

static t_file_buff	*get_extra(int fd, t_list **extra_list)
{
	t_list *temp;

	if (!extra_list || !*extra_list)
		*extra_list = create_node(fd);
	temp = *extra_list;
	while (temp)
	{
		if (((t_file_buff *)temp->content)->fd == fd)
			return ((t_file_buff *)temp->content);
		temp = temp->next;
	}
	ft_lstadd(extra_list, create_node(fd));
	return ((t_file_buff *)(*extra_list)->content);
}

static void			handle_extra(t_file_buff *extra, char **ret, char **end)
{
	long	dist;
	char	*loc;

	loc = ft_strchr(extra->str, '\n');
	if (loc)
	{
		dist = (long)(loc - extra->str);
		*end = (char *)1;
		extra->str[dist] = 0;
		*ret = ft_strdup(extra->str);
		extra->str += dist + 1;
	}
	else
	{
		*ret = ft_strdup(extra->str);
		ft_strclr(extra->start);
		extra->str = extra->start;
	}
}

static char			*handle_data(int count, char **ret, \
		char *buff, t_file_buff *extra)
{
	long	dist;
	char	*loc;
	int		len;

	len = ft_strlen(*ret);
	loc = ft_strchr(buff, '\n');
	if (!loc)
	{
		*ret = (char *)ft_realloc((void *)*ret, len, len + count + 1);
		ft_strncat(*ret, buff, count);
		ft_strclr(buff);
	}
	else
	{
		dist = (long)(loc - buff);
		*ret = (char *)ft_realloc((void *)*ret, len, len + dist + 1);
		ft_strncat(*ret, buff, dist);
		ft_strncpy(extra->start, buff + dist + 1, BUFF_SIZE - dist - 1);
	}
	return (ft_strchr(buff, '\n'));
}

int					get_next_line(const int fd, char **line)
{
	static t_list	*extra_list;
	char			*ret;
	int				count;
	char			*tmps[2];
	t_file_buff		*extra;

	if (!line)
		return (-1);
	extra = get_extra(fd, &extra_list);
	tmps[1] = 0;
	handle_extra(extra, &ret, &tmps[1]);
	if (!tmps[1])
		tmps[0] = ft_strnew(BUFF_SIZE);
	else
		return ((*line = ret) ? 1 : 0);
	while (!tmps[1] && (count = read(fd, tmps[0], BUFF_SIZE)) > 0)
		tmps[1] = handle_data(count, &ret, tmps[0], extra);
	if (tmps[1] > tmps[0])
		ft_strcpy(extra->start, tmps[1] + 1);
	*line = ret;
	ft_strdel(&tmps[0]);
	if (tmps[1] || ret[0] || count)
		return ((count >= 0 ? 1 : -1));
	return (0);
}

// static char		*ft_until_next(char *str)
// {
// 	int		i;
// 	int		j;
// 	char	*res;

// 	i = 0;
// 	j = 0;
// 	while ((str[i] != '\n') && (str[i] != '\0'))
// 		i++;
// 	if (str[i] == '\0')
// 		return (str);
// 	else
// 	{
// 		res = ft_strnew(i + 1);
// 		while (j < i)
// 		{
// 			res[j] = str[j];
// 			j++;
// 		}
// 		res[j] = '\0';
// 		return (res);
// 	}
// }

// static int		ft_read_into(const int fd, char **s1)
// {
// 	int		ret;
// 	char	buf[BUFF_SIZE + 1];
// 	char	*tmp;

// 	if ((ret = read(fd, buf, BUFF_SIZE)) <= 0)
// 		return (ret);
// 	buf[ret] = '\0';
// 	tmp = ft_strdup(*s1);
// 	*s1 = ft_strnew((ft_strlen(tmp) + ft_strlen(buf)));
// 	ft_strcat(*s1, tmp);
// 	ft_strcat(*s1, buf);
// 	ft_strdel(&tmp);
// 	ft_strclr(buf);
// 	return (ret);
// }

// int				get_next_line(const int fd, char **line)
// {
// 	int				ret;
// 	static char		*s1;
// 	int				i;

// 	i = 0;
// 	if (!s1)
// 		s1 = ft_strnew(1);
// 	while (ft_strchr(s1, '\n') == 0)
// 	{
// 		if ((ret = ft_read_into(fd, &s1)) <= 0)
// 			break ;
// 		i++;
// 	}
// 	if ((ret < 0) || (!line))
// 		return (-1);
// 	*line = ft_until_next(s1);
// 	s1 = ft_strchr(s1, '\n');
// 	if (s1)
// 	{
// 		s1++;
// 		i++;
// 	}
// 	if (((ret == 0) && (i == 0)) && (ft_strlen(*line) <= 0))
// 		return (0);
// 	return (1);
// }
