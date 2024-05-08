/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu-chen <yu-chen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:15:35 by yu-chen           #+#    #+#             */
/*   Updated: 2024/05/08 15:56:49 by yu-chen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game.h"

void	ft_anim_pacdeath(t_game *g)
{
	t_player	*temp_pl;

	temp_pl = g->pl;
	while (temp_pl)
	{
		mlx_put_image_to_window(g->id, g->w_id, g->sprites.black,
			temp_pl->win_pos.x, temp_pl->win_pos.y);
		mlx_put_image_to_window(g->id, g->w_id, g->sprites.pac_dying->content,
			temp_pl->win_pos.x, temp_pl->win_pos.y);
		temp_pl = temp_pl->next;
	}
	g->sprites.pac_dying = g->sprites.pac_dying->next;
	if (!g->sprites.pac_dying)
	{
		printf("\n%sGAME OVER\nBetter luck next time!%s\n\n", RED, DEFAULT);
		end_game(g);
	}
}

void	ft_load_pacdeath(t_game *g)
{
	char	c;
	int		s;

	g->sprites.pac_dying = NULL;
	g->s = ft_substr("sprites/Pac-Man/Dying/pacman_dying1.xpm", 0, 39);
	c = '0';
	while (c++ < '9')
	{
		ft_memset(&g->s[34], c, 1);
		ft_lstadd_back(&g->sprites.pac_dying,
			ft_lstaddnew(mlx_xpm_file_to_image(g->id, g->s, &s, &s), g));
	}
	free(g->s);
	ft_lstadd_back(&g->sprites.pac_dying,
		ft_lstaddnew(mlx_xpm_file_to_image(g->id,
				"sprites/Pac-Man/Dying/pacman_dying10.xpm", &s, &s), g));
	while (c-- > '7')
	{
		ft_lstadd_back(&g->sprites.pac_dying,
			ft_lstaddnew(mlx_xpm_file_to_image(g->id,
					"sprites/Other/Walls/black.xpm", &s, &s), g));
		ft_lstadd_back(&g->sprites.pac_dying,
			ft_lstaddnew(mlx_xpm_file_to_image(g->id,
					"sprites/Pac-Man/Dying/pacman_woosh.xpm", &s, &s), g));
	}
}

void	free_animation(t_game *g, t_list *start)
{
	t_list	*temp;

	temp = NULL;
	while (start)
	{
		temp = start;
		start = start->next;
		if (g)
			ft_destroy(g, temp->content);
		free(temp);
	}
}
