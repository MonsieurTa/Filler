/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <wta@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 14:40:44 by wta               #+#    #+#             */
/*   Updated: 2018/11/15 00:39:04 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	del_tab(char **tab, int len)
{
	int	i;

	i = 0;
	if (tab)
	{
		while (i < len)
		{
			free(tab[i]);
			tab[i] = NULL;
			i++;
		}
		free(tab);
		tab = NULL;
	}
}

char		**ft_strsplit(char const *s, char c)
{
	char	**split;
	size_t	wdcount;
	int		i;

	if (s && c)
	{
		wdcount = ft_word_count(s, c);
		if (!(split = (char**)malloc(sizeof(char*) * (wdcount + 1))))
			return (NULL);
		i = 0;
		while (*s)
		{
			if (*s != c)
			{
				if ((split[i++] = ft_wdcpy(s, c)) == NULL)
				{
					del_tab(split, --i);
					return (NULL);
				}
			}
			s = (*s != c) ? s + ft_word_len(s, c) : s + 1;
		}
		split[i] = 0;
	}
	return ((s && c) ? split : NULL);
}
