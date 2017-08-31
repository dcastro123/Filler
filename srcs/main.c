/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <dcastro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 18:23:27 by dcastro-          #+#    #+#             */
/*   Updated: 2017/08/30 19:36:28 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int	main(void)
{
//	t_env e;
	char	*line;
	int		fd;
	int		res;
	int		num;

	res = 0;
	num = 0;
	line = NULL;
	fd = 1;
//	ft_bzero(&e, sizeof(t_env));
	int i = 0;
	printf("testsetsetsetsetset\n");
	while ((res = get_next_line(fd, &line)) > 0)
	{
		printf("iteration: %d\n", i);
		printf("[Ret: %d, # of Line: %d, FD: %d] %s\n", res, ++num, fd, line);
		ft_strdel(&line);
		i++;
	}
	ft_strdel(&line);
	printf("[Ret: %d, # of Line: %d, FD: %d] %s\n", res, ++num, fd, line);
	if ((fd > 0 && (close(fd) == -1 || res != 0)) || fd < 0)
	{
		if (!line)
			write(1, "error\n", 6);
		return (1);
	}
	printf ("/* Ret == 1 ; read line\n   Ret == 0 ; end of line(finish) */\n");
	return (0);
}
