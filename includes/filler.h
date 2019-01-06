/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 10:16:09 by wta               #+#    #+#             */
/*   Updated: 2019/01/07 00:07:51 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

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
	int		shift_x;
	int		shift_y;
}				t_piece;

typedef struct	s_lst_pos
{
	struct s_lst_pos	*next;
	t_pos				pos;
	int					closest;
	int					closest_enemy;
}				t_lst_pos;

typedef struct	s_info
{
	char		player;
	char		enemy;
	t_map		map;
	t_piece		piece;
	t_pos		new_enemy;
	t_pos		output;
	t_lst_pos	*lst;
}				t_info;

void			init_info(t_info *info);

int				get_player(t_info *info);
int				get_map_info(t_info *info);

int				read_stdin(t_info *info);

int				create_map(t_info *info);
int				compare_map(t_info *info);

int				parse_piece(t_info *info);
int				parse_map(t_info *info);

void			init_delta(t_lst_pos *node);
void			set_delta(t_info *info, t_lst_pos *node, int dx, int dy);
void			set_delta_closest(t_info *info, t_lst_pos *node, int x, int y);
void			set_delta_aim(t_info *info, t_lst_pos *node, int x, int y);

int				is_valid_pos(t_info *info, char c, int x, int y);
int				check_piece_on_map(t_info *info, int x, int y, int stack);
void			set_aim(t_lst_pos *node, int dx, int dy);

char			*ft_str_char_skip(char *str, char c);
void			ft_splitdel(char **split);

t_lst_pos		*lst_newnode(int x, int y);
void			push_front(t_lst_pos **lst, t_lst_pos *node);
int				ft_mapndel(char **split, int n);
void			rm_lst(t_lst_pos *lst);

t_pos			lowest_node(t_lst_pos *lst);
int				get_player_lowest(t_info *info);

#endif
