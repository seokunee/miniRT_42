/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 09:50:10 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/17 18:20:30 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
#define PARSE_H

typedef struct s_objs t_objs;
typedef struct s_info t_info;
typedef enum e_type t_type;

// ambient
void	get_ambient(t_info *info, char **s);

// camera
void	get_camera(t_info *info, char **s);

// colors
t_vec3	*get_arg_color(char *s);

// coordinate
t_vec3	*get_arg_coor(char *s);
void	check_coordinates(t_objs *obj, char *str);

// cylinder
void	set_cy(t_objs *obj, char **opt);

// diameter
void	check_diameter(t_objs *obj, float dia);

// light
void	get_light(t_info *info, char **s);

// normal
t_vec3	*get_arg_normal(char *s);

// objects
void	check_obj(t_objs *obj, char **opt, t_type type);
void	get_obj(t_info *info, char **opt, t_type type);

// parse_rt_file
void	check_file_name(char *file_name);
int		check_range(int type, float ret);
void	edit_info(t_info *info, char *s);
bool	read_file(t_info *info, int fd);
char	*parse_rt_file(t_info *info, char *file_name);

//plane
void	set_pl(t_objs *obj, char **opt);

//sphere
void	set_sp(t_objs *obj, char **opt);

// utils
int		sec_arr_len(char **arr);
float	ft_atof(char *s);
int		check_only_num1(char *opt, char *oper);
int		check_only_num(char **opt, char *oper);

// utils2
int		check_oper(char c, char *s);
void	print_all_info(t_info *info);

#endif
