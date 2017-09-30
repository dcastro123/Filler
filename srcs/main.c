/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <dcastro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 18:23:27 by dcastro-          #+#    #+#             */
/*   Updated: 2017/09/29 18:41:31 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static	void		get_mapsize(t_env *env)
{
	char *line;

	line = NULL;
	get_next_line(0, &line);
	if (ft_strstr(line, "Plateau"))
	{
		env->map_y = ft_atoi(line + 8);
		env->map_x = ft_atoi(line + 10);
	}
	ft_strdel(&line);
	if (!(env->board.map = (char**)malloc(sizeof(char*) * (env->map_y))))
		ft_error("malloc error\n");
	ft_bzero(env->board.map, sizeof(env->map_y));
}

static	void	check_player(t_env *env)
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
}

static	void	init_env(t_env *env)
{
	t_board *board;
	t_p 	*p;
	t_enemy	*e;
	t_player *pl;

	env = (t_env*)ft_memalloc(sizeof(t_env));
	p = &env->p;
	board = &env->board;
	e = &env->enemy;
	pl = &env->player;
	env->p1 = 0;
	env->p2 = 0;
	env->p.y_size = 0;
	env->p.x_size = 0;
	env->count = 0;
	env->i = 0;
	env->enemy.x = 0;
	env->enemy.y = 0;
	env->player.x = 0;
	env->player.y = 0;
}

int	main(void)
{
	t_env	env;
	char	*line;
	int 	ret;

	init_env(&env);
	check_player(&env);
	get_mapsize(&env);
	env.start = 0;
	// fprintf(stderr, "map size: y: %d x: %d\n", env.map_y, env.map_x);
	while ((get_next_line(0, &line)) > 0)
	{
		// ft_putstr("12 13\n");
		// fprintf(stderr, "line being passed: %s\n", line);
		if ((ret = parse(&env, line)) == 1)
			check_piece(&env);
		ft_strdel(&line);
	}
	return (0);
}
