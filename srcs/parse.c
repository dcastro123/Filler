/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <dcastro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 14:19:12 by dcastro-          #+#    #+#             */
/*   Updated: 2017/10/01 16:11:54 by dcastro-         ###   ########.fr       */
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

int				parse(t_env *env, char *line)
{
	if (ft_isdigit(line[0]))
		store_mapline(env, line);
	else if (ft_strstr(line, "Piece"))
		get_piece_size(env, line);
	else if (line[0] == '*' || line[0] == '.')
		create_piece(env, line);
	if (env->p.y_size == env->i)
		return (1);
	return (0);
}
