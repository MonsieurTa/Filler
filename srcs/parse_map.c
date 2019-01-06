/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <wta@student.41.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 00:59:07 by wta               #+#    #+#             */
/*   Updated: 2019/01/06 11:03:16 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/ft_printf.h"
#include "filler.h"

void	set_delta_aim(t_info *info, t_lst_pos *node, int x, int y)
{
	t_pos	coord;

	coord.y = 0;
	while (coord.y < info->piece.height)
	{
		coord.x = 0;
		while (coord.x < info->piece.width)
		{
			if (info->piece.piece[coord.y][coord.x] == '*')
				set_aim(node, ft_abs(x + coord.x - info->new_enemy.x),
						ft_abs(y + coord.y - info->new_enemy.y));
			coord.x++;
		}
		coord.y++;
	}
}

void	set_closest(t_lst_pos *node, int dx, int dy)
{
	int	delta;

	delta = ft_pow(dx + dy, 2);
	if (node->closest == -1)
		node->closest = delta;
	else if (delta < node->closest)
		node->closest = delta;
}

void	set_delta_closest(t_info *info, t_lst_pos *node, int x, int y)
{
	int		row;
	int		col;

	row = -1;
	while (++row < info->map.height)
	{
		col = -1;
		while (++col < info->map.width)
		{
			if (info->map.map[row][col] == info->enemy)
			{
				if (col > 0 && info->map.map[row][col - 1] == '.')
					set_closest(node, ft_abs(col - x - 1), ft_abs(row - y));
				if (col < info->map.width - 1
				&& info->map.map[row][col + 1] == '.')
					set_closest(node, ft_abs(col - x + 1), ft_abs(row - y));
				if (row > 0 && info->map.map[row - 1][col] == '.')
					set_closest(node, ft_abs(col - x), ft_abs(row - y - 1));
				if (row < info->map.height - 1
				&& info->map.map[row + 1][col] == '.')
					set_closest(node, ft_abs(col - x), ft_abs(row - y + 1));
			}
		}
	}
}

void	init_delta(t_lst_pos *node)
{
	node->closest = -1;
	node->closest_enemy = -1;
}

int		parse_map(t_info *info)
{
	t_lst_pos	*node;
	t_pos		pos;
	int			row;
	int			col;

	row = -1;
	while (++row < info->map.height)
	{
		col = -1;
		while (++col < info->map.width)
		{
			if (check_piece_on_map(info, col, row, row) == 1)
			{
				pos.x = col - info->piece.shift_x;
				pos.y = row - info->piece.shift_y;
				node = lst_newnode(pos.x, pos.y);
				init_delta(node);
				set_delta_aim(info, node, pos.x, pos.y);
				set_delta_closest(info, node, pos.x, pos.y);
				push_front(&info->lst, node);
			}
		}
	}
	return (info->lst != NULL);
}
