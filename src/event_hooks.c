/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 10:31:59 by asene             #+#    #+#             */
/*   Updated: 2024/12/23 02:01:18 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int	key_down_hook(int k, t_vars *vars)
{
	if (k == XK_Escape)
		close_window(vars);
	return (0);
}

int	key_up_hook(int k, t_vars *vars)
{
	if (k == XK_Escape)
		close_window(vars);
	return (0);
}

int	close_window(t_vars *vars)
{
	clear_grid(vars->grid);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(EXIT_SUCCESS);
	return (0);
}

int	loop(t_vars *vars)
{
	(void)vars;
	return (1);
}
