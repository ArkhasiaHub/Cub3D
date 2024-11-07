/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rotate_view.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earaujo <earaujo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 11:11:49 by earaujo           #+#    #+#             */
/*   Updated: 2024/05/03 11:27:26 by earaujo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	move_rotate_right(t_cub *cub)
{
	cub->player->pa += DR * 2;
	cub->player->pa = fix_ang(cub->player->pa);
	cub->player->dx = cos(cub->player->pa);
	cub->player->dy = sin(cub->player->pa);
	cub->player->px = -cub->player->dy * tan(FOV);
	cub->player->py = cub->player->dx * tan(FOV);
	mlx_destroy_image(cub->mlx, cub->img.img);
	cub->img.img = mlx_new_image(cub->mlx, WIDTH, HEIGHT);
	cub->img.addr = mlx_get_data_addr(cub->img.img, \
	&(cub->img.pixel_bits), &(cub->img.line_bytes), &(cub->img.endian));
	display(cub);
	mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->img.img, 0, 0);
}

void	move_rotate_left(t_cub *cub)
{
	cub->player->pa -= DR * 2;
	cub->player->pa = fix_ang(cub->player->pa);
	cub->player->dx = cos(cub->player->pa);
	cub->player->dy = sin(cub->player->pa);
	cub->player->px = -cub->player->dy * tan(FOV);
	cub->player->py = cub->player->dx * tan(FOV);
	mlx_destroy_image(cub->mlx, cub->img.img);
	cub->img.img = mlx_new_image(cub->mlx, WIDTH, HEIGHT);
	cub->img.addr = mlx_get_data_addr(cub->img.img, &(cub->img.pixel_bits), \
	&(cub->img.line_bytes), &(cub->img.endian));
	display(cub);
	mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->img.img, 0, 0);
}

void	move_rotate_view(t_cub *cub, int dir)
{
	if (dir == RIGHT)
		move_rotate_right(cub);
	else
		move_rotate_left(cub);
}
