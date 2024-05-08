/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu-chen <yu-chen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:16:37 by yu-chen           #+#    #+#             */
/*   Updated: 2024/04/22 19:50:08 by yu-chen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game.h"

void	ft_anim_north(t_game *g, t_player *pl)
{
	t_player	*temp;

	temp = pl;
	if (!(g->n_frames % (((g->g_rate) + g->g_rate) / 7)))
		temp->sprites.up = temp->sprites.up->next;
	if (!temp->sprites.up)
		temp->sprites.up = temp->sprites.up_bak;
	mlx_put_image_to_window(g->id, g->w_id, temp->sprites.up->content, \
		temp->win_pos.x, temp->win_pos.y);
}

void	ft_anim_south(t_game *g, t_player *pl)
{
	t_player	*temp;

	temp = pl;
	if (!(g->n_frames % (((g->g_rate) + g->g_rate) / 7)))
		temp->sprites.down = temp->sprites.down->next;
	if (!temp->sprites.down)
		temp->sprites.down = temp->sprites.down_bak;
	mlx_put_image_to_window(g->id, g->w_id, temp->sprites.down->content, \
		temp->win_pos.x, temp->win_pos.y);
}

void	ft_anim_east(t_game *g, t_player *pl)
{
	t_player	*temp;

	temp = pl;
	if (!(g->n_frames % (((g->g_rate) + g->g_rate) / 7)))
		temp->sprites.right = temp->sprites.right->next;
	if (!temp->sprites.right)
		temp->sprites.right = temp->sprites.right_bak;
	mlx_put_image_to_window(g->id, g->w_id, temp->sprites.right->content, \
		temp->win_pos.x, temp->win_pos.y);
}

void	ft_anim_west(t_game *g, t_player *pl)
{
	t_player	*temp;

	temp = pl;
	if (!(g->n_frames % (((g->g_rate) + g->g_rate) / 7)))
		temp->sprites.left = temp->sprites.left->next;
	if (!temp->sprites.left)
		temp->sprites.left = temp->sprites.left_bak;
	mlx_put_image_to_window(g->id, g->w_id, temp->sprites.left->content, \
		temp->win_pos.x, temp->win_pos.y);
}
