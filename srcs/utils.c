/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <dcastro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 17:36:38 by dcastro-          #+#    #+#             */
/*   Updated: 2017/09/30 03:38:12 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int	ft_error(char *s)
{
	ft_putstr_fd(s, 2);
	return (0);
}

void	free_structs(t_env *env)
{
	int	i;

	i = -1;
	while (++i < env->map_y)
		free(env->board.map[i]);
	free(env->board.map);
	if (!(env->board.map = (char**)malloc(sizeof(char*) * (env->map_y + 1))))
		ft_error("malloc error\n");
	i = -1;
	while (++i < env->p.y_size)
		free(env->p.piece[i]);
	free(env->p.piece);
	if (!(env->p.piece = (char**)malloc(sizeof(char*) * (env->p.y_size + 1))))
		ft_error("piece malloc error\n");
	env->count = 0;
	env->i = 0;
	env->overlap = 0;
}
