/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earaujo <earaujo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 10:12:26 by earaujo           #+#    #+#             */
/*   Updated: 2024/05/06 12:57:57 by earaujo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_args(int argc, char *argv[])
{
	int	fd;

	if (argc != 2)
	{
		printf("Error\nBad number of arguments\n");
		exit(EXIT_FAILURE);
	}
	if (ft_strncmp(argv[1] + (ft_strlen(argv[1]) - 4), ".cub", 4) != 0)
	{
		printf("Error\nBad extension\n");
		exit(EXIT_FAILURE);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf("Error\nBad file path\n");
		exit(EXIT_FAILURE);
	}
	return (fd);
}

int	main(int argc, char *argv[])
{
	int		fd;
	t_cub	cub;

	fd = check_args(argc, argv);
	ft_memset(&cub, '\0', sizeof(t_cub));
	init_cub(&cub, fd);
	cub.mlx = mlx_init();
	if (!cub.mlx)
	{
		free(cub.textures);
		exit(EXIT_FAILURE);
	}
	init_and_read(fd, &cub);
	free_all(&cub);
}
