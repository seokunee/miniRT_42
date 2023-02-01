/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_xpm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:12:52 by sunhwang          #+#    #+#             */
/*   Updated: 2023/02/01 21:23:36 by sunhwang         ###   ########.fr       */
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

	obj->texture.type = 0; // 만약 type을 쓴다면 바꿔주는 부분이 필요 지금은 일단 0으로 통일
	file_path = ft_strjoin("./src/images/", file);
	obj->texture.data.img = mlx_xpm_file_to_image(info->win.mlx, \
	file_path, &img_width, &img_height);
	if (!obj->texture.data.img)
		error_exit("Invaild texture file");
	obj->texture.width = img_width;
	obj->texture.height = img_height;
	free(file_path);
}
