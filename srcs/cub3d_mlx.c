/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earaujo <earaujo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 10:50:56 by earaujo           #+#    #+#             */
/*   Updated: 2024/05/13 09:23:37 by earaujo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_ground_sky(t_cub *cub)
{
	int	i;
	int	j;

	i = -1;
	while (++i < HEIGHT * 0.5)
	{
		j = -1;
		while (++j < WIDTH)
			draw_pixel(&(cub->img), calc_pixel(j, i, &(cub->img)), \
			cub->textures->color_c);
	}
	i = HEIGHT * 0.5;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			draw_pixel(&(cub->img), calc_pixel(j, i, &(cub->img)), \
			cub->textures->color_f);
			j++;
		}
		i++;
	}
}

void	display(t_cub *cub)
{
	draw_ground_sky(cub);
	draw_rays(cub);
}

void	init(t_cub *cub)
{
	cub->player->pa = fix_ang(degree_to_radian(cub->player_direction));
	cub->player->dx = cos(cub->player->pa);
	cub->player->dy = sin(cub->player->pa);
	cub->player->px = 0;
	cub->player->py = tan(FOV);
	cub->player->px = -cub->player->dy * tan(FOV);
	cub->player->py = cub->player->dx * tan(FOV);
}

int	close_win_cross(t_cub *cub)
{
	free_all(cub);
	free_map(cub);
	exit(EXIT_SUCCESS);
}

int	create_cub(t_cub *cub)
{
	cub->mlx_win = mlx_new_window(cub->mlx, WIDTH, HEIGHT, "Cub3d - Genesis");
	if (!cub->mlx_win)
	{
		free_all(cub);
		free_map(cub);
		exit(EXIT_FAILURE);
	}
	cub->img.img = mlx_new_image(cub->mlx, WIDTH, HEIGHT);
	if (!cub->img.img)
	{
		free_all(cub);
		free_map(cub);
		exit(EXIT_FAILURE);
	}
	cub->img.addr = mlx_get_data_addr(cub->img.img, &(cub->img.pixel_bits), \
	&(cub->img.line_bytes), &(cub->img.endian));
	init(cub);
	display(cub);
	mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->img.img, 0, 0);
	mlx_hook(cub->mlx_win, 2, 1L << 0, move, cub);
	mlx_hook(cub->mlx_win, 17, 1L << 2, close_win_cross, cub);
	mlx_loop(cub->mlx);
	return (0);
}
