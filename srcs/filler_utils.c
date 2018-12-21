/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 15:31:34 by wta               #+#    #+#             */
/*   Updated: 2018/12/20 16:47:15 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"

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
	}
}

int	ft_mapndel(char **split, int n)
{
	while (n >= 0)
	{
		ft_strdel(&split[n]);
		n--;
	}
	free(split);
	split = NULL;
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
