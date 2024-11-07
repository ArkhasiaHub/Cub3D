/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earaujo <earaujo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:23:53 by earaujo           #+#    #+#             */
/*   Updated: 2024/04/01 15:47:04 by earaujo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/conversion.h"

static size_t	find_size(int n)
{
	size_t	size;

	size = 1;
	if (n < 0)
	{
		size++;
		if (n < -9)
			size++;
		n = -(n / 10);
	}
	while (n >= 10)
	{
		size++;
		n /= 10;
	}
	return (size);
}

static void	fill_str(char *str, int n, int size, int sign)
{
	while (--size >= sign)
	{
		if (n < 0)
		{
			str[size] = -(n % 10) + '0';
			n = -(n / 10);
		}
		else
		{
			str[size] = (n % 10) + '0';
			n /= 10;
		}
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	size;
	int		sign;

	size = find_size(n);
	str = (char *) malloc ((size + 1) * sizeof(char));
	if (!str)
		return (NULL);
	sign = 0;
	if (n < 0)
		sign = 1;
	str[size] = '\0';
	fill_str(str, n, size, sign);
	if (sign == 1)
		str[0] = '-';
	return (str);
}
