/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rt_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:52:33 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/11 16:22:05 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

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

char	*read_file(t_info *info, char *file_name)
{
	int				fd;
	char 			*readed;
	char			*read_tmp;
	char 			*tmp;
	t_check_flag	*check;

	info->t_a->color_b = 0;
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		error_exit("File open failed");
	check = ft_calloc(sizeof(t_check_flag), 1);
	tmp = get_next_line(fd);
	if (!tmp)
	{
		close(fd);
		return (NULL);
	}
	readed = ft_calloc(sizeof(char *), 1);
	while (1)
	{
		read_tmp = readed;
		readed = ft_strjoin(readed, tmp);
		free(read_tmp);
		free(tmp);
		tmp = get_next_line(fd);
		if (!tmp)
			break ;
	}
	close(fd);
	printf("%s", readed);
	free(readed);
	return (NULL);
}

char	*parse_rt_file(t_info *info, char *file_name)
{
	check_file_name(file_name);
	read_file(info, file_name);
	return (NULL);
}