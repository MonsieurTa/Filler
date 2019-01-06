/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_pos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <wta@student.41.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 09:16:35 by wta               #+#    #+#             */
/*   Updated: 2019/01/06 20:44:52 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "filler.h"

t_lst_pos	*lst_newnode(int x, int y)
{
	t_lst_pos	*node;

	if ((node = ft_memalloc(sizeof(t_lst_pos))) == NULL)
		return (NULL);
	node->next = NULL;
	node->pos.x = x;
	node->pos.y = y;
	return (node);
}

void		push_front(t_lst_pos **lst, t_lst_pos *node)
{
	if (*lst && node)
	{
		node->next = *lst;
		*lst = node;
	}
	else if (node)
		*lst = node;
}

void		rm_lst(t_lst_pos *lst)
{
	t_lst_pos	*tmp;

	if (lst)
	{
		while (lst)
		{
			tmp = lst;
			lst = lst->next;
			free(tmp);
			tmp = NULL;
		}
	}
}
