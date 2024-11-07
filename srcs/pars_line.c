/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earaujo <earaujo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:22:28 by earaujo           #+#    #+#             */
/*   Updated: 2024/05/03 11:17:02 by earaujo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	protect_realloc(t_cub *cub, char *line)
{
	free(line);
	free_map(cub);
	free_all(cub);
	exit(EXIT_FAILURE);
}

void	protect_new(t_cub *cub, char *line, char **new)
{
	int	i;

	i = 0;
	while (new[i])
	{
		free(new[i]);
		i++;
	}
	if (cub->map)
		free_map(cub);
	free(new);
	free(line);
	free_all(cub);
	exit(EXIT_FAILURE);
}

void	first_realloc(t_cub *cub, char *line)
{
	cub->map = malloc(sizeof(char *) * 1);
	if (!cub->map)
		protect_realloc(cub, line);
	cub->map[0] = malloc(sizeof(char ) * ft_strlen(line));
	if (!cub->map[0])
		protect_realloc(cub, line);
}

void	realloc_map(t_cub *cub, char *line)
{
	int		i;
	char	**new;

	i = -1;
	if (cub->size_map == 0)
		first_realloc(cub, line);
	else
	{
		new = malloc(sizeof(char *) * (cub->size_map + 1));
		if (!new)
			protect_realloc(cub, line);
		while (++i < cub->size_map)
		{
			new[i] = ft_strdup(cub->map[i]);
			if (!new[i])
				protect_new(cub, line, new);
			free(cub->map[i]);
		}
		free(cub->map);
		cub->map = NULL;
		new[i] = malloc(sizeof(char) * ft_strlen(line) + 1);
		if (!new[i])
			protect_new(cub, line, new);
		cub->map = new;
	}
}

void	pars_line(char *line, t_cub *cub)
{
	int	i;

	i = 0;
	realloc_map(cub, line);
	cub->size_map++;
	while (line[i] != '\n' && line[i] != '\0')
	{
		cub->map[cub->size_map - 1][i] = line[i];
		i++;
	}
	cub->map[cub->size_map - 1][i] = '\0';
}
