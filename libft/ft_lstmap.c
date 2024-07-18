/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:30:27 by qhauuy            #+#    #+#             */
/*   Updated: 2023/11/11 17:12:47 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	void	*new_content;
	t_list	*new_elem;

	if (f == NULL || del == NULL)
		return (NULL);
	result = NULL;
	while (lst)
	{
		new_content = (*f)(lst->content);
		new_elem = ft_lstnew(new_content);
		if (new_elem == NULL)
		{
			ft_lstclear(&result, del);
			del(new_content);
			return (NULL);
		}
		ft_lstadd_back(&result, new_elem);
		lst = lst->next;
	}
	return (result);
}
