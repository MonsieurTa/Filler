/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <wta@student.41.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 00:59:07 by wta               #+#    #+#             */
/*   Updated: 2018/12/22 17:50:21 by wta              ###   ########.fr       */
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
	if (y < info->map.height && x < info->map.width)
		return (1);
	return (0);
}

int	check_piece_on_map(t_info *info, int x, int y)
{
	int	stack;
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
					col + x, row + y) == 0)
				return (0);
			if (info->piece.piece[row][col] == '*'
			&& info->map.map[row + y][col + x] != info->player
			&& info->map.map[row + y][col + x] != '.')
				return (0);
			if (info->piece.piece[row][col] == '*'
			&& info->map.map[row + y][col + x] == info->player)
				stack++;
			col++;
		}
		row++;
	}
	return (stack == 1);
}

t_pos	set_delta_aim(t_info *info, int x, int y)
{
	t_pos	delta;

	delta.x = ft_abs(info->new_enemy.x - x);
	delta.y = ft_abs(info->new_enemy.y - y);
	return (delta);
}

void	set_delta(t_info *info, t_lst_pos *node, int dx, int dy)
{
	t_pos	delta;

	delta.x = dx;
	delta.y = dy;
	if (node->closest.x == -1)
		node->closest = delta;
	else if (dx <= node->closest.x && dy <= node->closest.y)
		node->closest = delta;
}

void	set_delta_closest(t_info *info, t_lst_pos *node, int x, int y)
{
	t_pos	delta;
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
					set_delta(info, node, ft_abs(col - x - 1), ft_abs(row - y));
				if (col < info->map.width - 1 && info->map.map[row][col + 1] == '.')
					set_delta(info, node, ft_abs(col - x + 1), ft_abs(row - y));
				if (row > 0 && info->map.map[row - 1][col] == '.')
					set_delta(info, node, ft_abs(col - x), ft_abs(row - y - 1));
				if (row < info->map.height - 1 && info->map.map[row + 1][col] == '.')
					set_delta(info, node, ft_abs(col - x), ft_abs(row - y + 1));
			}
				//node->closest = set_delta(info, node, ft_abs(col - x), ft_abs(row - y));
			col++;
		}
		row++;
	}
}

t_pos	init_delta(void)
{
	t_pos	delta;

	delta.x = -1;
	delta.y = -1;
	return (delta);
}

void	set_closest_delta(t_lst_pos *node, t_pos *delta)
{
	node->closest = *delta;
}

void	find_closest(t_info *info, t_lst_pos *node, int x, int y)
{
	char	**map;
	int		row;
	int		col;
	t_pos	delta;

	map = info->map.map;
	node->closest = init_delta();
	row = 0;
	while (row < info->piece.height)
	{
		col = 0;
		while (col < info->piece.width)
		{
			if (row + y < info->map.height && col + x < info->map.width
			&& info->map.map[row + y][col + x] == info->player
			&& info->piece.piece[row][col] == '*')
				break ;
			col++;
		}
		row++;
	}
	set_delta_closest(info, node, col + x, row + y);
}

int	parse_map(t_info *info)
{
	t_lst_pos	*node;
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
				node = lst_newnode(col, row);
				find_closest(info, node, col, row);
				push_front(&info->lst, node);
			}
			col++;
		}
		row++;
	}
	return (info->lst != NULL);
}
