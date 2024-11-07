/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earaujo <earaujo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 10:41:28 by earaujo           #+#    #+#             */
/*   Updated: 2024/05/03 11:23:03 by earaujo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	little_atoi(char c)
{
	int	nb;

	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (0);
	if (c == ' ')
		return (2);
	nb = (int)c - 48;
	return (nb);
}

int	is_map(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != 32 && line[i] != '\n' && line[i] != 'S' \
			&& (line[i] < 48 || line[i] > 57) && line[i] != 'N' \
				&& line[i] != 'W' && line[i] != 'E')
			return (0);
		i++;
	}
	return (1);
}

double	clamp(double value, double min, double max)
{
	if (value < min)
		return (min);
	if (value > max)
		return (max);
	return (value);
}

float	fix_ang(float ang)
{
	if (ang < 0)
		return (ang + 2 * PI);
	if (ang > 2 * PI)
		return (ang - 2 * PI);
	return (ang);
}

float	degree_to_radian(int ang)
{
	return (ang * (PI / 180.0));
}
