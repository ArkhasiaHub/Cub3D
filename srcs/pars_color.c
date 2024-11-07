/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earaujo <earaujo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 12:26:58 by earaujo           #+#    #+#             */
/*   Updated: 2024/05/13 09:28:55 by earaujo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	pars_color(char *line, int *i, t_cub *cub)
{
	if (ft_strncmp(line, "F ", 2) == 0)
	{
		if (pars_f(line, i, cub) == -1)
			return (-1);
	}
	if (ft_strncmp(line, "C ", 2) == 0)
	{
		if (pars_c(line, i, cub) == -1)
			return (-1);
	}
	return (0);
}
