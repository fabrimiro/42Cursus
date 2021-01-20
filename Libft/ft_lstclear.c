/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmiranda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 10:59:01 by fmiranda          #+#    #+#             */
/*   Updated: 2021/01/20 10:59:03 by fmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*clr;

	if (!del || !*lst || !*lst)
		return ;
	while (lst && *lst)
	{
		clr = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = clr;
	}
}
