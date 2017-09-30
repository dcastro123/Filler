/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <dcastro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 14:19:12 by dcastro-          #+#    #+#             */
/*   Updated: 2017/09/29 18:35:20 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static	void	get_piece_size(t_env *env, char *line)
{
	env->p.x_size = ft_atoi(line + 8);
	env->p.y_size= ft_atoi(line + 6);
	if (!(env->p.piece = (char**)malloc(sizeof(char*) * (env->p.y_size))))
		ft_error("piece malloc error\n");
}

static	void	create_piece(t_env *env, char *line)
{
	// fprintf(stderr, "env->i: %d\n", env->i);
	// fprintf(stderr, "line being duped: %s\n", line);
	env->p.piece[env->i] = ft_strdup(line);
	// fprintf(stderr, "piece after dupe: %s\n\n", env->p.piece[env->i]);
	env->i += 1;
	// fprintf(stderr, "env->i++: %d\n", env->i);
}

static	void	store_mapline(t_env *env, char *line)
{
	env->board.map[env->count] = ft_strdup(line + 4);
	// fprintf(stderr, "map after store at [%d]: %s\n", env->count, env->board.map[env->count]);
	env->count += 1;
}

int	parse(t_env *env, char *line)
{
	if (ft_isdigit(line[0]))
	{
		store_mapline(env, line);
	}
	else if (ft_strstr(line, "Piece"))
	{
		get_piece_size(env, line);
	}
	else if (line[0] == '*' || line[0] == '.')
	{
		// fprintf(stderr, "%s\n", "strduping the line");
		create_piece(env, line);
		// fprintf(stderr, "piece at row[%d]: %s\n\n", env->i, env->p.piece[env->i]);
	}
	if (env->p.y_size == env->i && env->map_y == env->count)
	{
		// int a = 0;
		// fprintf(stderr, "%s\n\n", "printing map");
		// while (a < env->map_y)
		// {
		// 	fprintf(stderr, "%s\n", env->board.map[a]);
		// 	a++;
		// }
		// int b = 0;
		// fprintf(stderr, "%s\n\n", "-----------------------");
		// fprintf(stderr, "%s\n\n", "printing piece---------");
		// while (b < env->p.y_size)
		// {
		// 	fprintf(stderr, "%s\n", env->p.piece[b]);
		// 	b++;
		// }
		// fprintf(stderr, "%s\n\n", "-------------------------");
		return (1);
	}
	return (0);
}
