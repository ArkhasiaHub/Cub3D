/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earaujo <earaujo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:56:37 by earaujo           #+#    #+#             */
/*   Updated: 2024/04/01 15:47:25 by earaujo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define LINE_SEP '\n'

char	*get_next_line(int fd);
int		ft_strlen_gnl(char *str);
int		ft_strchr_gnl(const char *s, int c);
char	*ft_strdup_nl(char const *s, int start, int stop);
char	*ft_strdup_gnl(const char *s);
char	*ft_str_add(char *s1, char *s2, int size);

#endif
