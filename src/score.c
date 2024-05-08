/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu-chen <yu-chen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:04:31 by yu-chen           #+#    #+#             */
/*   Updated: 2024/05/08 15:43:11 by yu-chen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game.h"
#include "../minilibx-linux/mlx.h"
#include <unistd.h>

void	ft_update_score(t_game *g)
{
	int	i;
	int	score;
	int	digit;

	i = 0;
	score = g->n_moves;
	while (i < 4)
	{
		digit = score % 10;
		score /= 10;
		mlx_put_image_to_window(g->id, g->w_id, g->sprites.score_font.black,
			g->width / 2 + 10 - 12 * i, g->height - 67);
		ft_put_font(g, digit, i);
		i++;
	}
}

int	ft_load_score_font(t_game *g)
{
	int	size;

	g->sprites.score_font.zero = mlx_xpm_file_to_image(g->id,
			"sprites/Other/Fonts/0.xpm", &size, &size);
	g->sprites.score_font.one = mlx_xpm_file_to_image(g->id,
			"sprites/Other/Fonts/1.xpm", &size, &size);
	g->sprites.score_font.two = mlx_xpm_file_to_image(g->id,
			"sprites/Other/Fonts/2.xpm", &size, &size);
	g->sprites.score_font.three = mlx_xpm_file_to_image(g->id,
			"sprites/Other/Fonts/3.xpm", &size, &size);
	g->sprites.score_font.four = mlx_xpm_file_to_image(g->id,
			"sprites/Other/Fonts/4.xpm", &size, &size);
	g->sprites.score_font.five = mlx_xpm_file_to_image(g->id,
			"sprites/Other/Fonts/5.xpm", &size, &size);
	g->sprites.score_font.six = mlx_xpm_file_to_image(g->id,
			"sprites/Other/Fonts/6.xpm", &size, &size);
	g->sprites.score_font.seven = mlx_xpm_file_to_image(g->id,
			"sprites/Other/Fonts/7.xpm", &size, &size);
	g->sprites.score_font.eight = mlx_xpm_file_to_image(g->id,
			"sprites/Other/Fonts/8.xpm", &size, &size);
	g->sprites.score_font.nine = mlx_xpm_file_to_image(g->id,
			"sprites/Other/Fonts/9.xpm", &size, &size);
	g->sprites.score_font.black = mlx_xpm_file_to_image(g->id,
			"sprites/Other/Fonts/black.xpm", &size, &size);
	return (check_font_xpm(g));
}

void	ft_put_font(t_game *g, int digit, int i)
{
	void	*font;

	font = NULL;
	if (digit == 0)
		font = g->sprites.score_font.zero;
	if (digit == 1)
		font = g->sprites.score_font.one;
	if (digit == 2)
		font = g->sprites.score_font.two;
	if (digit == 3)
		font = g->sprites.score_font.three;
	if (digit == 4)
		font = g->sprites.score_font.four;
	if (digit == 5)
		font = g->sprites.score_font.five;
	if (digit == 6)
		font = g->sprites.score_font.six;
	if (digit == 7)
		font = g->sprites.score_font.seven;
	if (digit == 8)
		font = g->sprites.score_font.eight;
	if (digit == 9)
		font = g->sprites.score_font.nine;
	mlx_put_image_to_window(g->id, g->w_id, font, g->width / 2 + 10 - 12 * i,
		g->height - 67);
}

void	free_fonts(t_game *g)
{
	ft_destroy(g, g->sprites.score_font.black);
	ft_destroy(g, g->sprites.score_font.zero);
	ft_destroy(g, g->sprites.score_font.one);
	ft_destroy(g, g->sprites.score_font.two);
	ft_destroy(g, g->sprites.score_font.three);
	ft_destroy(g, g->sprites.score_font.four);
	ft_destroy(g, g->sprites.score_font.five);
	ft_destroy(g, g->sprites.score_font.six);
	ft_destroy(g, g->sprites.score_font.seven);
	ft_destroy(g, g->sprites.score_font.eight);
	ft_destroy(g, g->sprites.score_font.nine);
}
