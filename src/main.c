/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu-chen <yu-chen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:42:18 by yu-chen           #+#    #+#             */
/*   Updated: 2024/04/29 16:52:37 by yu-chen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "../inc/check.h"
#include "../inc/game.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	char	**map;
	t_lay	lay;

	map = check_params(argc, argv, &lay);
	check_map_path(map, &lay);
	init_game(map, lay);
	return (0);
}
