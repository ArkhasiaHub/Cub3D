/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_begin_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earaujo <earaujo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 13:45:43 by earaujo           #+#    #+#             */
/*   Updated: 2024/05/07 13:56:21 by earaujo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_begin_map(char *line)
{
	int	i;

	i = 0;
	if (line[0] != '\n')
	{
		while (line[i])
		{
			if (line[i] != '0' && line[i] != '1' && \
				line[i] != '\n' && line[i] != ' ' && line[i] != 'N' \
				&& line[i] != 'S' && line[i] != 'W' && line[i] != 'E')
				return (0);
			i++;
		}
	}
	return (1);
}
