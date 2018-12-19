/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <wta@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 14:50:32 by wta               #+#    #+#             */
/*   Updated: 2018/08/09 12:27:54 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*ptr;
	size_t			len;

	ptr = NULL;
	len = size;
	if (!(ptr = (unsigned char*)malloc(size)))
		return (NULL);
	while (len--)
		*ptr++ = 0;
	return ((void*)ptr - size);
}
