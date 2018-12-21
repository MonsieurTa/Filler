/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <wta@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 15:33:58 by wta               #+#    #+#             */
/*   Updated: 2018/12/21 00:42:47 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "filler.h"

int	is_valid_piece_line(char *line)
{
	char	c;
	int		idx;

	if (line)
	{
		idx = 0;
		while (line[idx])
		{
			c = line[idx];
			if (c != 'X' && c != 'O' && c != '.' && c != '*')
				return (0);
			idx++;
		}
		return (1);
	}
	return (0);
}

int	check_piece_line(t_info *info, char *line, int y)
{
	char	*seeker;
	int		ret;

	ret = 1;
	if (((seeker = ft_str_char_skip(line, ' ')) == NULL)
	|| (info->piece.piece[y] = ft_strdup(seeker)) == NULL)
		ret = 0;
	if (is_valid_piece_line(info->piece.piece[y]) == 0)
		return (0);
	if (y >= 1 && ft_strlen(info->piece.piece[y]) != ft_strlen(info->piece.piece[y - 1]))
		ret = 0;
	return (ret);
}

int	get_piece(t_info *info, int width, int height)
{
	char	*line;
	char	*seeker;
	int		ret;
	int		y;

	line = NULL;
	ret = (width != 0 && height != 0) ? 1 : 0;
	if (width != 0 && height != 0)
	{
		if ((info->piece.piece = ft_memalloc(sizeof(char*) * (height + 1))) == NULL)
			return (0);
		y = -1;
		while (ret == 1 && ++y < height)
		{
			if (get_next_line(0, &line) <= 0)
				return (ft_mapndel(info->piece.piece, y - 1));
			ret = check_piece_line(info, line, y);
			ft_strdel(&line);
		}
		if (ret == 0)
			return (ft_mapndel(info->piece.piece, y - 1));
	}
	return (ret);
}

int	parse_piece(t_info *info)
{
	char	**split;
	t_piece	*piece_ptr;
	char	*line;
	char	ret;

	ret = 0;
	line = NULL;
	if (get_next_line(0, &line) <= 0)
		return (ret);
	if ((split = ft_strsplit(line, ' ')) != NULL)
	{
		if (ft_strcmp("Piece", split[0]) == 0)
		{
			piece_ptr = &info->piece;
			piece_ptr->height = ft_atoi(split[1]);
			piece_ptr->width = ft_atoi(split[2]);
			ret = get_piece(info, piece_ptr->width, piece_ptr->height);
		}
		ft_splitdel(split);
	}
	ft_strdel(&line);
	return (ret);
}
