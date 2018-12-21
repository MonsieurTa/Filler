/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 18:19:46 by wta               #+#    #+#             */
/*   Updated: 2018/12/21 10:54:21 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/ft_printf.h"
#include "../libft/includes/libft.h"
#include "filler.h"

int	main(void)
{
	t_info	info;

	init_info(&info);
	while (read_stdin(&info) == 1)
	{
		parse_map(&info);
		ft_mapndel(info.map.map, info.map.height);
		ft_mapndel(info.piece.piece, info.piece.height);
		if (info.lst)
		{
			info.output = info.lst->pos;
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
