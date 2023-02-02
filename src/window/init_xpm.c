/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_xpm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:12:52 by sunhwang          #+#    #+#             */
/*   Updated: 2023/02/02 18:03:51 by sunhwang         ###   ########.fr       */
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
	t_data	*data;

	obj->texture.type = 1; // 만약 type을 쓴다면 바꿔주는 부분이 필요 지금은 일단 0으로 통일
	file_path = ft_strjoin("/Users/seokchoi/Desktop/miniRT_42/src/images/", file);
	// file path 메크로로 만들어주거나 밖에서 파싱하는 방법으로 해야할 것 같다. 아니면 파일 이름 넣어줄떄
	// 아예 다 넣어주던가.
	// file_path = ft_strjoin("./src/images/", file);
	data = &obj->texture.data;
	data->img = mlx_xpm_file_to_image(info->win.mlx, \
	file_path, &img_width, &img_height);
	if (!obj->texture.data.img)
		error_exit("Invaild texture file");
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
	obj->texture.width = img_width;
	obj->texture.height = img_height;
	free(file_path);
}
