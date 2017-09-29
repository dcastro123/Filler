/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <dcastro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 14:19:12 by dcastro-          #+#    #+#             */
/*   Updated: 2017/09/29 14:20:16 by dcastro-         ###   ########.fr       */
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
	fprintf(stderr, "env->i: %d\n", env->i);
	fprintf(stderr, "line being duped: %s\n", line);
	env->p.piece[env->i] = ft_strdup(line);
	fprintf(stderr, "piece after dupe: %s\n\n", env->p.piece[env->i]);
	env->i += 1;
	fprintf(stderr, "env->i++: %d\n", env->i);
}

int	parse(t_env *env, char *line)
{
	int i = 0;
	char	*c;
	if (ft_isdigit(line[0]))
		env->board.map[env->count++] = ft_strdup(line + 4);
	else if (ft_strstr(line, "Piece"))
	{
		fprintf(stderr, "%s\n", "getting piece size");
		get_piece_size(env, line);
		fprintf(stderr, "x: %d y: %d\n\n", env->p.x_size, env->p.y_size);
	}
	else if (line[0] == '*' || line[0] == '.')
	{
		fprintf(stderr, "%s\n", "strduping the line");
		create_piece(env, line);
		// fprintf(stderr, "piece at row[%d]: %s\n\n", env->i, env->p.piece[env->i]);
	}
	// if (env->p.piece)
	// {
	// 	c = ft_itoa(i++);
	// 	ft_putstr_fd(c, 2);
	// }
	if (env->p.y_size == env->i)
	{
		fprintf(stderr, "%s\n", "[pringting piece:");
		fprintf(stderr, "%s\n", "-----------------");
		int a, b = 0;
		while (env->p.piece[a])
		{
			fprintf(stderr, "%s\n", "<<<<<<<<<<<<<<<");
			b = 0;
			while (env->p.piece[a][b])
			{
				fprintf(stderr, "%s\n", ">>>>>>>>>>>>>>>>");
				fprintf(stderr, "env->p.piece[%d][%d]: %c\n", a, b, env->p.piece[a][b]);
				b++;
			}
			a++;
		}
		fprintf(stderr, "%s\n\n", "-------------------------");
		return (1);
	}
	return (0);
}
