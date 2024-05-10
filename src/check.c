/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu-chen <yu-chen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:48:32 by yu-chen           #+#    #+#             */
/*   Updated: 2024/05/10 14:28:21 by yu-chen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/check.h"

void	find_player(char **map, int *i, int *j)
{
	int	x;
	int	y;

	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == 'P')
			{
				*i = x;
				*j = y;
			}
			y++;
		}
		x++;
	}
}

void	flood_fill(char **map, t_lay *lay, int i, int j)
{
	if (i < 0 || j < 0 || i >= lay->n_row || j >= lay->n_col)
		return ;
	if (lay->n_collect == 0 && lay->n_exit == 0)
		return ;
	if (map[i][j] == 'C')
		lay->n_collect--;
	map[i][j] = '1';
	if (map[i + 1][j] != '1' && map[i + 1][j] != 'E' && map[i + 1][j] != '\0')
		flood_fill(map, lay, i + 1, j);
	if (map[i][j + 1] != '1' && map[i][j + 1] != 'E' && map[i][j + 1] != '\0')
		flood_fill(map, lay, i, j + 1);
	if (map[i - 1][j] != '1' && map[i - 1][j] != 'E' && map[i - 1][j] != '\0')
		flood_fill(map, lay, i - 1, j);
	if (map[i][j - 1] != '1' && map[i][j - 1] != 'E' && map[i][j - 1] != '\0')
		flood_fill(map, lay, i, j - 1);
	return ;
}

int	check_map_path(char **map, t_lay *lay)
{
	char	**map_bak;
	int		i;
	int		j;
	t_lay	new_lay;

	new_lay = ft_newlayout();
	new_lay.n_collect = lay->n_collect;
	new_lay.n_exit = lay->n_exit;
	new_lay.n_col = lay->n_col;
	new_lay.n_row = lay->n_row;
	map_bak = ft_dup_matrix(map);
	find_player(map_bak, &i, &j);
	flood_fill(map_bak, &new_lay, i, j);
	ft_free_matrix(&map_bak);
	if (new_lay.n_collect)
	{
		ft_free_matrix(&map);
		error_msg_params("Invalid Path!", map);
	}
	return (0);
}

char	**check_params(int argc, char **argv, t_lay *lay)
{
	int	fd;

	if (argc != 2)
		error_msg_params("Invalid number of arguments!", NULL);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error_msg_params("File not found!", NULL);
	if (ft_strrncmp(argv[1], ".ber", 4))
		error_msg_params("Invalid file type, use .ber!", NULL);
	return (check_map(fd, lay));
}

char	**check_map(int fd, t_lay *lay)
{
	char	*map_str;
	char	**map;
	t_err	map_err;

	map_str = NULL;
	map = NULL;
	map_err = ft_newmap_error();
	*lay = ft_newlayout();
	ft_readlayout(fd, &map_err, lay, &map_str);
	ft_print_map_error(lay, &map_err, &map_str);
	map = ft_split(map_str, '\n');
	free(map_str);
	if (!map)
		error_msg_params("Memory allocation error!", NULL);
	return (map);
}
