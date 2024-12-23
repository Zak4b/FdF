/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 20:30:18 by asene             #+#    #+#             */
/*   Updated: 2024/12/23 17:07:02 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <libft.h>
# include <mlx.h>
# include <math.h>
# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif
# include <X11/keysym.h>
# include <fcntl.h>
# define WIN_W 1600
# define WIN_H 1000

typedef enum e_keycode
{
	KEY_SPACE = 32,
	KEY_ESC = 65307,
	KEY_W = 119,
	KEY_A = 97,
	KEY_S = 115,
	KEY_D = 100,
	KEY_ARU = 65362,
	KEY_ARD = 65364,
	KEY_ARL = 65361,
	KEY_ARR = 65363

}	t_keycode;

typedef struct s_point
{
	int		x;
	int		y;
	int		z;
	float	px;
	float	py;
}	t_point;

typedef struct s_grid
{
	int		width;
	int		height;
	t_point	***data;
}	t_grid;

typedef struct s_img
{
	int		width;
	int		height;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	t_img	*buffer;
	t_grid	*grid;
	int		offsetX;
	int		offsetY;
	int		zoom;
	int		z_factor;
	double	rot_x;
	double	rot_z;
}	t_vars;

int		key_down_hook(int k, t_vars *vars);
int		key_up_hook(int k, t_vars *vars);
int		close_window(t_vars *vars);
int		loop(t_vars *g);


void	put_pixel(t_img *img, int x, int y, int color);
void	free_image(t_vars *vars, t_img *img);
t_img	*new_image(void *mlx, int width, int height);

t_point	*new_point(int x, int y, int z);
t_grid	*init_grid(t_list *line_list, int height);
void	clear_grid(t_grid *grid);

t_grid	*parse_map(int fd);

void	render(t_vars *vars);

#endif