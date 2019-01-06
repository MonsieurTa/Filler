/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <wta@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 21:02:40 by wta               #+#    #+#             */
/*   Updated: 2018/11/05 15:04:51 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dest;
	size_t	size;

	size = ft_strlen(s1);
	if (!(dest = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	*(dest + size) = 0;
	while (*s1)
		*dest++ = *s1++;
	return (dest - size);
}
