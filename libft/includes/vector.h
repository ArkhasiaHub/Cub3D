/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earaujo <earaujo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 12:20:29 by earaujo           #+#    #+#             */
/*   Updated: 2024/04/01 15:47:37 by earaujo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <stdlib.h>

typedef struct s_vector
{
	size_t			elemsize;
	size_t			capacity;
	void			*array;
	unsigned char	allocated;
}	t_vector;

int		vector_init(t_vector **vec, size_t elemsize, size_t initial_capacity);
void	*vector_get_at(const t_vector *vec, size_t index);
int		vector_resize(t_vector **vec, size_t new_capacity);
void	free_vector(t_vector *vec);

#endif
