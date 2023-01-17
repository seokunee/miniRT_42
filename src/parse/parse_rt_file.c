/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rt_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:52:33 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/16 21:17:12 by seokchoi         ###   ########.fr       */
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

float	ft_atof(char *s)
{
	double	ret;
	double	i;
	int		sign;

	ret = 0;
	sign = 1;
	i = 0.1;
	if (*s == 0)
		return (-1);
	if (*s == '-')
	{
		sign = -1;
		(s)++;
	}
	ret = (double)ft_atoi(s);
	if (*s == '.')
		(s)++;
	while (*s >= '0' && *s <= '9')
	{
		ret = ret + ((*s - '0') * i);
		i *= 0.1;
		(s)++;
	}
	return ((float)(sign * ret));
}

int	check_oper(char c, char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != c)
			return (ERR);
		i++;
	}
	return (SUCCESS);
}

int	check_only_num1(char *opt, char *oper)
{
	while (*opt)
	{
		if (*opt >= '0' && *opt <= '9')
			opt++;
		else if (check_oper(*opt, oper))
			opt++;
		else
			error_exit("wrong argument");
	}
	return (SUCCESS);
}

int	check_only_num(char **opt, char *oper)
{
	int	i;
	int	j;

	i = 0;
	while (opt[i])
	{
		check_only_num1(opt[i], oper);
		i++;
	}
}

t_vec3	*get_arg_color(char *s)
{
	char	**tmp;
	float	color[3];

	tmp = ft_split(s[2], ',');
	if (sec_arr_len(tmp) != 3)
		error_exit("wrong argument");
	check_only_num(tmp, "");
	color[0] = ft_atof(tmp[0]);
	if (check_range(255, color[0]) == ERR)
		error_exit("wrong argument");
	while (!(tmp >= '0' && tmp <= '9') && tmp != 0)
		s++;
	color[1] = ft_atof(tmp[1]);
	if (check_range(255, color[1]) == ERR)
		error_exit("wrong argument");
	while (!(tmp >= '0' && tmp <= '9') && tmp != 0)
		s++;
	color[2] = ft_atof(tmp[2]);
	if (check_range(255, color[2]) == ERR)
		error_exit("wrong argument");
	return (create_3d_vec(color[0],color[1], color[2]));
}
	
void	get_ambient(t_info *info, char **s)
{
	if (sec_arr_len(s) != 3)
		error_exit("wrong argument");
	check_only_num1(s[1], ".");
	info->t_a->amb_light_ratio = ft_atof(s[1]);
	if (check_range(1, info->t_a->amb_light_ratio) == ERR)
		error_exit("wrong argument:A:amb_L");
	while (*s != 0 && ft_isspace(*s))
		s++;
	info->t_a->colors = get_arg_color(s[2]);
}

int	sec_arr_len(char **arr)
{
	int	len;

	len = 0;
	while (arr[len])
		len++;
	return (len);
}

void	free_sec_arr(char *arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

void	check_coordinates(t_objs *obj, char *str) // 모든 coor을 체크 할 수 있음.
{
	char **coor;

	coor = ft_split(str, ',');
	if (!coor)
		error_exit("Malloc Error\n");
	if (sec_arr_len(coor) != 3) // vector 3인지 체크
		error_exit("wrong argument");
	check_only_num1(coor[0], "."); // 숫자와 . 으로 이루어졌는지는 체크.
	check_only_num1(coor[1], ".");
	check_only_num1(coor[2], ".");
	obj->coor = create_3d_vec(ft_atof(coor[0]),\
	ft_atof(coor[1]), ft_atof(coor[2]));
	free_sec_arr(coor);
}

void	check_normal_vector(t_objs *obj, char *str)
{
	char **normal;

	normal = ft_split(str, ',');
	if (!normal)
		error_exit("Malloc Error\n");
	if (sec_arr_len(normal) != 3) // vector 3인지 체크
		error_exit("wrong argument");
	check_only_num1(normal[0], ".");
	check_only_num1(normal[1], ".");
	check_only_num1(normal[2], ".");
	obj->normal = create_3d_vec(ft_atof(normal[0]),\
	ft_atof(normal[1]), ft_atof(normal[2]));
	if (v_dot(obj->normal, obj->normal) != 1)
		error_exit("wrong normal argument");
}

void	check_diameter(t_objs *obj, float dia)
{
	if (dia <= 0)
		error_exit("wrong argument");
	obj->diameter = dia;
}

void	check_obj(t_objs *obj, char **opt, t_type type)
{
	obj->type = type;
	if (type == PL)
		set_pl(obj, opt);
	if (type == SP)
		set_sp(obj, opt);
	if (type == CY)
		set_cy(obj, opt);
}

void	get_obj(t_info *info, char **opt, t_type type)
{
	t_objs *obj;
	t_list *new;

	obj = malloc(sizeof(t_objs));
	if (!obj)
		error_exit("malloc error");
	new = ft_lstnew(obj);
	ft_lstadd_back(&(info->t_objs), new);
	check_obj(obj, opt, type);
}

t_vec3	*get_arg_coor(char *s)
{
	char	**tmp;
	float	color[3];

	tmp = ft_split(s[2], ',');
	if (!tmp[3])
		error_exit("wrong argument");
	check_only_num(tmp, ".");
	color[0] = ft_atof(tmp[0]);
	while (!(tmp >= '0' && tmp <= '9') && tmp != 0)
		s++;
	color[1] = ft_atof(tmp[1]);
	while (!(tmp >= '0' && tmp <= '9') && tmp != 0)
		s++;
	color[2] = ft_atof(tmp[2]);
	return (create_3d_vec(color[0],color[1], color[2]));
}

t_vec3	*get_arg_normal(char *s)
{
	char	**tmp;
	float	color[3];

	tmp = ft_split(s[2], ',');
	if (sec_arr_len(tmp) != 3);
		error_exit("wrong argument");
	check_only_num(tmp, ".");
	color[0] = ft_atof(tmp[0]);
	if (check_range(-1, color[0]) == ERR)
		error_exit("wrong argument");
	while (!(tmp >= '0' && tmp <= '9') && tmp != 0)
		s++;
	color[1] = ft_atof(tmp[1]);
	if (check_range(-1, color[1]) == ERR)
		error_exit("wrong argument");
	while (!(tmp >= '0' && tmp <= '9') && tmp != 0)
		s++;
	color[2] = ft_atof(tmp[2]);
	if (check_range(-1, color[2]) == ERR)
		error_exit("wrong argument");
	return (create_3d_vec(color[0],color[1], color[2]));
}


void	edit_info(t_info *info, char *s)
{
	char **options;

	options = ft_split_is_space(s);
	if (!options)
		error_exit("malloc error"); // 이게 맞나? 확인
	if (sec_arr_len(options) < 3)
		error_exit("wrong identifier");
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
		error_exit("wrong identifier");
	free_sec_arr(options);
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
	while (*tmp1 != 0 && ft_isspace(*tmp1))
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