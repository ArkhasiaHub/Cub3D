/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_coord.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earaujo <earaujo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 11:14:04 by earaujo           #+#    #+#             */
/*   Updated: 2024/05/03 11:28:39 by earaujo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	move_left(t_cub *cub)
{
	int	px;
	int	py;

	px = cub->player->coord.x + cub->player->dy * 0.2;
	py = cub->player->coord.y - cub->player->dx * 0.2;
	if (check_collision_x(cub, px))
		cub->player->coord.x += cub->player->dy * 0.2;
	if (check_collision_y(cub, py))
		cub->player->coord.y -= cub->player->dx * 0.2;
	mlx_destroy_image(cub->mlx, cub->img.img);
	cub->img.img = mlx_new_image(cub->mlx, WIDTH, HEIGHT);
	cub->img.addr = mlx_get_data_addr(cub->img.img, &(cub->img.pixel_bits), \
	&(cub->img.line_bytes), &(cub->img.endian));
	display(cub);
	mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->img.img, 0, 0);
}

void	move_right(t_cub *cub)
{
	int	px;
	int	py;

	px = cub->player->coord.x - cub->player->dy * 0.2;
	py = cub->player->coord.y + cub->player->dx * 0.2;
	if (check_collision_x(cub, px))
		cub->player->coord.x -= cub->player->dy * 0.2;
	if (check_collision_y(cub, py))
		cub->player->coord.y += cub->player->dx * 0.2;
	mlx_destroy_image(cub->mlx, cub->img.img);
	cub->img.img = mlx_new_image(cub->mlx, WIDTH, HEIGHT);
	cub->img.addr = mlx_get_data_addr(cub->img.img, &(cub->img.pixel_bits), \
	&(cub->img.line_bytes), &(cub->img.endian));
	display(cub);
	mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->img.img, 0, 0);
}

void	move_up(t_cub *cub)
{
	int	px;
	int	py;

	px = cub->player->coord.x + cub->player->dx * 0.2;
	py = cub->player->coord.y + cub->player->dy * 0.2;
	if (check_collision_x(cub, px))
		cub->player->coord.x += cub->player->dx * 0.2;
	if (check_collision_y(cub, py))
		cub->player->coord.y += cub->player->dy * 0.2;
	mlx_destroy_image(cub->mlx, cub->img.img);
	cub->img.img = mlx_new_image(cub->mlx, WIDTH, HEIGHT);
	cub->img.addr = mlx_get_data_addr(cub->img.img, &(cub->img.pixel_bits), \
	&(cub->img.line_bytes), &(cub->img.endian));
	display(cub);
	mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->img.img, 0, 0);
}

void	move_down(t_cub *cub)
{
	int	px;
	int	py;

	px = cub->player->coord.x - cub->player->dx * 0.2;
	py = cub->player->coord.y - cub->player->dy * 0.2;
	if (check_collision_x(cub, px))
		cub->player->coord.x -= cub->player->dx * 0.2;
	if (check_collision_y(cub, py))
		cub->player->coord.y -= cub->player->dy * 0.2;
	mlx_destroy_image(cub->mlx, cub->img.img);
	cub->img.img = mlx_new_image(cub->mlx, WIDTH, HEIGHT);
	cub->img.addr = mlx_get_data_addr(cub->img.img, &(cub->img.pixel_bits), \
	&(cub->img.line_bytes), &(cub->img.endian));
	display(cub);
	mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->img.img, 0, 0);
}
