/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <dcastro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 14:19:12 by dcastro-          #+#    #+#             */
/*   Updated: 2017/09/30 22:27:22 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static	void	get_piece_size(t_env *env, char *line)
{
	env->p.x_size = ft_atoi(line + 8);
	env->p.y_size = ft_atoi(line + 6);
	if (!(env->p.piece = (char**)malloc(sizeof(char*) * (env->p.y_size + 1))))
		ft_error("piece malloc error\n");
}

static	void	create_piece(t_env *env, char *line)
{
	env->p.piece[env->i] = ft_strdup(line);
	env->i += 1;
}

static	void	store_mapline(t_env *env, char *line)
{
	env->board.map[env->count] = ft_strdup(line + 4);
	env->count += 1;
}

int	parse(t_env *env, char *line)
{
	// write(2, "fuckit\n", 8);
	if (ft_isdigit(line[0]))
		store_mapline(env, line);
	else if (ft_strstr(line, "Piece")){
		// write(2, "tyler ugly\n", 11);
		get_piece_size(env, line);
	}
	else if (line[0] == '*' || line[0] == '.')
	{
		// write(2, "tyler scrup\n", 12);
		// fprintf(stderr, "%s\n", "strduping the line");
		create_piece(env, line);
		// write(2, "yes he is\n", 10);
		// fprintf(stderr, "piece at row[%d]: %s\n\n", env->i, env->p.piece[env->i]);
	}
	if (env->p.y_size == env->i)
	{
		// write(2, "tyler sucks\n", 12);
		// int a = 0;
		// ft_putstr_fd("printing map\n", 2);
		// while (a < env->map_y)
		// {
		// 	ft_putendl_fd(env->board.map[a], 2);
		// 	a++;
		// }
		// int b = 0;
		// fprintf(stderr, "%s\n\n", "-----------------------");
		// fprintf(stderr, "%s\n\n", "printing piece---------");
		// int b = 0;
		// while (b < env->p.y_size)
		// {
		// 	fprintf(stderr, "%s\n", env->p.piece[b]);
		// 	b++;
		// }
		// fprintf(stderr, "%s\n\n", "-------------------------");
		return (1);
	}
	// write(2, "ret0 after: ", 12);
	// write(2, line, ft_strlen(line));
	// write(2, "\n", 1);
	return (0);
}
