/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <dcastro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 17:36:17 by dcastro-          #+#    #+#             */
/*   Updated: 2017/09/29 01:49:03 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static	void	get_start(t_env *env)
{
	int	y;
	int	x;

	y = 0;
	while (env->board.map[y])
	{
		x = 0;
		while (env->board.map[y][x])
		{
			if (env->board.map[y][x] == env->p2)
			{
				env->enemy.x = x;
				env->enemy.y = y;
			}
			else if (env->board.map[y][x] == env->p1)
			{
				env->player.x = x;
				env->player.y = y;
			}
			x++;
		}
		y++;
	}
	env->start = 1;
	env->dir = env->enemy.y > env->player.y ? RIGHT : LEFT;
}


static	int		check_place(t_env *env, int x, int y, int valid)
{
	int	i;
	int	j;

	i = 0;
	fprintf(stderr, "x being passed: %d\n", x);
	fprintf(stderr, "y being passed: %d\n\n", y);
	while (env->p.piece[i])
	{
		j = 0;
		while (env->p.piece[i][j])
		{
			if (env->p.piece[i][j] == '*' && i >= 0 && j >= 0)
			{
				fprintf(stderr, "%s\n", "----------------");
				fprintf(stderr, "i being passed: %d\n", i);
				fprintf(stderr, "j being passed: %d\n\n", j);
				if (i + y < 0 || x + j < 0 || i + y >= env->map_y || x + j >= env->map_x)
					return (0);
				else if (env->board.map[y + i][j + x] == '*')
					env->overlap++;
				else if (env->board.map[y + i][j + x] == env->p2)
					return (0);
				fprintf(stderr, "%s\n\n", "checking done");
				fprintf(stderr, "%s\n\n", "--------------");
			}
			j++;
		}
		i++;
	}
	return (valid = env->overlap == 1 ? 1 : 0);
}

void	go_upleft(t_env *env)
{
	int	valid;

	env->board.map_posy = env->map_y + env->p.y_size;
	valid = 0;
	fprintf(stderr, "%s\n", "before going left");
	while (env->board.map_posy > -env->p.y_size)
	{
		env->board.map_posx = env->map_x + env->p.x_size;
		while (env->board.map_posx > -env->p.x_size)
		{
			valid = check_place(env, env->board.map_posx, env->board.map_posy, valid);
			if (valid)
			{
				fprintf(stderr, "%s\n", "valid");
				env->board.xplace = env->board.map_posx;
				env->board.yplace = env->board.map_posy;
			}
			env->board.map_posx--;
		}
		env->board.map_posy--;
	}
	// while (env->board.map_posy - env->p.y_size < env->map_y)
	// {
	// 	env->board.map_posx = env->map_x - env->p.x_size;
	// 	while (env->board.map_posx  - env->p.x_size < env->map_x)
	// 	{
	// 		valid = check_place(env, env->board.map_posx, env->board.map_posy, valid);
	// 		if (valid == 1)
	// 		{
	// 			env->board.xplace = env->board.map_posx;
	// 			env->board.yplace = env->board.map_posy;
	// 		}
	// 		env->board.map_posx++;
	// 	}
	// 	env->board.map_posy++;
	// }
}

void	check_piece(t_env *env)
{
	// if (env->start == 0)
	// 	get_start(env);
	// // if (env->dir == RIGHT)
	// // 	ft_error("fl");
	// if (env->dir == LEFT)
	// {
	// 	fprintf(stderr, "%s\n", "<<<<<<<<<<<<<<<");
	// 	go_upleft(env);
	// }
	// ft_putnbr(env->board.yplace);
	// ft_putchar(' ');
	// ft_putnbr(env->board.xplace);
	// ft_putchar('\n');
	fprintf(stderr, "%s\n", "??????????");
	ft_putstr("8 2\n");
	free_structs(env);
}