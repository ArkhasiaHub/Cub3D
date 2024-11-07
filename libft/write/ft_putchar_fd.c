/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earaujo <earaujo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:40:29 by earaujo           #+#    #+#             */
/*   Updated: 2024/04/01 15:50:55 by earaujo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/write.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
