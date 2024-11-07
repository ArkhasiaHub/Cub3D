/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earaujo <earaujo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 14:43:54 by earaujo           #+#    #+#             */
/*   Updated: 2024/05/06 12:51:37 by earaujo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

bool	check_collision_x(t_cub *cub, int new_x)
{
	if (cub->map[(int)cub->player->coord.y][new_x] == '0')
		return (true);
	return (false);
}

bool	check_collision_y(t_cub *cub, int new_y)
{
	if (cub->map[new_y][(int)cub->player->coord.x] == '0')
		return (true);
	return (false);
}

int	move(int key, t_cub *cub)
{
	if (key == LEFT)
		move_left(cub);
	else if (key == UP)
		move_up(cub);
	else if (key == RIGHT)
		move_right(cub);
	else if (key == DOWN)
		move_down(cub);
	else if (key == 65363)
		move_rotate_view(cub, RIGHT);
	else if (key == 65361)
		move_rotate_view(cub, LEFT);
	else if (key == 65307)
	{
		free_all(cub);
		free_map(cub);
		exit(EXIT_SUCCESS);
	}
	return (0);
}
