/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earaujo <earaujo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 15:55:52 by earaujo           #+#    #+#             */
/*   Updated: 2024/05/06 17:01:45 by earaujo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	pars_n(char *line, int *i, t_cub *cub)
{
	char	*temp;

	if (ft_strncmp(line, "NO ", 3) == 0)
	{
		*i += 2;
		while (line[*i] == ' ')
			*i += 1;
		temp = ft_strdup(line + *i);
		if (!temp)
			protect_pars(line, cub);
		temp[ft_strlen(temp) - 1] = '\0';
		cub->textures->n_texture = mlx_xpm_file_to_image(cub->mlx, temp, \
			&cub->textures->n_texture_width, &cub->textures->n_texture_height);
		if (!cub->textures->n_texture)
		{
			free(temp);
			printf("Error\nCouldn't load textures\n");
			protect_pars(line, cub);
		}
		free(temp);
	}
}

void	pars_s(char *line, int *i, t_cub *cub)
{
	char	*temp;

	if (ft_strncmp(line, "SO ", 3) == 0)
	{
		*i += 2;
		while (line[*i] == ' ')
			*i += 1;
		temp = ft_strdup(line + *i);
		if (!temp)
			protect_pars(line, cub);
		temp[ft_strlen(temp) - 1] = '\0';
		cub->textures->s_texture = mlx_xpm_file_to_image(cub->mlx, temp, \
			&cub->textures->s_texture_width, &cub->textures->s_texture_height);
		if (!cub->textures->s_texture)
		{
			free(temp);
			printf("Error\nCouldn't load textures\n");
			protect_pars(line, cub);
		}
		free(temp);
	}
}

void	pars_w(char *line, int *i, t_cub *cub)
{
	char	*temp;

	if (ft_strncmp(line, "WE ", 3) == 0)
	{
		*i += 2;
		while (line[*i] == ' ')
			*i += 1;
		temp = ft_strdup(line + *i);
		if (!temp)
			protect_pars(line, cub);
		temp[ft_strlen(temp) - 1] = '\0';
		cub->textures->w_texture = mlx_xpm_file_to_image(cub->mlx, temp, \
			&cub->textures->w_texture_width, &cub->textures->w_texture_height);
		if (!cub->textures->w_texture)
		{
			free(temp);
			printf("Error\nCouldn't load textures\n");
			protect_pars(line, cub);
		}
		free(temp);
	}
}

void	pars_e(char *line, int *i, t_cub *cub)
{
	char	*temp;

	if (ft_strncmp(line, "EA ", 3) == 0)
	{
		*i += 2;
		while (line[*i] == ' ')
			*i += 1;
		temp = ft_strdup(line + *i);
		if (!temp)
			protect_pars(line, cub);
		temp[ft_strlen(temp) - 1] = '\0';
		cub->textures->e_texture = mlx_xpm_file_to_image(cub->mlx, temp, \
			&cub->textures->e_texture_width, &cub->textures->e_texture_height);
		if (!cub->textures->e_texture)
		{
			free(temp);
			printf("Error\nCouldn't load textures\n");
			protect_pars(line, cub);
		}
		free(temp);
	}
}

int	pars_textures(char *line, t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[j] == ' ')
		j++;
	pars_n(line + j, &i, cub);
	pars_s(line + j, &i, cub);
	pars_w(line + j, &i, cub);
	pars_e(line + j, &i, cub);
	if (pars_color(line + j, &i, cub) == -1)
	{
		free(line);
		exit(EXIT_FAILURE);
	}
	if (i != 0)
		return (1);
	else
		return (0);
}
