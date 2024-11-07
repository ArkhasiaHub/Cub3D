/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earaujo <earaujo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 11:18:19 by earaujo           #+#    #+#             */
/*   Updated: 2024/04/01 15:47:19 by earaujo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSION_H
# define CONVERSION_H

# include <stdlib.h>
# include "./is_type.h"

int		ft_atoi(const char *nptr);
char	*ft_itoa(int n);
long	ft_atol(const char *nptr);

#endif
