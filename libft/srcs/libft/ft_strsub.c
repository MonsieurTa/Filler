/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <wta@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 12:06:19 by wta               #+#    #+#             */
/*   Updated: 2018/11/05 14:57:04 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new;

	new = NULL;
	if (s)
	{
		if (!(new = (char*)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		*(new + len) = 0;
		s = s + start;
		start = len;
		while (start--)
			*new++ = *s++;
		return (new - len);
	}
	return (NULL);
}
