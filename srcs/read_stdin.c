/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_stdin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <wta@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 16:36:22 by wta               #+#    #+#             */
/*   Updated: 2019/01/08 08:30:58 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "filler.h"

int	read_stdin(t_info *info)
{
	int ret;

	ret = get_player(info);
	if (ret == 0)
		ft_putstr_fd("get_player error\n", 2);
	if (ret == 1)
		ret = get_map_info(info);
	else
		ft_putstr_fd("get_map_info error\n", 2);
	if (ret == 1 && info->map.map != NULL)
		compare_map(info);
	else if (ret == 1)
		ret = create_map(info);
	else
		ft_putstr_fd("compare_map / create_map error\n", 2);
	if (ret == 1)
		ret = parse_piece(info);
	else
		ft_putstr_fd("parse_piece error\n", 2);
	return (ret);
}
