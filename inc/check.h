/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu-chen <yu-chen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:42:27 by yu-chen           #+#    #+#             */
/*   Updated: 2024/04/22 17:42:50 by yu-chen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_H
# define CHECK_H

# include "map.h"
# include "../libft/inc/libft.h"
# include <fcntl.h>

char	**check_params(int argc, char **argv, t_lay *lay);
char	**check_map(int fd, t_lay *lay);

#endif
