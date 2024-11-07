/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earaujo <earaujo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 10:53:22 by earaujo           #+#    #+#             */
/*   Updated: 2024/05/03 11:26:52 by earaujo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_pixel(t_image *img, int pixel, int color)
{
	if (img->endian == 1)
	{
		img->addr[pixel + 0] = color >> 24;
		img->addr[pixel + 1] = color >> 16;
		img->addr[pixel + 2] = color >> 8;
		img->addr[pixel + 3] = color >> 0;
	}
	else if (img->endian == 0)
	{
		img->addr[pixel + 0] = color >> 0;
		img->addr[pixel + 1] = color >> 8;
		img->addr[pixel + 2] = color >> 16;
		img->addr[pixel + 3] = color >> 24;
	}
}

int	calc_pixel(int x, int y, t_image *img)
{
	unsigned int	pixel;

	pixel = (y * img->line_bytes)
		+ (x * (img->pixel_bits / 8));
	return (pixel);
}

int	get_pixel_color(void *img_ptr, int x, int y)
{
	int		bpp;
	int		size_line;
	int		endian;
	char	*image_data;
	int		index;

	image_data = mlx_get_data_addr(img_ptr, &bpp, &size_line, &endian);
	index = (y * size_line) + (x * (bpp / 8));
	return (*(unsigned int *)(image_data + index));
}
