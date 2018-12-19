/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 10:17:57 by wta               #+#    #+#             */
/*   Updated: 2018/12/19 17:14:20 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "../libft/includes/libft.h"

void	init_info(t_info *info)
{
	info->player = 0;
	info->width = 0;
	info->height = 0;
}

int		get_player(t_info *info)
{
	char	*line;
	char	*needle;

	line = NULL;
	needle = NULL;
	if (info->player != 0)
		return (1);
	if (get_next_line(0, &line) <= 0)
		return (0);
	if ((needle = ft_strnstr(line, "$$$ exec p", 10)) != NULL)
	{
		if (needle[10] == '1' && needle[11] == ' ')
			info->player = 'O';
		else if (needle[10] == '2' && needle[11] == ' ')
			info->player = 'X';
		ft_strdel(&line);
	}
	return (info->player == 'O' || info->player == 'X');
}

int	get_map_info(t_info *info)
{
	char	**split;
	char	*line;

	line = NULL;
	if (info->width != 0 && info->height != 0)
		return (1);
	if (get_next_line(0, &line) <= 0)
		return (0);
	if ((split = ft_strsplit(line, ' ')) != NULL)
	{
		if (ft_strcmp("Plateau", split[0]) == 0)
		{
			/*
			 * TODO
			 */
		}
		ft_splitdel(split);
	}
	ft_strdel(&line);
	return (0);
}
