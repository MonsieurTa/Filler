/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 10:17:57 by wta               #+#    #+#             */
/*   Updated: 2019/01/08 07:37:54 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../libft/includes/ft_printf.h"
#include "filler.h"

void	init_info(t_info *info)
{
	info->player = 0;
	(&info->map)->width = 0;
	(&info->map)->height = 0;
	info->lst = NULL;
	info->map.map = NULL;
}

int		get_player(t_info *info)
{
	char	*line;

	line = NULL;
	if (info->player != 0)
		return (1);
	if (get_next_line(0, &line) <= 0)
		return (0);
	if (ft_strnstr(line, "$$$ exec", 8) != NULL)
	{
		if (ft_strstr(line, "p1"))
			info->player = 'O';
		else if (ft_strstr(line, "p2"))
			info->player = 'X';
		info->enemy = (info->player == 'O') ? 'X' : 'O';
	}
	ft_strdel(&line);
	return (info->player == 'O' || info->player == 'X');
}

int		check_map_info(t_map *curr, t_map *parsed)
{
	int	ret;

	ret = 1;
	if ((curr->width != 0 && curr->width == parsed->width)
	&& (curr->height != 0 && curr->height == parsed->height))
		return (ret);
	if (curr->width == 0 && parsed->width != 0)
		curr->width = parsed->width;
	else
		ret = 0;
	if (curr->height == 0 && parsed->height != 0)
		curr->height = parsed->height;
	else
		ret = 0;
	return (ret);
}

int		get_map_info(t_info *info)
{
	t_map	parsed;
	char	**split;
	char	*line;
	int		ret;

	line = NULL;
	ret = 0;
	if (get_next_line(0, &line) <= 0)
		return (ret);
	if ((split = ft_strsplit(line, ' ')) != NULL)
	{
		if (split[0] != NULL && (ft_strcmp("Plateau", split[0])) == 0
		&& split[1] != NULL && split[2] != NULL)
		{
			parsed.width = ft_atoi(split[2]);
			parsed.height = ft_atoi(split[1]);
			ret = check_map_info(&info->map, &parsed);
		}
		ft_splitdel(split);
	}
	ft_strdel(&line);
	return (ret);
}
