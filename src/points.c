/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 21:48:25 by asene             #+#    #+#             */
/*   Updated: 2024/12/23 01:30:17 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

t_point	*new_point(int x, int y, int z)
{
	t_point	*p;

	p = malloc(sizeof(t_point));
	p->x = x;
	p->y = y;
	p->z = z;
	return (p);
}

t_grid	*init_grid(t_list *p_list, int height)
{
	int		i;
	int		j;
	int		width;
	t_grid	*grid;

	width = ft_lstsize(p_list) / height;
	grid = ft_calloc(1, sizeof(t_grid));
	grid->height = height;
	grid->width = width;
	grid->data = ft_calloc(height + 1, sizeof(t_point ***));
	i = 0;
	while (i < height && p_list)
	{
		grid->data[i] = ft_calloc(width + 1, sizeof(t_point **));
		j = 0;
		while (j < width && p_list)
		{
			grid->data[i][j++] = p_list->content;
			p_list = p_list->next;
		}
		i++;
	}
	return (grid);	
}

void	clear_grid(t_grid *grid)
{
	int	i;
	int	j;

	i = 0;
	while (i < grid->height)
	{
		j = 0;
		while (j < grid->width)
			free(grid->data[i][j++]);
		free(grid->data[i++]);
	}
	free(grid->data);
	free(grid);
}
