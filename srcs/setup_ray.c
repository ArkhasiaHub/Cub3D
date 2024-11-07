/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earaujo <earaujo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 10:00:52 by earaujo           #+#    #+#             */
/*   Updated: 2024/05/03 11:22:09 by earaujo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_rays(t_cub *cub, t_ray *ray)
{
	ray->camera_x = 2 * ray->x / (double)WIDTH - 1;
	ray->ray_x = cub->player->dx + cub->player->px * ray->camera_x;
	ray->ray_y = cub->player->dy + cub->player->py * ray->camera_x;
	ray->map_x = (int)cub->player->coord.x;
	ray->map_y = (int)cub->player->coord.y;
	if (ray->ray_x == 0)
		ray->delta_dist_x = 1e30;
	else
		ray->delta_dist_x = fabs(1.0 / ray->ray_x);
	if (ray->ray_y == 0)
		ray->delta_dist_y = 1e30;
	else
		ray->delta_dist_y = fabs(1.0 / ray->ray_y);
}

void	find_side_dist(t_cub *cub, t_ray *ray)
{
	ray->hit = 0;
	if (ray->ray_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (cub->player->coord.x - ray->map_x) \
		* ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - cub->player->coord.x) \
		* ray->delta_dist_x;
	}
	if (ray->ray_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (cub->player->coord.y - ray->map_y) \
		* ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - cub->player->coord.y) \
		* ray->delta_dist_y;
	}
}
