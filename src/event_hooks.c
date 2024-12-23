/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 10:31:59 by asene             #+#    #+#             */
/*   Updated: 2024/12/23 17:21:36 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int	key_down_hook(int k, t_vars *vars)
{
	if (k == XK_Escape)
		close_window(vars);
	if (k == KEY_W || k == KEY_S || k == KEY_A || k == KEY_D)
	{
		if(k == KEY_W)
			vars->rot_x += .5;
		else if (k == KEY_S)
			vars->rot_x -= .5;
		if(k == KEY_A)
			vars->rot_z += .5;
		else if (k == KEY_D)
			vars->rot_z -= .5;
		render(vars);
	}
	else if (k == KEY_ARL)
		vars->offsetX -= 10;
	else if (k == KEY_ARR)
		vars->offsetX += 10;
	else if (k == KEY_ARU)
		vars->offsetY -= 10;
	else if (k == KEY_ARD)
		vars->offsetY += 10;
	render(vars);
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
