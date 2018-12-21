/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 15:34:22 by wta               #+#    #+#             */
/*   Updated: 2018/12/21 00:42:00 by wta              ###   ########.fr       */
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
