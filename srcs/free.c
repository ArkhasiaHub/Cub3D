/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earaujo <earaujo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 10:45:36 by earaujo           #+#    #+#             */
/*   Updated: 2024/05/06 16:24:29 by earaujo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_map(t_cub *cub)
{
	int	i;

	i = 0;
	if (cub->map)
	{
		while (i < cub->size_map)
		{
			free(cub->map[i]);
			i++;
		}
		free(cub->map);
	}
	i = 0;
	if (cub->world_map)
	{
		while (i < cub->size_int)
		{
			if (cub->world_map[i])
				free(cub->world_map[i]);
			i++;
		}
		free(cub->world_map);
	}
}

void	free_all(t_cub *cub)
{
	if (cub->textures)
	{
		if (cub->textures->e_texture)
			mlx_destroy_image(cub->mlx, cub->textures->e_texture);
		if (cub->textures->n_texture)
			mlx_destroy_image(cub->mlx, cub->textures->n_texture);
		if (cub->textures->w_texture)
			mlx_destroy_image(cub->mlx, cub->textures->w_texture);
		if (cub->textures->s_texture)
			mlx_destroy_image(cub->mlx, cub->textures->s_texture);
		free(cub->textures);
	}
	if (cub->player)
		free(cub->player);
	if (cub->mlx)
	{
		if (cub->img.img)
			mlx_destroy_image(cub->mlx, cub->img.img);
		if (cub->mlx_win)
			mlx_destroy_window(cub->mlx, cub->mlx_win);
		mlx_destroy_display(cub->mlx);
		free(cub->mlx);
	}
	close(cub->fd);
}
