/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 20:30:18 by asene             #+#    #+#             */
/*   Updated: 2024/12/23 02:11:45 by asene            ###   ########.fr       */
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

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
}	t_point;

typedef struct s_grid
{
	int		width;
	int		height;
	t_point	***data;
}	t_grid;


typedef struct s_vars
{
	void	*mlx;
	void	*win;
	t_grid	*grid;
	int		zoom;
}	t_vars;

int		key_down_hook(int k, t_vars *vars);
int		key_up_hook(int k, t_vars *vars);
int		close_window(t_vars *vars);
int		loop(t_vars *g);

t_point	*new_point(int x, int y, int z);
t_grid	*init_grid(t_list *line_list, int height);
void	clear_grid(t_grid *grid);

t_grid	*parse_map(int fd);

#endif