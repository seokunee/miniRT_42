/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rt_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:52:33 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/20 16:34:24 by sunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "minirt.h"

void	check_file_name(char *file_name)
{
	int	name_len;

	name_len = ft_strlen(file_name);
	if (name_len < 3)
		error_exit("Invalid file type");
	if (file_name[name_len - 3] != '.' || file_name[name_len - 2] != 'r' \
	||file_name[name_len - 1] != 't')
		error_exit("Invalid file type");
}

int	check_range(int type, float ret)
{
	if (type == 255 || (ret >= 0 && ret <= 255))
		return (SUCCESS);
	else if (type == -1 || (ret >= -1 && ret <= 1))
		return (SUCCESS);
	else if (type == 1 || (ret >= 0 && ret <= 1))
		return (SUCCESS);
	else if (type == 180 || (ret >= 0 && ret <= 180))
		return (SUCCESS);
	return (ERR);
}

void	edit_info(t_info *info, char *s)
{
	char **options;

	options = ft_split_is_space(s);
	if (!options)
		error_exit("Malloc error");
	if (sec_arr_len(options) < 3)
		error_exit("Wrong identifier");
	if (ft_strncmp(options[0], "A", 2) == 0)
		get_ambient(info, options);
	else if (ft_strncmp(options[0], "C", 2) == 0)
		get_camera(info, options);
	else if (ft_strncmp(options[0], "L", 2) == 0)
		get_light(info, options);
	else if (ft_strncmp(options[0], "pl", 3) == 0)
		get_obj(info, options, PL);
	else if (ft_strncmp(options[0], "sp", 3) == 0)
		get_obj(info, options, SP);
	else if (ft_strncmp(options[0], "cy", 3) == 0)
		get_obj(info, options, CY);
	else
		error_exit("Wrong identifier");
	free_double_array((void**)options);
}

bool read_file(t_info *info, int fd)
{
	char *tmp;

	tmp = get_next_line(fd);
	if (!tmp)
	{
		close(fd);
		return (false);
	}
	else if (ft_strncmp(tmp, "\n", 2) == 0)
	{
		free(tmp);
		return (true);
	}
	edit_info(info, tmp);
	free(tmp);
	return (true);
}

void	parse_rt_file(t_info *info, char *file_name)
{
	int fd;

	check_file_name(file_name);
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		error_exit("File open failed");
	init_info(info);
	while (1)
	{
		if (!read_file(info, fd))
			break ;
	}
}
