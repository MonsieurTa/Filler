/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 10:16:09 by wta               #+#    #+#             */
/*   Updated: 2018/12/19 15:32:23 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

typedef struct	s_info
{
	char	player;
	int		width;
	int		height;
}				t_info;

void	init_info(t_info *info);
int		get_player(t_info *info);
int		get_map_info(t_info *info);
void	ft_splitdel(char **split);

#endif
