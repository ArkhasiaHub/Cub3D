/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earaujo <earaujo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 10:22:02 by earaujo           #+#    #+#             */
/*   Updated: 2024/05/06 12:52:53 by earaujo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	loop_ray(t_cub *cub, t_ray *ray)
{
	while (ray->hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
			if (ray->ray_x >= 0)
				ray->side_wall = WEST;
			else
				ray->side_wall = EAST;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
			if (ray->ray_y >= 0)
				ray->side_wall = SOUTH;
			else
				ray->side_wall = NORTH;
		}
		if (cub->world_map[ray->map_y][ray->map_x] == 1)
			ray->hit = 1;
	}
}

void	end_and_start(t_cub *cub, t_ray *ray)
{
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->side_dist_x - ray->delta_dist_x);
	else
		ray->perp_wall_dist = (ray->side_dist_y - ray->delta_dist_y);
	ray->line_height = (int)(HEIGHT / ray->perp_wall_dist);
	ray->draw_start = -ray->line_height * 0.5 + HEIGHT * 0.5;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height * 0.5 + HEIGHT * 0.5;
	if (ray->draw_end >= HEIGHT)
		ray->draw_end = HEIGHT - 1;
	if (ray->side == 0)
		ray->wall_x = WIDTH - \
		(cub->player->coord.y + ray->perp_wall_dist * ray->ray_y);
	else
		ray->wall_x = WIDTH - \
		(cub->player->coord.x + ray->perp_wall_dist * ray->ray_x);
	ray->wall_x -= floor(ray->wall_x);
}

void	draw_wall(t_cub *cub, t_ray *ray)
{
	int	color;

	ray->tex_y = (int)ray->tex_pos & (64 - 1);
	ray->tex_pos += ray->step;
	if (ray->side_wall == NORTH)
		color = get_pixel_color(cub->textures->n_texture, \
		ray->tex_x, ray->tex_y);
	else if (ray->side_wall == SOUTH)
		color = get_pixel_color(cub->textures->s_texture, \
		ray->tex_x, ray->tex_y);
	else if (ray->side_wall == EAST)
		color = get_pixel_color(cub->textures->e_texture, \
		ray->tex_x, ray->tex_y);
	else if (ray->side_wall == WEST)
		color = get_pixel_color(cub->textures->w_texture, \
		ray->tex_x, ray->tex_y);
	if (ray->side == 0)
		color = (color >> 1) & 8355711;
	draw_pixel(&(cub->img), calc_pixel(ray->x, ray->j, &(cub->img)), color);
	ray->j++;
}

void	draw_rays(t_cub *cub)
{
	t_ray	ray;

	ray.x = 0;
	while (ray.x < WIDTH)
	{
		init_rays(cub, &ray);
		find_side_dist(cub, &ray);
		loop_ray(cub, &ray);
		end_and_start(cub, &ray);
		ray.tex_x = (int)(ray.wall_x * 64.0);
		if (ray.side == 0 && ray.ray_x > 0)
			ray.tex_x = 64 - ray.tex_x - 1;
		if (ray.side == 1 && ray.ray_y < 0)
			ray.tex_x = 64 - ray.tex_x - 1;
		ray.step = 1.0 * 64 / ray.line_height;
		ray.tex_pos = (ray.draw_start - HEIGHT * 0.5 + \
		ray.line_height * 0.5) * ray.step;
		ray.j = ray.draw_start;
		while (ray.j < ray.draw_end)
			draw_wall(cub, &ray);
		ray.x++;
	}
}
