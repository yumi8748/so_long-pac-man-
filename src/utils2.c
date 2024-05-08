/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu-chen <yu-chen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:47:16 by yu-chen           #+#    #+#             */
/*   Updated: 2024/05/08 16:31:58 by yu-chen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game.h"

void	ft_destroy(t_game *g, void *img)
{
	if (g && g->id && img)
		mlx_destroy_image(g->id, img);
}

t_list	*ft_lstaddnew(void *content, t_game *g)
{
	t_list	*new;

	if (content == NULL)
	{
		err_quit_game(g);
		return (NULL);
	}
	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

int	err_quit_game(t_game *g)
{
	if (g->map)
		ft_free_matrix(&g->map);
	if (g->map_bak)
		ft_free_matrix(&g->map_bak);
	free_sprites(g);
	if (g->pl || g->gh)
		ft_free_playerlist(g);
	printf("%sInvalid .XPM%s", RED, DEFAULT);
	mlx_clear_window(g->id, g->w_id);
	mlx_destroy_window(g->id, g->w_id);
	mlx_destroy_display(g->id);
	if (g->id)
		free(g->id);
	exit(0);
	return (0);
}

int	check_font_xpm(t_game *g)
{
	if (!g->sprites.score_font.zero || !g->sprites.score_font.one
		|| !g->sprites.score_font.two || !g->sprites.score_font.three
		|| !g->sprites.score_font.four || !g->sprites.score_font.five
		|| !g->sprites.score_font.six || !g->sprites.score_font.seven
		|| !g->sprites.score_font.eight || !g->sprites.score_font.nine
		|| !g->sprites.score_font.black)
		err_quit_game(g);
	return (0);
}
