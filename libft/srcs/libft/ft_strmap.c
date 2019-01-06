/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <wta@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 18:29:23 by wta               #+#    #+#             */
/*   Updated: 2018/11/05 14:57:33 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	len;
	char	*new;

	new = NULL;
	if (s)
	{
		len = ft_strlen(s);
		if (!(new = (char*)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		*(new + len) = 0;
		while (*s)
			*new++ = (*f)(*s++);
		return (new - len);
	}
	else
		return (NULL);
}
