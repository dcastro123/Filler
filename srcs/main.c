/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <dcastro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 18:23:27 by dcastro-          #+#    #+#             */
/*   Updated: 2017/09/26 00:23:52 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int	ft_error(char *s)
{
	ft_putstr(s);
	return (0);
}

static void	create_map(t_env *env)
{
	int		i;

	if (!(env->board.map = (char**)malloc(sizeof(char*) * (env->map_y + 1))))
		ft_error("malloc error\n");
	i = -1;
	env->board.map[env->map_x] = NULL;
	while (++i < env->map_x)
	{
		env->board.map[i] = (char*)ft_memalloc(sizeof(char) * (env->map_y + 1));
		ft_bzero(env->board.map[i], env->map_y + 1);
	}
}

static	void	skip_plateau(t_env *env, char *line)
{
	if (ft_strstr(line, "Plateau"))
		ft_strdel(&line);
}

static	void		get_mapsize(t_env *env)
{
	char *line;

	line = NULL;
	get_next_line(0, &line);
	if (ft_strstr(line, "Plateau"))
	{
		env->map_y = ft_atoi(line + 10);
		env->map_x = ft_atoi(line + 8);
	}
	ft_strdel(&line);
	create_map(env);
}

void	get_piece(t_env *env, char *line)
{
	if (ft_strstr(line, "Piece"))
	{
		env->p.x_size = ft_atoi(line + 5);
		env->p.y_size= ft_atoi(line + 7);
		ft_strdel(&line);
	}
	else
		ft_strdel(&line);
}

void	check_player(t_env *env)
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

int	parse(t_env *env, char *line)
{
	// if (ft_strchr(line, '<'))
		//not sure.....
	if (ft_strstr(line, "Plateau"))
		skip_plateau(env, line);
	// else if (ft_strchr(line, '0'))
	// 	update_map(env, line);
	else if (ft_strstr(line, "Piece"))
		get_piece(env, line);
	// do_placement(env);
	return (1);
}

static	void	init_env(t_env *env)
{
	t_board *board;
	t_p 	*p;

	if (!(env = (t_env*)malloc(sizeof(t_env))))
		ft_error("Struct malloc failed!\n");
	p = &env->p;
	board = &env->board;
	env->p1 = NULL;
	env->p2 = NULL;
	env->tot_score = 0;
	env->
}
int	main(void)
{
	t_env	env;
	char	*line;

	init_env(&env);
	check_player(&env);
	get_mapsize(&env);
	while ((get_next_line(0, &line)) > 0)
	{
		if (parse(&env, line))
			fprintf(stderr, "%s\n", "done reading line");
	}
	return (0);
}
