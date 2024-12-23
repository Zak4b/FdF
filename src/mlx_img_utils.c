/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_img_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 11:35:22 by asene             #+#    #+#             */
/*   Updated: 2024/12/23 13:53:59 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x > img->width || y < 0 || y > img->height)
		return ;
	dst = img->addr
		+ (y * img->line_length + x * (img->bpp / 8));
	*(int *)dst = color;
}

void	free_image(t_vars *vars, t_img *img)
{
	mlx_destroy_image(vars->mlx, img->img);
	free(img);
}

t_img	*new_image(void *mlx, int width, int height)
{
	t_img	*i;

	i = ft_calloc(1, sizeof(t_img));
	i->img = mlx_new_image(mlx, width, height);
	i->addr = mlx_get_data_addr(i->img,
			&i->bpp,
			&i->line_length,
			&i->endian);
	i->width = width;
	i->height = height;
	return (i);
}
