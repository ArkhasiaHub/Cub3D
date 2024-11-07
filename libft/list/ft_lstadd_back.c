/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earaujo <earaujo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:35:37 by earaujo           #+#    #+#             */
/*   Updated: 2024/04/01 15:48:30 by earaujo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/list.h"

void	ft_lstadd_back(t_list **lst, t_list *n)
{
	t_list	*current;

	if (!*lst)
	{
		*lst = n;
		return ;
	}
	current = *lst;
	while (current->next != NULL)
		current = current->next;
	current->next = n;
}
