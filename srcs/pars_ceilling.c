/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_ceilling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earaujo <earaujo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 09:25:32 by earaujo           #+#    #+#             */
/*   Updated: 2024/05/13 09:32:30 by earaujo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	pars_red_c(char *line, int *i, t_cub *cub, int *r)
{
	char	*temp;
	int		j;

	line[ft_strlen(line) - 1] = '\0';
	*i += 1;
	while (line[*i] == ' ')
		*i += 1;
	j = *i;
	while (ft_isdigit(line[*i]) == 1)
		*i += 1;
	temp = ft_substr(line, j, *i - j);
	if (!temp)
		protect_pars(line, cub);
	*r = ft_atoi(temp);
	if (*r > 255)
	{
		printf("Error\nBad color\n");
		free_map(cub);
		free(temp);
		free_all(cub);
		return (-1);
	}
	free(temp);
	*i += 1;
	return (0);
}

int	pars_green_c(t_cub *cub, char *line, int *i, int *g)
{
	char	*temp;
	int		j;

	j = *i;
	while (ft_isdigit(line[*i]) == 1)
		*i += 1;
	temp = ft_substr(line, j, *i - j);
	if (!temp)
		protect_pars(line, cub);
	*g = ft_atoi(temp);
	if (*g > 255)
	{
		printf("Error\nBad Color\n");
		free_map(cub);
		free(temp);
		free_all(cub);
		return (-1);
	}
	free(temp);
	return (0);
}

int	pars_blue_c(t_cub *cub, char *line, int *i, int *b)
{
	char	*temp;

	temp = ft_substr(line, *i, ft_strlen(line + *i));
	if (!temp)
		protect_pars(line, cub);
	*b = ft_atoi(temp);
	if (*b > 255 || all_digit(temp) == 0)
	{
		printf("Error\nBad Color\n");
		free_map(cub);
		free(temp);
		free_all(cub);
		return (-1);
	}
	free(temp);
	return (0);
}

int	pars_c(char *line, int *i, t_cub *cub)
{
	int		r;
	int		g;
	int		b;

	if (pars_red_c(line, i, cub, &r) == -1)
		return (-1);
	if (pars_green_c(cub, line, i, &g) == -1)
		return (-1);
	*i += 1;
	if (pars_blue_c(cub, line, i, &b) == -1)
		return (-1);
	cub->textures->color_c = (r << 16) | (g << 8) | b;
	cub->textures->is_c = true;
	return (0);
}
