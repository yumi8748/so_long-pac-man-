/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprits.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu-chen <yu-chen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:16:37 by yu-chen           #+#    #+#             */
/*   Updated: 2024/03/14 15:50:06 by yu-chen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game.h"
#include "../minilibx-linux/mlx.h"

void	ft_initsprites(t_game *g)
{
	int	size;

	size = SIZE;
	g->sprites.wall = mlx_xpm_file_to_image(g->id,
			"sprites/Other/Walls/wall.xpm", &size, &size);
	g->sprites.pacfood = mlx_xpm_file_to_image(g->id,
			"sprites/Other/Pacfood/pacdot_food.xpm", &size, &size);
	g->sprites.portal = mlx_xpm_file_to_image(g->id,
			"sprites/Other/Portal/portal.xpm", &size, &size);
	g->sprites.logo = mlx_xpm_file_to_image(g->id,
			"sprites/Other/Logo/logo.xpm", &size, &size);
	g->sprites.pacman = mlx_xpm_file_to_image(g->id,
			"sprites/Pac-Man/pac_closed.xpm", &size, &size);
	g->sprites.black = mlx_xpm_file_to_image(g->id,
			"sprites/Other/Walls/black.xpm", &size, &size);
	if (!g->sprites.wall || !g->sprites.pacfood || !g->sprites.portal
		|| !g->sprites.logo || !g->sprites.pacman || !g->sprites.black)
		err_quit_game(g);
	ft_load_pacdeath(g);
	ft_load_score_font(g);
}

int	free_sprites(t_game *g)
{
	ft_destroy(g, g->sprites.wall);
	ft_destroy(g, g->sprites.pacfood);
	ft_destroy(g, g->sprites.portal);
	ft_destroy(g, g->sprites.logo);
	ft_destroy(g, g->sprites.pacman);
	ft_destroy(g, g->sprites.black);
	free_player(g);
	free_fonts(g);
	free_animation(g, g->sprites.pac_dying);
	return (0);
}

void	free_player(t_game *g)
{
	t_player	*ghost;
	t_player	*pacman;

	ghost = g->gh;
	pacman = g->pl;
	while (ghost)
	{
		free_animation(g, ghost->sprites.up_bak);
		free_animation(g, ghost->sprites.down_bak);
		free_animation(g, ghost->sprites.left_bak);
		free_animation(g, ghost->sprites.right_bak);
		ghost = ghost->next;
	}
	while (pacman)
	{
		free_animation(g, pacman->sprites.up_bak);
		free_animation(g, pacman->sprites.down_bak);
		free_animation(g, pacman->sprites.left_bak);
		free_animation(g, pacman->sprites.right_bak);
		pacman = pacman->next;
	}
}

void	ft_free_singlepl(t_game *g, t_player *pl)
{
	free_animation(g, pl->sprites.up_bak);
	free_animation(g, pl->sprites.down_bak);
	free_animation(g, pl->sprites.left_bak);
	free_animation(g, pl->sprites.right_bak);
}

void	ft_put_map(t_game *g, int x, int y)
{
	if (g->map[y][x] == '1')
		mlx_put_image_to_window(g->id, g->w_id, g->sprites.wall, x * SIZE, y
			* SIZE);
	if (g->map[y][x] == 'E')
		mlx_put_image_to_window(g->id, g->w_id, g->sprites.portal, x * SIZE, y
			* SIZE);
	if (g->map[y][x] == 'C')
		mlx_put_image_to_window(g->id, g->w_id, g->sprites.pacfood, x * SIZE, y
			* SIZE);
}
