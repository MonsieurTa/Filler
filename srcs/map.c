/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 15:34:22 by wta               #+#    #+#             */
/*   Updated: 2018/12/22 00:15:53 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "filler.h"

int	create_map(t_info *info)
{
	char	*needle;
	char	*line;
	int		ret;
	int		idx;

	if ((info->map.map = ft_memalloc(sizeof(char*) * (info->map.height + 1))) == NULL)
		return (0);
	if (get_next_line(0, &line) <= 0)
		return (ft_mapndel(info->map.map, -1));
	ft_strdel(&line);
	ret = 1;
	idx = 0;
	while (ret == 1 && idx < info->map.height)
	{
		if (get_next_line(0, &line) <= 0
		|| (needle = ft_strchr(line, ' ')) == NULL
		|| (info->map.map[idx] = ft_strdup(needle + 1)) == NULL)
			ret = 0;
		ft_strdel(&line);
		idx++;
	}
	if (ret == 0)
		return (ft_mapndel(info->map.map, idx - 1));
	return (ret);
}

void	set_new_enemy(t_pos *new_enemy, int x, int y)
{
	new_enemy->x = x;
	new_enemy->y = y;
}

int	compare_map(t_info *info)
{
	char	*tmp;
	char	*line;
	char	*needle;
	int		ret;
	int		x;
	int		y;

	line = NULL;
	ret = 1;
	y = 0;
	if (get_next_line(0, &line) <= 0)
		return (ft_mapndel(info->map.map, -1));
	ft_strdel(&line);
	while (ret == 1 && y < info->map.height)
	{
		x = 0;
		if (get_next_line(0, &line) <= 0)
			return (0);
		if ((needle = ft_strchr(line, ' ')) != NULL)
		{
			while (ret == 1 && x < info->map.width)
			{
				if (needle[x + 1] == info->enemy
				&& info->map.map[y][x] != info->enemy)
					set_new_enemy(&info->new_enemy, x, y);
				x++;
			}
		}
		else
			ret = 0;
		tmp = info->map.map[y];
		if ((info->map.map[y] = ft_strdup(needle + 1)) == NULL)
			ret = 0;
		free(tmp);
		ft_strdel(&line);
		y++;
	}
	if (ret == 0)
		return (ft_mapndel(info->map.map, y - 1));
	return (ret);
}
