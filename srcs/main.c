/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <dcastro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 18:23:27 by dcastro-          #+#    #+#             */
/*   Updated: 2017/09/30 22:26:46 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static	void	get_info(t_env *env)
{
	char	*line;
	int		i;

	i = 0;
	get_next_line(0, &line);
	if (ft_strchr(line, '1'))
	{
		env->p1 = 'O';
		env->p2 = 'X';
	}
	else if (ft_strchr(line, '2'))
	{
		env->p1 = 'X';
		env->p2 = 'O';
	}
	ft_strdel(&line);
	get_next_line(0, &line);
	if (ft_strstr(line, "Plateau"))
	{
		env->map_y = ft_atoi(line + 8);
		env->map_x = ft_atoi(line + 10);
	}
	ft_strdel(&line);
	if (!(env->board.map = (char**)malloc(sizeof(char*) * (env->map_y + 1))))
		ft_error("malloc error\n");
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
	env->overlap = 0;
	env->board.xplace = 0;
	env->board.yplace = 0;
}

int	main(void)
{
	t_env	env;
	char	*line;
	int 	ret;

	init_env(&env);
	get_info(&env);
	env.start = 0;
	while ((get_next_line(0, &line)) > 0)
	{
		// // ft_putstr("12 13\n");
		// write(2, "line being passed: ", 19);
		// write(2, line, 17);
		// write(2, "\n", 1);
		// write(2, "before parse\n", 10);
		if ((ret = parse(&env, line)) == 1)
			check_piece(&env);
		// write(2, "before delete\n", 12);
		ft_strdel(&line);
		// write(2, "after delete\n", 12);
	}
	return (0);
}
