/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <dcastro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 17:36:22 by dcastro-          #+#    #+#             */
/*   Updated: 2017/10/01 17:00:53 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static void	get_start(t_env *env)
{
	int	y;
	int	x;

	y = 0;
	while (env->board.map[y])
	{
		x = 0;
		while (env->board.map[y][x])
		{
			if ((NEW(env->board.map[y][x])) == env->p2)
			{
				env->enemy.x = x;
				env->enemy.y = y;
			}
			else if ((NEW(env->board.map[y][x])) == env->p1)
			{
				env->player.x = x;
				env->player.y = y;
			}
			x++;
		}
		y++;
	}
	env->start = 1;
	env->dir = env->enemy.y > env->player.y ? LEFT : RIGHT;
}

void		go_upleft(t_env *env)
{
	int	value;

	value = 0;
	POS_Y = env->p.y_size + env->map_y;
	while (POS_Y > -env->p.y_size)
	{
		POS_X = env->p.x_size + env->map_x;
		while (POS_X > -env->p.x_size)
		{
			if ((value = check_place(env, POS_X, POS_Y, value)))
				if (value < env->enemy_dist)
					set_piece(env, value);
			POS_X--;
		}
		POS_Y--;
	}
}

void		go_downright(t_env *env)
{
	int	value;

	value = 0;
	POS_Y = -env->p.y_size;
	while (POS_Y < env->map_y)
	{
		POS_X = -env->p.x_size;
		while (POS_X < env->map_x)
		{
			if ((value = check_place(env, POS_X, POS_Y, value)))
				if (value < env->enemy_dist)
					set_piece(env, value);
			POS_X++;
		}
		POS_Y++;
	}
}

void		check_piece(t_env *env)
{
	env->enemy.max = MAX(env->map_x, env->map_y);
	env->enemy_dist = env->enemy.max;
	env->board.xplace = 0;
	env->board.yplace = 0;
	if (env->start == 0)
		get_start(env);
	if (env->dir == RIGHT)
		go_downright(env);
	else if (env->dir == LEFT)
		go_upleft(env);
	ft_printf("%d %d\n", env->board.yplace, env->board.xplace);
	free_structs(env);
}
