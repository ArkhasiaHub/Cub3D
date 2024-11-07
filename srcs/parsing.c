/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earaujo <earaujo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 15:15:41 by earaujo           #+#    #+#             */
/*   Updated: 2024/05/10 10:27:22 by earaujo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_cub(t_cub *cub, int fd)
{
	cub->textures = malloc(sizeof(t_textures));
	if (!cub->textures)
	{
		free_all(cub);
		exit(EXIT_FAILURE);
	}
	cub->textures->e_texture = NULL;
	cub->textures->n_texture = NULL;
	cub->textures->w_texture = NULL;
	cub->textures->s_texture = NULL;
	cub->textures->is_c = false;
	cub->textures->is_f = false;
	cub->map = NULL;
	cub->map_begin = false;
	cub->newline = false;
	cub->size_map = 0;
	cub->size_int = 0;
	cub->is_player = 0;
	cub->fd = fd;
}

int	check_completion(t_cub *cub)
{
	if (cub->textures->e_texture == NULL || cub->textures->w_texture == NULL)
		return (-1);
	if (cub->textures->n_texture == NULL || cub->textures->s_texture == NULL)
		return (-1);
	if (cub->textures->is_c == false || cub->textures->is_f == false)
		return (-1);
	return (0);
}

void	parsing(char *line, t_cub *cub)
{
	if (check_begin_map(line) == 1)
		cub->map_begin = true;
	if (check_begin_map(line) == 1 && cub->newline == true)
	{
		printf("Error\nInvalid map\n");
		free(line);
		free_map(cub);
		free_all(cub);
		exit(EXIT_FAILURE);
	}
	if (pars_textures(line, cub) == 1)
		return ;
	if (check_completion(cub) == -1)
	{
		printf("Error\nMissing textures\n");
		free(line);
		free_all(cub);
		exit(EXIT_FAILURE);
	}
	else
		pars_line(line, cub);
}

void	init_and_read(int fd, t_cub *cub)
{
	char		*line;

	line = NULL;
	while (1)
	{
		if (line)
			free(line);
		line = get_next_line(fd);
		if (line == NULL || line[0] == '\0')
			break ;
		if (line[0] != '\n')
			parsing(line, cub);
		else if (cub->map_begin == true)
			cub->newline = true;
	}
	if (line)
		free(line);
	verif_map(cub);
	map_to_int(cub);
	create_cub(cub);
	free_map(cub);
}
