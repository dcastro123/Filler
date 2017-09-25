/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <dcastro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 18:23:27 by dcastro-          #+#    #+#             */
/*   Updated: 2017/09/25 00:59:14 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int	ft_error(char *s)
{
	ft_putstr(s);
	return (0);
}

static int	create_map(t_env *e, char *line)
{
	t_board *board;
	int		i;

	board = &env->board;

	if (!(env->board->map = (char**)malloc(sizeof(char*) * (env->map_x + 1))))
		ft_error("malloc error\n");
	i = -1;
	env->board->map[env->map_y] = NULL;
	while (++i < env->map_y)
	{
		if (!(env->board->map[i] = (char*)malloc(sizeof(char) * (env->map_x + 1))))
			ft_error("malloc error\n");
	}
}

static	int		get_map_and_piece(t_env *e)
{
	get_next_line(0, &line);
	if (ft_strstr(line, "Plateau"))
	{
		fprintf(stderr, "Line being fed: %s\n", &line[i]);
		env->map_y = ft_atoi(line + 8);
		env->map_x = ft_atoi(line + 10);
		fprintf(stderr, "map_y is: %d\n", env->map_y);
		fprintf(stderr, "map_x is: %d\n", env->map_x);
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
}

int	check_player(t_env *env, char *line)
{
	char	*line;
	int		i;

	i = 0;
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
	ft_strdel(&line);
	return (1);
}

int	main(void)
{
	t_env	*env;
	t_p 	*p;
	char	*line;

	line = NULL;
	p = &env->p;
	if (!(env = (t_env*)malloc(sizeof(t_env))))
		ft_error("Struct malloc failed!\n");
	check_player(env);
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
