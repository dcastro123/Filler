/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <dcastro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 18:23:27 by dcastro-          #+#    #+#             */
/*   Updated: 2017/09/23 02:58:22 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int	ft_error(char *s)
{
	ft_putstr(s);
	return (0);
}

int	check_file(t_env *env)
{
	char	*line;
	t_board	*board;
	int		i;

	i = 0;
	board = &env->board;
	get_next_line(0, &line);
	if (ft_strchr(line, '1'))
	{
		env->p2 = 'X';
		env->p1 = 'O';
	}
	else if (ft_strchr(line, '2'))
	{
		env->p1 = 'X';
		env->p2 = 'O';
	}
	else
	{
		ft_strdel(&line);
		return (0);
	}
	ft_strdel(&line);
	get_next_line(0, &line);
	if (ft_strstr(line, "Plateau"))
	{
		fprintf(stderr, "Line being fed: %s\n", &line[i]);
		env->map_h = ft_atoi(line + 8);
		env->map_w = ft_atoi(line + 10);
		fprintf(stderr, "map_y is: %d\n", env->map_h);
		fprintf(stderr, "map_x is: %d\n", env->map_w);
		ft_strdel(&line);
	}
	else if (ft_strstr(line, "Piece"))
	{
		env->p.height = ft_atoi(line + 5);
		env->p.width = ft_atoi(line + 7);
		fprintf(stderr, "piece height is: %d\n", env->p.height);
		fprintf(stderr, "piece width is : %d\n", env->p.width);
		ft_strdel(&line);
	}
	else
		ft_strdel(&line);
	get_next_line(0, &line);
	fprintf(stderr, "Line being fed: %s\n", line);
	ft_strdel(&line);
	int i = 0;
	int j = 0;
	while (get_next_line(0, &line) > 0)
	{
		//go until space before '.'
		//malloc here for each line in map array env->board.map[i][j]
	}
	return (1);
}

int	main(void)
{
	t_env	*env;
	t_p 	*p;
	char	*line;

	line = NULL;
	if (!(env = (t_env*)malloc(sizeof(t_env))))
		ft_error("Struct malloc failed!\n");
	p = &env->p;
	if (!(check_file(env)))
		ft_error("Read error!\n");
	// while (get_next_line(0))
	// while (get_next_line(0, &line) > 0)
	// {
	// 	ft_putstr_fd(">>", 2);
	// 	ft_putendl_fd(line, 2);
	// 	ft_putstr("\n");
	// 	ft_strdel(&line);
	// }
	// ft_strdel(&line);
	ft_putendl_fd("done reading\n", 2);
	return (0);
}
