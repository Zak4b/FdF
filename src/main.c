/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 20:29:50 by asene             #+#    #+#             */
/*   Updated: 2024/12/23 02:27:32 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	init_vars(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, 1000, 1600, "FdF");
	mlx_hook(vars->win, 17, 0, close_window, vars);
	mlx_hook(vars->win, 2, 1L << 0, key_down_hook, vars);
	mlx_hook(vars->win, 3, 1L << 1, key_up_hook, vars);
	//mlx_loop_hook(vars->mlx, vars_loop, vars);
}

void	render(t_vars *vars)
{
	int	i;
	int	j;
	double	angle = M_PI / 6;

	i = 0;
	while (i < vars->grid->height)
	{
		j = 0;
		while (j < vars->grid->width)
		{
			t_point	*point = vars->grid->data[i][j];
			int	x = (point->x - point->y) *5 * cos(angle);
			int	y = (point->x + point->y) *5 * sin(angle) - point->z;
			mlx_pixel_put(vars->mlx, vars->win, x + 100, y + 100, 0xFF0000);
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		fd;
	t_vars	vars;

	if (argc != 2)
		return (ft_fprintf(2, "Usage: %s <FILE>\n", argv[0]), EXIT_FAILURE);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (ft_fprintf(2, "Can't open file \"%s\"\n", argv[1]), 1);
	vars.grid = parse_map(fd);
	close(fd);
	init_vars(&vars);
	render(&vars);
	mlx_loop(vars.mlx);
}