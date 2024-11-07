/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_floor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earaujo <earaujo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 13:20:38 by earaujo           #+#    #+#             */
/*   Updated: 2024/05/07 13:40:31 by earaujo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	all_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < 48 || str[i] > 57)
			return (0);
		i++;
	}
	return (1);
}

int	pars_red_f(char *line, int *i, t_cub *cub, int *r)
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

int	pars_green_f(t_cub *cub, char *line, int *i, int *g)
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

int	pars_blue_f(t_cub *cub, char *line, int *i, int *b)
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

int	pars_f(char *line, int *i, t_cub *cub)
{
	int		r;
	int		g;
	int		b;

	if (pars_red_f(line, i, cub, &r) == -1)
		return (-1);
	if (pars_green_f(cub, line, i, &g) == -1)
		return (-1);
	*i += 1;
	if (pars_blue_f(cub, line, i, &b) == -1)
		return (-1);
	cub->textures->color_f = (r << 16) | (g << 8) | b;
	cub->textures->is_f = true;
	return (0);
}
