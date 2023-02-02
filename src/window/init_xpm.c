/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_xpm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <kko@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:12:52 by sunhwang          #+#    #+#             */
/*   Updated: 2023/02/02 14:38:50 by kko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "window.h"
#include "structs.h"
#include "error.h"

void	init_image(t_info *info, t_obj *obj, char *file)
{
	int		img_width;
	int		img_height;
	char	*file_path;

	obj->texture.type = 0;
	file_path = ft_strjoin("./src/images/", file);
	obj->texture.data.img = mlx_xpm_file_to_image(info->win.mlx, \
	file_path, &img_width, &img_height);
	if (!obj->texture.data.img)
		error_exit("Invaild texture file");
	obj->texture.width = img_width;
	obj->texture.height = img_height;
	free(file_path);
}
