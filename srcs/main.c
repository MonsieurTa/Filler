/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 18:19:46 by wta               #+#    #+#             */
/*   Updated: 2018/12/22 17:41:12 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/ft_printf.h"
#include "../libft/includes/libft.h"
#include "filler.h"

t_pos	closest_node(t_lst_pos *lst)
{
	t_lst_pos	tmp;

	if (lst)
	{
		tmp = *lst;
		while (lst)
		{
			if (lst->closest.x != -1 && lst->closest.x <= tmp.closest.x
			&& lst->closest.y != -1  && lst->closest.y <= tmp.closest.y)
				tmp = *lst;
			lst = lst->next;
		}
		return (tmp.pos);
	}
	tmp.pos.x = 0;
	tmp.pos.y = 0;
	return (tmp.pos);
}

t_pos	farest_node(t_lst_pos *lst)
{
	t_lst_pos	tmp;

	if (lst)
	{
		tmp = *lst;
		while (lst)
		{
			if (lst->closest.x >= tmp.closest.x
			&& lst->closest.y >= tmp.closest.y)
				tmp = *lst;
			lst = lst->next;
		}
		return (tmp.pos);
	}
	tmp.pos.x = 0;
	tmp.pos.y = 0;
	return (tmp.pos);
}

int	main(void)
{
	t_info	info;

	init_info(&info);
	while (read_stdin(&info) == 1)
	{
		parse_map(&info);
		ft_mapndel(info.piece.piece, info.piece.height);
		if (info.lst)
		{
			info.output = closest_node(info.lst);
			//info.output = farest_node(info.lst);
			rm_lst(info.lst);
			info.lst = NULL;
			ft_printf("%d %d\n", info.output.y, info.output.x);
		}
		else
			break ;
	}
	ft_printf("0 0\n");
	return (0);
}
