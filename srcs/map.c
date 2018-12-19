/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 15:34:22 by wta               #+#    #+#             */
/*   Updated: 2018/12/19 15:56:43 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	ft_mapndel(char **split, int n)
{
	while (n >= 0)
	{
		ft_strdel(&str[n]);
		n--;
	}
	free(split);
	split = NULL;
	return (0);
}

int	create_map(t_info *info)
{
	char	*needle;
	char	*line;
	int		idx;
	int		gnl_ret;

	if (info->map == NULL)
		return (1);
	if ((info->map = ft_memalloc(sizeof(char*) * (info->height + 1))) == NULL)
		return (0);
	idx = 0;
	while (idx < info->height)
	{
		if ((gnl_ret = get_next_line(0, &line)) <= 0)
			break ;
		if ((needle = ft_strchr(line, ' ')) == NULL)
			break ;
		if ((info->map[idx] = ft_strdup(needle)) == NULL)
			break ;
		idx++;
	}
	if (gnl_ret <= 0 || needle == NULL || info->map[info->height - 1] == NULL)
		return (ft_mapndel(info->map, idx));
	return (1);
}
