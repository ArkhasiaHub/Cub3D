/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earaujo <earaujo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 08:44:50 by earaujo           #+#    #+#             */
/*   Updated: 2024/04/01 15:48:43 by earaujo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/list.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next;

	if (!*lst)
		return ;
	if (!del)
		return ;
	while ((*lst)->next)
	{
		next = (*lst)->next;
		ft_lstdelone(*lst, (*del));
		*lst = next;
	}
	ft_lstdelone(*lst, (*del));
	*lst = NULL;
}
