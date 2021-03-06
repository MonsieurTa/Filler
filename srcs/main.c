/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 18:19:46 by wta               #+#    #+#             */
/*   Updated: 2019/01/08 08:26:38 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/ft_printf.h"
#include "../libft/includes/libft.h"
#include "filler.h"

t_pos	closest_enemy_node(t_lst_pos *lst, int width, int height)
{
	t_lst_pos	tmp;

	tmp = *lst;
	while (lst)
	{
		if (lst->closest_enemy < tmp.closest_enemy)
		{
			tmp = *lst;
			if (width > 50 && height > 50 && lst->closest <= tmp.closest)
				tmp = *lst;
		}
		lst = lst->next;
	}
	return (tmp.pos);
}

int		are_lower(t_info *info, t_lst_pos *lst)
{
	int	y;

	if ((y = get_player_lowest(info)) > 0)
	{
		while (lst)
		{
			if (lst->pos.y <= y)
				return (1);
			lst = lst->next;
		}
	}
	return (0);
}

t_pos	closest_lowest_node(t_lst_pos *lst)
{
	t_lst_pos	tmp;

	tmp = *lst;
	while (lst)
	{
		if (lst->closest <= tmp.closest)
		{
			tmp = *lst;
			if (lst->pos.y <= tmp.pos.y)
				tmp = *lst;
		}
		lst = lst->next;
	}
	return (tmp.pos);
}

void	choose_algo(t_info *info)
{
	if (info->map.height < 24 && info->map.width < 24
	&& info->player == 'X')
	{
		if (are_lower(info, info->lst) == 1)
			info->output = lowest_node(info->lst);
		else
			info->output = closest_lowest_node(info->lst);
	}
	else
		info->output = closest_enemy_node(info->lst, info->map.width,
			info->map.height);
}

int		main(void)
{
	t_info	info;

	init_info(&info);
	while (read_stdin(&info) == 1)
	{
		parse_map(&info);
		ft_mapndel(info.piece.piece, info.piece.height);
		if (info.lst != NULL)
		{
			choose_algo(&info);
			rm_lst(info.lst);
			info.lst = NULL;
			ft_printf("%d %d\n", info.output.y, info.output.x);
		}
		else
			break ;
	}
	ft_mapndel(info.map.map, info.map.height);
	get_next_line(0, NULL);
	ft_printf("0 0\n");
	return (0);
}
