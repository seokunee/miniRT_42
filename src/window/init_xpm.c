/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_xpm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:12:52 by sunhwang          #+#    #+#             */
/*   Updated: 2023/02/02 20:29:08 by sunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "window.h"
#include "structs.h"
#include "error.h"

void	init_image(t_window *win, t_texture *texture, char *file, t_texture_type type)
{
	char	*file_path;
	t_data	*data;

	if (ft_strncmp(file, "checker", 8) == 0)
	{
		texture->type = CHECK;
		return ;
	}
	else if (type == DIFFUSE)
		texture->type = DIFFUSE;
	else if (type == NORMAL)
		texture->type = NORMAL;
	file_path = ft_strjoin("./src/images/", file);
	data = &texture->data;
	data->img = mlx_xpm_file_to_image(win->mlx, file_path, &texture->width, &texture->height);
	if (!data->img)
		error_exit("Invaild texture file");
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
	free(file_path);
}
