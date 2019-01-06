/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 15:34:22 by wta               #+#    #+#             */
/*   Updated: 2019/01/06 22:50:37 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "filler.h"

void	get_first_enemy(t_info *info)
{
	int	y;
	int	x;

	y = 0;
	while (y < info->map.height)
	{
		x = 0;
		while (x < info->map.width)
		{
			if (info->map.map[y][x] == info->enemy)
			{
				info->new_enemy.x = x;
				info->new_enemy.y = y;
				break ;
			}
			x++;
		}
		y++;
	}
}

int		create_map(t_info *info)
{
	char	*needle;
	char	*line;
	int		ret;
	int		idx;

	if ((info->map.map = ft_memalloc(sizeof(char*) * (
						info->map.height + 1))) == NULL)
		return (0);
	if (get_next_line(0, &line) <= 0)
		return (ft_mapndel(info->map.map, info->map.height));
	ft_strdel(&line);
	ret = 1;
	idx = -1;
	while (ret == 1 && ++idx < info->map.height)
	{
		if (get_next_line(0, &line) <= 0
		|| (needle = ft_strchr(line, ' ')) == NULL
		|| (info->map.map[idx] = ft_strdup(needle + 1)) == NULL)
			ret = 0;
		ft_strdel(&line);
	}
	if (ret == 0)
		return (ft_mapndel(info->map.map, idx));
	get_first_enemy(info);
	return (ret);
}

void	set_new_enemy(t_pos *new_enemy, int x, int y)
{
	new_enemy->x = x;
	new_enemy->y = y;
}

int		find_enemy(t_info *info, char *line, int y)
{
	char	*needle;
	char	*tmp;
	int		x;

	x = -1;
	if ((needle = ft_strchr(line, ' ')) != NULL)
	{
		while (++x < info->map.width)
		{
			if (needle[x + 1] == info->enemy
			&& info->map.map[y][x] != info->enemy)
				set_new_enemy(&info->new_enemy, x, y);
		}
		tmp = info->map.map[y];
		if ((info->map.map[y] = ft_strdup(needle + 1)) != NULL)
		{
			ft_strdel(&tmp);
			ft_strdel(&line);
			return (1);
		}
	}
	ft_strdel(&line);
	return (0);
}

int		compare_map(t_info *info)
{
	char	*line;
	char	*needle;
	int		ret;
	int		y;

	line = NULL;
	needle = NULL;
	ret = 1;
	y = -1;
	if (get_next_line(0, &line) <= 0)
		return (ft_mapndel(info->map.map, info->map.height));
	ft_strdel(&line);
	while (ret == 1 && ++y < info->map.height)
	{
		if (get_next_line(0, &line) <= 0)
			return (0);
		if ((find_enemy(info, line, y)) == 0)
			ret = 0;
	}
	return ((ret == 0) ? ft_mapndel(info->map.map, y) : ret);
}
