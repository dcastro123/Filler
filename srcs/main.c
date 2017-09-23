/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <dcastro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 18:23:27 by dcastro-          #+#    #+#             */
/*   Updated: 2017/09/22 17:33:00 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int	ft_error(char *s)
{
	ft_putstr(s);
	return (0);
}

// int	check_file(t_env *env)
// {
// 	char	*line;
// 	int		i;

// 	line = NULL;
// 	i = 0;
// 	if (get_next_line(0, &line) > 0)
// 	{
// 		if (ft_strchr(line, '\n'))
// 	}
// }
int	main(void)
{
	t_env	*env;
	char	*line;

	line = NULL;
	if (!(env = (t_env*)malloc(sizeof(t_env))))
		ft_error("Struct malloc failed!\n");
	// if (!(check_file(env)))
	// 	ft_error("Read error!\n");
	while (get_next_line(0, &line) > 0)
	{
		ft_putstr_fd(">>", 2);
		ft_putendl_fd(line, 2);
		ft_putstr("\n");
		ft_strdel(&line);
	}
	ft_strdel(&line);
	ft_putendl_fd("done reading\n", 2);
	return (0);
}
