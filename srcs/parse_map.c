/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <wta@student.41.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 00:59:07 by wta               #+#    #+#             */
/*   Updated: 2018/12/21 10:56:00 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	parse_map(t_info *info)
{
	int	row;
	int	col;
	
	row = 0;
	while (row < info->map.height)
	{
		col = 0;
		while (col < info->map.width)
		{
			if (check_piece_on_map(info, col, row) == 1)
			{
				push_front(&info->lst, lst_newnode(col, row));
			}
			col++;
		}
		row++;
	}
	return (info->lst != NULL);
}
