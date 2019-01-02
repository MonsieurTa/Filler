/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <wta@student.41.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 00:59:07 by wta               #+#    #+#             */
/*   Updated: 2018/12/25 13:54:41 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/ft_printf.h"
#include "filler.h"

int	is_valid_pos(t_info *info, char c, int x, int y)
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

int	check_piece_on_map(t_info *info, int x, int y)
{
	int	stack;
	t_lst_pos	*node;
	t_pos	pos;
	int	row;
	int	col;

	row = 0;
	stack = 0;
	while (stack <= 1 && row < info->piece.height)
	{
		col = 0;
		while (stack <= 1 && col < info->piece.width)
		{
			if (is_valid_pos(info, info->piece.piece[row][col],
			col - info->piece.shift_x + x, row - info->piece.shift_y + y) == 0)
				return (0);
			if (info->piece.piece[row][col] == '*'
			&& info->map.map[row - info->piece.shift_y + y][col - info->piece.shift_x + x] != info->player
			&& info->map.map[row - info->piece.shift_y + y][col - info->piece.shift_x + x] != '.')
				return (0);
			if (info->piece.piece[row][col] == '*'
			&& info->map.map[row - info->piece.shift_y + y][col - info->piece.shift_x + x] == info->player)
				stack++;
			col++;
		}
		row++;
	}
	return (stack == 1);
}

void	set_aim(t_info *info, t_lst_pos *node, int dx, int dy)
{
	int	delta;

	delta = ft_pow(dx + dy, 2);
	if (node->closest_enemy == -1)
		node->closest_enemy = delta;
	else if (delta < node->closest_enemy)
		node->closest_enemy = delta;
}

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
				set_aim(info, node, ft_abs(x + coord.x - info->new_enemy.x),
						ft_abs(y + coord.y - info->new_enemy.y));
			coord.x++;
		}
		coord.y++;
	}
}

void	set_closest(t_info *info, t_lst_pos *node, int dx, int dy)
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

	row = 0;
	while (row < info->map.height)
	{
		col = 0;
		while (col < info->map.width)
		{
			if (info->map.map[row][col] == info->enemy)
			{
				if (col > 0 && info->map.map[row][col - 1] == '.')
					set_closest(info, node, ft_abs(col - x - 1), ft_abs(row - y));
				if (col < info->map.width - 1 && info->map.map[row][col + 1] == '.')
					set_closest(info, node, ft_abs(col - x + 1), ft_abs(row - y));
				if (row > 0 && info->map.map[row - 1][col] == '.')
					set_closest(info, node, ft_abs(col - x), ft_abs(row - y - 1));
				if (row < info->map.height - 1 && info->map.map[row + 1][col] == '.')
					set_closest(info, node, ft_abs(col - x), ft_abs(row - y + 1));
			}
				//node->closest = set_delta(info, node, ft_abs(col - x), ft_abs(row - y));
			col++;
		}
		row++;
	}
}

void	init_delta(t_lst_pos *node)
{
	node->closest = -1;
	node->closest_enemy = -1;
}

int	parse_map(t_info *info)
{
	t_lst_pos	*node;
	t_pos		pos;
	int			row;
	int			col;
	
	row = 0;
	while (row < info->map.height)
	{
		col = 0;
		while (col < info->map.width)
		{
			if (check_piece_on_map(info, col, row) == 1)
			{
				pos.x = col - info->piece.shift_x;
				pos.y = row - info->piece.shift_y;
				node = lst_newnode(pos.x , pos.y);
				init_delta(node);
				set_delta_aim(info, node, pos.x, pos.y);
				set_delta_closest(info, node, pos.x, pos.y);
				push_front(&info->lst, node);
			}
			col++;
		}
		row++;
	}
	return (info->lst != NULL);
}
