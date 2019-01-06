/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 11:02:38 by wta               #+#    #+#             */
/*   Updated: 2019/01/06 11:05:16 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/ft_printf.h"
#include "filler.h"

int		is_valid_pos(t_info *info, char c, int x, int y)
{
	if ((y >= info->map.height || x >= info->map.width)
	&& c == '*')
		return (0);
	else if ((y >= info->map.height || x >= info->map.width)
	&& c == '.')
		return (1);
	else if ((y < 0 || x < 0) && c == '*')
		return (0);
	else if ((y < 0 || x < 0) && c == '.')
		return (1);
	return (1);
}

int		check_piece_on_map(t_info *info, int x, int y, int stack)
{
	int	row;
	int	col;

	row = -1;
	stack = 0;
	while (stack <= 1 && ++row < info->piece.height)
	{
		col = -1;
		while (stack <= 1 && ++col < info->piece.width)
		{
			if ((is_valid_pos(info, info->piece.piece[row][col],
			col - info->piece.shift_x + x, row - info->piece.shift_y + y) == 0)
			|| (info->piece.piece[row][col] == '*'
			&& info->map.map[row - info->piece.shift_y + y]
			[col - info->piece.shift_x + x] != info->player
			&& info->map.map[row - info->piece.shift_y + y]
			[col - info->piece.shift_x + x] != '.'))
				return (0);
			if (info->piece.piece[row][col] == '*'
			&& info->map.map[row - info->piece.shift_y + y]
			[col - info->piece.shift_x + x] == info->player)
				stack++;
		}
	}
	return (stack == 1);
}

void	set_aim(t_lst_pos *node, int dx, int dy)
{
	int	delta;

	delta = ft_pow(dx + dy, 2);
	if (node->closest_enemy == -1)
		node->closest_enemy = delta;
	else if (delta < node->closest_enemy)
		node->closest_enemy = delta;
}
