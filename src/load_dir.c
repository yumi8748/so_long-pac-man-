/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu-chen <yu-chen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:02:29 by yu-chen           #+#    #+#             */
/*   Updated: 2024/05/08 15:25:21 by yu-chen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game.h"

t_list	*ft_load_north(t_game *g, char *path, int i)
{
	t_list	*anim;

	anim = NULL;
	if (path)
	{
		g->s = ft_strjoin(path, "ghost_up1.xpm");
		ft_lstadd_back(&anim, ft_lstaddnew(mlx_xpm_file_to_image(g->id, g->s,
					&i, &i), g));
		free(g->s);
		g->s = ft_strjoin(path, "ghost_up2.xpm");
		ft_lstadd_back(&anim, ft_lstaddnew(mlx_xpm_file_to_image(g->id, g->s,
					&i, &i), g));
		free(g->s);
		return (anim);
	}
	ft_lstadd_back(&anim, ft_lstaddnew(mlx_xpm_file_to_image(g->id,
				"sprites/Pac-Man/pac_semi_up.xpm", &i, &i), g));
	ft_lstadd_back(&anim, ft_lstaddnew(mlx_xpm_file_to_image(g->id,
				"sprites/Pac-Man/pac_open_up.xpm", &i, &i), g));
	ft_lstadd_back(&anim, ft_lstaddnew(mlx_xpm_file_to_image(g->id,
				"sprites/Pac-Man/pac_semi_up.xpm", &i, &i), g));
	ft_lstadd_back(&anim, ft_lstaddnew(mlx_xpm_file_to_image(g->id,
				"sprites/Pac-Man/pac_closed.xpm", &i, &i), g));
	return (anim);
}

t_list	*ft_load_south(t_game *g, char *path, int i)
{
	t_list	*anim;

	anim = NULL;
	if (path)
	{
		g->s = ft_strjoin(path, "ghost_down1.xpm");
		ft_lstadd_back(&anim, ft_lstaddnew(mlx_xpm_file_to_image(g->id, g->s,
					&i, &i), g));
		free(g->s);
		g->s = ft_strjoin(path, "ghost_down2.xpm");
		ft_lstadd_back(&anim, ft_lstaddnew(mlx_xpm_file_to_image(g->id, g->s,
					&i, &i), g));
		free(g->s);
		return (anim);
	}
	ft_lstadd_back(&anim, ft_lstaddnew(mlx_xpm_file_to_image(g->id,
				"sprites/Pac-Man/pac_semi_down.xpm", &i, &i), g));
	ft_lstadd_back(&anim, ft_lstaddnew(mlx_xpm_file_to_image(g->id,
				"sprites/Pac-Man/pac_open_down.xpm", &i, &i), g));
	ft_lstadd_back(&anim, ft_lstaddnew(mlx_xpm_file_to_image(g->id,
				"sprites/Pac-Man/pac_semi_down.xpm", &i, &i), g));
	ft_lstadd_back(&anim, ft_lstaddnew(mlx_xpm_file_to_image(g->id,
				"sprites/Pac-Man/pac_closed.xpm", &i, &i), g));
	return (anim);
}

t_list	*ft_load_east(t_game *g, char *path, int i)
{
	t_list	*anim;

	anim = NULL;
	if (path)
	{
		g->s = ft_strjoin(path, "ghost_right1.xpm");
		ft_lstadd_back(&anim, ft_lstaddnew(mlx_xpm_file_to_image(g->id, g->s,
					&i, &i), g));
		free(g->s);
		g->s = ft_strjoin(path, "ghost_right2.xpm");
		ft_lstadd_back(&anim, ft_lstaddnew(mlx_xpm_file_to_image(g->id, g->s,
					&i, &i), g));
		free(g->s);
		return (anim);
	}
	ft_lstadd_back(&anim, ft_lstaddnew(mlx_xpm_file_to_image(g->id,
				"sprites/Pac-Man/pac_semi_right.xpm", &i, &i), g));
	ft_lstadd_back(&anim, ft_lstaddnew(mlx_xpm_file_to_image(g->id,
				"sprites/Pac-Man/pac_open_right.xpm", &i, &i), g));
	ft_lstadd_back(&anim, ft_lstaddnew(mlx_xpm_file_to_image(g->id,
				"sprites/Pac-Man/pac_semi_right.xpm", &i, &i), g));
	ft_lstadd_back(&anim, ft_lstaddnew(mlx_xpm_file_to_image(g->id,
				"sprites/Pac-Man/pac_closed.xpm", &i, &i), g));
	return (anim);
}

t_list	*ft_load_west(t_game *g, char *path, int i)
{
	t_list	*anim;

	anim = NULL;
	if (path)
	{
		g->s = ft_strjoin(path, "ghost_left1.xpm");
		ft_lstadd_back(&anim, ft_lstaddnew(mlx_xpm_file_to_image(g->id, g->s,
					&i, &i), g));
		free(g->s);
		g->s = ft_strjoin(path, "ghost_left2.xpm");
		ft_lstadd_back(&anim, ft_lstaddnew(mlx_xpm_file_to_image(g->id, g->s,
					&i, &i), g));
		free(g->s);
		return (anim);
	}
	ft_lstadd_back(&anim, ft_lstaddnew(mlx_xpm_file_to_image(g->id,
				"sprites/Pac-Man/pac_semi_left.xpm", &i, &i), g));
	ft_lstadd_back(&anim, ft_lstaddnew(mlx_xpm_file_to_image(g->id,
				"sprites/Pac-Man/pac_open_left.xpm", &i, &i), g));
	ft_lstadd_back(&anim, ft_lstaddnew(mlx_xpm_file_to_image(g->id,
				"sprites/Pac-Man/pac_semi_left.xpm", &i, &i), g));
	ft_lstadd_back(&anim, ft_lstaddnew(mlx_xpm_file_to_image(g->id,
				"sprites/Pac-Man/pac_closed.xpm", &i, &i), g));
	return (anim);
}
