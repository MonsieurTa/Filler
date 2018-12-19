/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wdcpy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <wta@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 15:41:16 by wta               #+#    #+#             */
/*   Updated: 2018/11/05 14:54:02 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_wdcpy(const char *s, char c)
{
	char	*dst;
	size_t	wdlen;

	dst = NULL;
	wdlen = 0;
	if (s)
	{
		wdlen = ft_word_len(s, c);
		if (!(dst = (char*)malloc(sizeof(char) * (wdlen + 1))))
			return (NULL);
		while (*s != c && *s != 0)
			*dst++ = *s++;
		*dst = 0;
	}
	return (dst - wdlen);
}
