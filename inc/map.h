/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu-chen <yu-chen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:42:23 by yu-chen           #+#    #+#             */
/*   Updated: 2024/05/03 15:26:21 by yu-chen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H

# define MAP_H

# include "../libft/inc/get_next_line.h"
# include <stdlib.h>

typedef struct s_lay
{
	int	n_row;
	int	n_col;
	int	n_exit;
	int	n_pl;
	int	n_gh;
	int	n_collect;
}		t_lay;

typedef struct s_err
{
	int	inv_rowlen;
	int	inv_char;
	int	inv_n_players;
	int	inv_n_ghosts;
	int	inv_n_collect;
	int	inv_n_exits;
	int	inv_borders;
}		t_err;

t_lay	ft_newlayout(void);

t_err	ft_newmap_error(void);

int		ft_print_map_error(t_lay *lay, t_err *map_err, char **map_str);

void	ft_readlayout(int fd, t_err *map_err, t_lay *lay, char **map_str);

void	ft_checklayout(char *line, t_err *map_err, t_lay *lay, int is_last);

int		error_msg_params(char *msg, char **map_str);

#endif