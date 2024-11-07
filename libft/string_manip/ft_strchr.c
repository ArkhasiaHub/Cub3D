/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earaujo <earaujo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:12:39 by earaujo           #+#    #+#             */
/*   Updated: 2024/04/01 15:50:04 by earaujo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	if (s[0] == (unsigned char)c)
		return ((char *)s);
	while (*s != '\0')
	{
		s++;
		if (*s == (unsigned char)c)
			return ((char *)s);
	}
	return (0);
}
