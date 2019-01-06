/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 15:31:34 by wta               #+#    #+#             */
/*   Updated: 2019/01/06 22:35:59 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "filler.h"

void	ft_splitdel(char **split)
{
	int	idx;

	if (split)
	{
		idx = 0;
		while (split[idx])
		{
			ft_strdel(&split[idx]);
			idx++;
		}
		free(split);
		split = NULL;
	}
}

int		ft_mapndel(char **split, int n)
{
	int	i;

	i = 0;
	if (split)
	{
		while (split[i] != NULL && i < n)
		{
			ft_strdel(&split[i]);
			i++;
		}
		free(split);
		split = NULL;
	}
	return (0);
}

char	*ft_str_char_skip(char *str, char c)
{
	int	idx;

	if (str)
	{
		idx = 0;
		while (str[idx] != '\0')
		{
			if (str[idx] != c)
				break ;
			idx++;
		}
		return (str + idx);
	}
	return (NULL);
}

t_pos	lowest_node(t_lst_pos *lst)
{
	t_lst_pos	tmp;

	tmp = *lst;
	while (lst)
	{
		if (lst->pos.y < tmp.pos.y)
			tmp = *lst;
		lst = lst->next;
	}
	return (tmp.pos);
}

int		get_player_lowest(t_info *info)
{
	int	y;

	y = 0;
	while (y < info->map.height)
	{
		if (ft_strchr(info->map.map[y], info->player) != NULL)
			return (y);
		y++;
	}
	return (-1);
}
