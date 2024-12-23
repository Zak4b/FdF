/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 20:30:18 by asene             #+#    #+#             */
/*   Updated: 2024/12/23 01:33:16 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <libft.h>
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
	t_grid	*grid;
	int		zoom;
}	t_vars;

t_point	*new_point(int x, int y, int z);
t_grid	*init_grid(t_list *line_list, int height);
void	clear_grid(t_grid *grid);

t_grid	*parse_map(int fd);

#endif