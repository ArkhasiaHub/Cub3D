/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earaujo <earaujo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:45:04 by earaujo           #+#    #+#             */
/*   Updated: 2024/05/13 09:26:57 by earaujo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include "../libft/includes/conversion.h"
# include "../libft/includes/string_manip.h"
# include "../libft/includes/mem_manip.h"
# include <fcntl.h>
# include <stdbool.h>
# include "../minilibx-linux/mlx.h"
# include "../libft/includes/is_type.h"

# define WIDTH 1280
# define HEIGHT 800
# define PI 3.14159265359
# define ROTSPEED 2
# define DR 0.0174533
# define FOV 0.66

typedef enum s_side
{
	NORTH,
	SOUTH,
	WEST,
	EAST
}	t_side;

typedef enum s_key
{
	UP = 119,
	DOWN = 115,
	LEFT = 97,
	RIGHT = 100,
}	t_key;

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		pixel_bits;
	int		line_bytes;
	int		endian;
}	t_image;

typedef struct s_textures
{
	void	*n_texture;
	int		n_texture_width;
	int		n_texture_height;
	void	*s_texture;
	int		s_texture_width;
	int		s_texture_height;
	void	*w_texture;
	int		w_texture_width;
	int		w_texture_height;
	void	*e_texture;
	int		e_texture_width;
	int		e_texture_height;
	int		color_f;
	bool	is_f;
	bool	is_c;
	int		color_c;
}	t_textures;

typedef struct s_vector
{
	float	x;
	float	y;
	float	z;
}	t_vector;

typedef struct s_player
{
	t_vector	coord;
	float		pa;
	float		dx;
	float		dy;
	float		px;
	float		py;
}	t_player;

typedef struct s_ray
{
	int		x;
	double	camera_x;
	double	ray_x;
	double	ray_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		j;
	double	wall_x;
	double	step;
	double	tex_pos;
	int		tex_y;
	int		tex_x;
	int		side_wall;
}	t_ray;

typedef struct s_cub
{
	void			*mlx;
	void			*mlx_win;
	t_image			img;
	t_textures		*textures;
	int				fd;
	char			**map;
	int				**world_map;
	int				map_width;
	int				map_height;
	int				size_map;
	int				size_int;
	int				is_player;
	bool			map_begin;
	bool			newline;
	t_player		*player;
	int				player_direction;
}	t_cub;

int		is_map(char *line);
void	init_and_read(int fd, t_cub *cub);
int		pars_textures(char *line, t_cub *cub);
void	error(void);
int		pars_color(char *line, int *i, t_cub *cub);
int		ft_strlen_gnl(char *str);
int		ft_strchr_gnl(const char *s, int c);
char	*ft_strdup_nl(char const *s, int start, int len);
char	*ft_strdup_gnl(const char *s);
char	*ft_str_add(char *s1, char *s2, int size);
char	*get_next_line(int fd);
void	free_all(t_cub *cub);
void	protect_pars(char *line, t_cub *cub);
void	pars_line(char *line, t_cub *cub);
void	free_map(t_cub *cub);
void	verif_map(t_cub *cub);
int		ft_atoi(const char *nptr);
float	degree_to_radian(int ang);
void	render(t_cub *c);
int		little_atoi(char c);
void	map_to_int(t_cub *cub);
void	clear_window(t_cub *c);
int		create_cub(t_cub *cub);
int		calc_pixel(int x, int y, t_image *img);
void	draw_pixel(t_image *img, int pixel, int color);
void	draw_rays(t_cub *cub);
int		get_pixel_color(void *img_ptr, int x, int y);
int		move(int key, t_cub *cub);
void	display(t_cub *cub);
float	fix_ang(float ang);
void	find_side_dist(t_cub *cub, t_ray *ray);
void	init_rays(t_cub *cub, t_ray *ray);
void	move_rotate_view(t_cub *cub, int dir);
void	move_down(t_cub *cub);
void	move_up(t_cub *cub);
void	move_right(t_cub *cub);
void	move_left(t_cub *cub);
bool	check_collision_x(t_cub *cub, int new_x);
bool	check_collision_y(t_cub *cub, int new_y);
void	init_cub(t_cub *cub, int fd);
int		pars_f(char *line, int *i, t_cub *cub);
int		check_begin_map(char *line);
int		all_digit(char *str);
int		pars_c(char *line, int *i, t_cub *cub);

#endif
