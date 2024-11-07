/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earaujo <earaujo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 15:36:27 by earaujo           #+#    #+#             */
/*   Updated: 2024/05/06 16:24:20 by earaujo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	error_map_to_int(t_cub *cub, int i)
{
	int	j;

	j = 0;
	if (cub->world_map)
	{
		while (j < i)
		{
			if (cub->world_map[j])
				free(cub->world_map[j]);
			j++;
		}
	}
}

void	protect_int_map(t_cub *cub)
{
	free_map(cub);
	free_all(cub);
	exit(EXIT_FAILURE);
}

void	map_to_int(t_cub *cub)
{
	int	i;
	int	j;

	cub->world_map = malloc(sizeof(int *) * cub->size_map);
	if (!cub->world_map)
		protect_int_map(cub);
	i = 0;
	while (i < cub->size_map)
	{
		j = 0;
		cub->world_map[i] = malloc(sizeof(int) * ft_strlen(cub->map[i]) + 1);
		if (!cub->world_map[i])
		{
			error_map_to_int(cub, i);
			protect_int_map(cub);
		}
		cub->size_int++;
		while (j < (int)ft_strlen(cub->map[i]))
		{
			cub->world_map[i][j] = little_atoi(cub->map[i][j]);
			j++;
		}
		i++;
	}
}
