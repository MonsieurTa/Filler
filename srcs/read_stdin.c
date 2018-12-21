/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_stdin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <wta@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 16:36:22 by wta               #+#    #+#             */
/*   Updated: 2018/12/21 10:24:44 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "filler.h"

int	read_stdin(t_info *info)
{
	int ret;
	ret = get_player(info);
	ret = get_map_info(info);
	ret = create_map(info);
	ret = parse_piece(info);
	return (ret);
}
