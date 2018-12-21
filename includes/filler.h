/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 10:16:09 by wta               #+#    #+#             */
/*   Updated: 2018/12/21 11:05:10 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

#include <stdio.h>

typedef struct	s_pos
{
	int	x;
	int	y;
}				t_pos;

typedef struct	s_map
{
	char	**map;
	int		width;
	int		height;
}				t_map;

typedef struct	s_piece
{
	char	**piece;
	int		width;
	int		height;
}				t_piece;

typedef struct	s_lst_pos
{
	struct s_lst_pos	*next;
	t_pos				pos;
}				t_lst_pos;

typedef struct	s_info
{
	char		player;
	char		enemy;
	t_map		map;
	t_piece		piece;
	t_pos		output;
	t_lst_pos	*lst;
}				t_info;

void	init_info(t_info *info);
int		get_player(t_info *info);
int		get_map_info(t_info *info);
void	ft_splitdel(char **split);
char	*ft_str_char_skip(char *str, char c);
int		ft_mapndel(char **split, int n);

int		create_map(t_info *info);
int		parse_piece(t_info *info);
int		read_stdin(t_info *info);
int		parse_map(t_info *info);

t_lst_pos	*lst_newnode(int x, int y);
void	push_front(t_lst_pos **lst, t_lst_pos *node);
void		rm_lst(t_lst_pos *lst);
#endif
