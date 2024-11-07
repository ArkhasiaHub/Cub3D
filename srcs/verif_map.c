/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbriche <sbriche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 09:41:44 by earaujo           #+#    #+#             */
/*   Updated: 2024/05/13 09:45:39 by sbriche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	error_verif(t_cub *cub, int nb)
{
	printf("Error\n");
	if (nb == 0)
		printf("Map not close\n");
	if (nb == 1)
		printf("Too much player\n");
	if (nb == 2)
		printf("Not valid map\n");
	if (nb == 3)
		printf("No player\n");
	free_map(cub);
	free_all(cub);
	exit(EXIT_FAILURE);
}

int	check_around(t_cub *cub, int i, int j)
{
	if (cub->map[i - 1][j] == ' ' || cub->map[i - 1][j] == '\0' \
		|| cub->map[i + 1][j] == ' ' || cub->map[i + 1][j] == '\0')
		return (-1);
	if (cub->map[i][j + 1] == '\0' || cub->map[i][j + 1] == ' ')
		return (-1);
	if (j == 0 || cub->map[i][j - 1] == ' ')
		return (-1);
	return (0);
}

void	pars_player(t_cub *cub, int i, int j)
{
	cub->is_player = 1;
	cub->player = malloc(sizeof(t_player));
	if (!cub->player)
	{
		free_map(cub);
		free_all(cub);
		exit(EXIT_FAILURE);
	}
	cub->player->coord.x = j;
	cub->player->coord.y = i;
	if (cub->map[i][j] == 'E')
		cub->player_direction = 0;
	else if (cub->map[i][j] == 'W')
		cub->player_direction = 180;
	else if (cub->map[i][j] == 'N')
		cub->player_direction = 270;
	else if (cub->map[i][j] == 'S')
		cub->player_direction = 90;
	cub->map[i][j] = '0';
}

void	verif_point(t_cub *cub, int i, int j)
{
	if (cub->map[i][j] == '0')
	{
		if (i == 0 || i == cub->size_map - 1 \
			|| check_around(cub, i, j) == -1 || \
			j > (int)ft_strlen(cub->map[i + 1]))
			error_verif(cub, 0);
		return ;
	}
	if (cub->map[i][j] == 'N' || cub->map[i][j] == 'S' \
		|| cub->map[i][j] == 'W' || cub->map[i][j] == 'E')
	{
		if (cub->is_player == 1 || i == 0 || i == cub->size_map - 1 \
			|| check_around(cub, i, j) == -1)
			error_verif(cub, 1);
		pars_player(cub, i, j);
		return ;
	}
	if (cub->map[i][j] == '1' || cub->map[i][j] == ' ')
		return ;
	error_verif(cub, 2);
}

void	verif_map(t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	while (i < cub->size_map)
	{
		j = 0;
		while (cub->map[i][j])
		{
			verif_point(cub, i, j);
			j++;
		}
		i++;
	}
	if (cub->is_player == 0)
		error_verif(cub, 3);
}
