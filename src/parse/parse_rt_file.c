/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rt_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <kko@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:52:33 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/16 13:05:01 by kko              ###   ########.fr       */
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

// void	check_flags(char *line)
// {``
// 	ft_split_is_space();
// }

// char	*read_file(t_info *info, char *file_name)
// {
// 	int				fd;
// 	char 			*readed;
// 	char			*read_tmp;
// 	char 			*tmp;
// 	t_check_flag	*check;

// 	info->t_a->color_b = 0;
// 	fd = open(file_name, O_RDONLY);
// 	if (fd < 0)
// 		error_exit("File open failed");
// 	tmp = get_next_line(fd);
// 	if (!tmp)
// 	{
// 		close(fd);
// 		return (NULL);
// 	}
// 	check = ft_calloc(sizeof(t_check_flag), 1);
// 	readed = ft_calloc(sizeof(char *), 1);
// 	while (1)
// 	{
// 		read_tmp = readed;
// 		readed = ft_strjoin(readed, tmp);
// 		free(read_tmp);
// 		free(tmp);
// 		tmp = get_next_line(fd);
// 		if (!tmp)
// 			break ;
// 	}
// 	close(fd);
// 	// printf("%s", readed);
// 	free(readed);
// 	free(check);
// 	return (NULL);
// }

int	check_range(int type, float ret)
{
	if (type == 255 || (ret <= 0 && ret >= 255))
		return (SUCCESS);
	else if (type == -1 || (ret <= -1 && ret >= 1))
		return (SUCCESS);
	else if (type == 1 || (ret <= 0 && ret >= 1))
		return (SUCCESS);
	else
		return (ERR);
}

float	ft_atof_stream(char **s)
{
	double	ret;
	double	i;
	int		sign;

	ret = 0;
	sign = 1;
	i = 0.1;
	if (**s == 0)
		return (-1);
	if (**s == '-')
	{
		sign = -1;
		(*s)++;
	}
	ret = (double)ft_atoi_stream(s);
	while (**s != '.')
		(*s)++;
	(*s)++;
	while (**s >= '0' && **s <= '9')
	{
		ret = ret + ((**s - '0') * i);
		i *= 0.1;
		(*s)++;
	}
	return ((float)(sign * ret));
}

void	get_arg_color(int *color, char *s)
{
	if (*s == 0)
		error_exit("wrong argument");
	color[0] = ft_atoi_stream(&s);
	if (check_range(255, color[0]) == ERR)
		error_exit("wrong argument");
	while (!(*s >= '0' && *s <= '9') && *s != 0)
		s++;
	color[1] = ft_atoi_stream(&s);
	if (check_range(255, color[1]) == ERR)
		error_exit("wrong argument");
	while (!(*s >= '0' && *s <= '9') && *s != 0)
		s++;
	color[2] = ft_atoi_stream(&s);
	if (check_range(255, color[2]) == ERR)
		error_exit("wrong argument");
}
	
void	get_ambient(t_info *info, char *s)
{
	while (*s != 0 && (*s == ' ' || *s == '\t'))
		s++;
	info->t_a->amb_light_ratio = ft_atof_stream(&s);
	if (check_range(1, info->t_a->amb_light_ratio) == ERR)
		error_exit("wrong argument:A:amb_L");
	while (*s != 0 && (*s == ' ' || *s == '\t'))
		s++;
	get_arg_color(info->t_a->colors, s);
}

void	edit_info(t_info *info, char *s)
{
	if (*s == 'A')
		get_ambient(info, ++s);
	else if (*s == 'C')
		get_camera(info, ++s);
	else if (*s == 'L')
		get_light(info, ++s);
	else
		error_exit("wrong identifier");
}

char	*read_file(t_info *info, char *file_name)
{
	char *tmp;
	char *tmp1;
	int fd;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		error_exit("File open failed");
	tmp = get_next_line(fd);
	if (!tmp)
	{
		close(fd);
		return (NULL);
	}
	tmp1 = tmp;
	while (*tmp1 != 0 && (*tmp1 == ' ' || *tmp1 == '\t'))
		tmp1++;
	edit_info(info, tmp1);
	free(tmp);
	return ("yet");
}

char	*parse_rt_file(t_info *info, char *file_name)
{
	check_file_name(file_name);
	read_file(info, file_name);
	return (NULL);
}