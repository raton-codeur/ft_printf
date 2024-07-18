/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:30:14 by qhauuy            #+#    #+#             */
/*   Updated: 2023/11/08 10:32:51 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*elem;
	t_list	*elem_next;

	if (lst == NULL || *lst == NULL || del == NULL)
		return ;
	elem = *lst;
	*lst = NULL;
	while (elem)
	{
		elem_next = elem->next;
		ft_lstdelone(elem, del);
		elem = elem_next;
	}
}
