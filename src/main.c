/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 20:29:50 by asene             #+#    #+#             */
/*   Updated: 2024/12/23 17:29:48 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	init_vars(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, WIN_W, WIN_H, "FdF");
	vars->buffer = new_image(vars->mlx, WIN_W, WIN_H);
	vars->zoom = 30;
	vars->rot_x = 0;
	vars->rot_z = 0;
	vars->offsetX = 300;
	vars->offsetY = 300;
	vars->z_factor = 1;
	mlx_hook(vars->win, 17, 0, close_window, vars);
	mlx_hook(vars->win, 2, 1L << 0, key_down_hook, vars);
	//mlx_hook(vars->win, 3, 1L << 1, key_up_hook, vars);
	//mlx_loop_hook(vars->mlx, vars_loop, vars);
}

void	draw_line(t_img *dst, t_point *p1, t_point *p2, int color)
{
    int dx = abs((int)p1->px - (int)p2->px);
    int dy = abs((int)p1->py - (int)p2->py);
    int sx = ((int)p1->px < (int)p2->px) ? 1 : -1;
    int sy = ((int)p1->py < (int)p2->py) ? 1 : -1;
    int err = dx - dy;
	int	x = (int)p1->px;
	int	y = (int)p1->py;
    
    while (1)
	{
        if (x == (int)p2->px && y == (int)p2->py) break;
        int e2 = 2 * err;
        
        if (e2 > -dy) {
            err -= dy;
            x += sx;
        }
        if (e2 < dx) {
            err += dx;
            y += sy;
        }
		put_pixel(dst, x, y, color);
    }
}

void	render(t_vars *vars)
{
	t_point	*p;
	int		i;
	int		j;

	i = 0;
	while (i < vars->grid->height)
	{
		j = 0;
		while (j < vars->grid->width)
		{
			p = vars->grid->data[i][j];
			//p->px = (cos(vars->rot_z) *p->x - sin(vars->rot_z) * p->z / vars->z_factor) * vars->zoom + vars->offsetX;
			//p->py = (sin(vars->rot_x) * sin(vars->rot_z) * p->x + cos(vars->rot_x) * p->y + cos(vars->rot_z) * sin(vars->rot_x) * p->z / vars->z_factor) * vars->zoom + vars->offsetY;
			p->px = ((p->x - p->y) * cos(M_PI / 6)) * vars->zoom + vars->offsetX;
			p->py = ((p->x + p->y) * sin(M_PI / 6) - p->z / vars->z_factor) * vars->zoom + vars->offsetY;
			j++;
		}
		i++;
	}
	ft_bzero(vars->buffer->addr, vars->buffer->height * vars->buffer->line_length + vars->buffer->width * vars->buffer->bpp / 8);
	
	i = 0;
	while (i < vars->grid->height)
	{
		j = 0;
		while (j < vars->grid->width)
		{
			if (i + 1 < vars->grid->height)
				draw_line(vars->buffer, vars->grid->data[i][j], vars->grid->data[i + 1][j], 0xFFFFFF);
			if (j + 1 < vars->grid->width)
				draw_line(vars->buffer, vars->grid->data[i][j], vars->grid->data[i][j + 1], 0xFFFFFF);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->buffer->img, 0, 0);
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