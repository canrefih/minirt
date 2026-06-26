#ifndef MINIRT_H
# define MINIRT_H

# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "mlx.h"
# include "libft.h"

# define WIDTH 800
# define HEIGHT 600
# define ERROR "Error\n"
# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}	t_vec3;

typedef struct s_q_params
{
	double	a;
	double	b;
	double	c;
}	t_q_params;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_hit_data
{
	t_vec3	normal;
	t_vec3	point;
	t_color	color;
	double	t;
}	t_hit_data;

typedef struct s_render_ctx
{
	double	aspect;
	double	scale;
	int		i;
	int		j;
}	t_render_ctx;

typedef struct s_ray
{
	t_vec3	origin;
	t_vec3	direction;
}	t_ray;

typedef enum e_obj_type
{
	SPHERE,
	PLANE,
	CYLINDER
}	t_obj_type;

typedef struct s_sphere
{
	t_vec3	center;
	double	diameter;
	t_color	color;
}	t_sphere;

typedef struct s_plane
{
	t_vec3	point;
	t_vec3	normal;
	t_color	color;
}	t_plane;

typedef struct s_cylinder
{
	t_vec3	center;
	t_vec3	axis;
	double	diameter;
	double	height;
	t_color	color;
}	t_cylinder;

typedef struct s_object
{
	t_obj_type		type;
	void			*shape;
	struct s_object	*next;
}	t_object;

typedef struct s_camera
{
	t_vec3	pos;
	t_vec3	forward;
	t_vec3	right;
	t_vec3	up;
	double	fov;
}	t_camera;

typedef struct s_light
{
	t_vec3	pos;
	double	intensity;
	t_color	color;
}	t_light;

typedef struct s_ambient
{
	double	ratio;
	t_color	color;
}	t_ambient;

typedef struct s_scene
{
	t_camera	camera;
	t_light		light;
	t_object	*objects;
	t_ambient	ambient;
}	t_scene;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	t_img	img;
}	t_mlx;

typedef struct s_rt
{
	t_scene	scene;
	t_mlx	mlx;
}	t_rt;

/* init */
int			init_scene(t_rt *rt);
int			parse_file(char *file, t_rt *rt);
int			key_hook(int keycode, t_rt *rt);
int			close_window(void *param);
void		init_mlx(t_rt *rt);
void		init_default_camera(t_rt *rt);

/* render */
void		render(t_rt *rt);
int			get_sphere_lighting(t_vec3 hit, t_sphere sp, t_vec3 light_pos);
double		hit_object(t_ray ray, t_object *obj);
int			is_in_shadow(t_scene *scene, t_vec3 hit, t_vec3 light_pos);
double		hit_scene(t_scene *scene, t_ray ray, t_object **hit_obj);

/* ray tracing */
t_color		trace_ray(t_ray ray, t_scene *scene);
t_ray		ray_create(t_vec3 origin, t_vec3 direction);
t_vec3		ray_at(t_ray ray, double t);

/* utils */
double		ft_atof(const char *s);
void		free_split(char **p);
int			arr_len(char **s);
int			is_valid_float(char *str);
int			is_valid_int(char *str);
void		my_mlx_pixel_put(t_img *img, int x, int y, int color);
void		free_objects(t_object *obj);

/* vec3 */
t_vec3		parse_vec3(char *str);
t_vec3		vec3(double x, double y, double z);
t_vec3		vec_add(t_vec3 a, t_vec3 b);
t_vec3		vec_sub(t_vec3 a, t_vec3 b);
t_vec3		vec_scale(t_vec3 v, double t);
double		vec_dot(t_vec3 a, t_vec3 b);
double		vec_len(t_vec3 v);
t_vec3		vec_normalize(t_vec3 v);
t_vec3		vec_cross(t_vec3 a, t_vec3 b);

/* sphere */
void		parse_sphere(t_rt *rt, char **s);
double		sphere_intersect(t_ray ray, t_sphere sphere);
t_color		get_shaded_color(t_rt *rt, t_hit_data data,
				t_color base, int shadow);

/* parse features */
void		parse_camera(t_rt *rt, char **s);
void		parse_light(t_rt *rt, char **s);
void		parse_ambient(t_rt *rt, char **s);
t_color		parse_color(char *str);
void		parse_scene(t_rt *rt, char *file);

/* plane */
void		parse_plane(t_rt *rt, char **s);
double		plane_intersect(t_ray ray, t_plane pl);

/* cylinder */
void		parse_cylinder(t_rt *rt, char **s);
double		hit_cylinder(t_ray ray, t_cylinder *cy);
t_q_params	get_cy_params(t_ray ray, t_cylinder *cy);
double		hit_cylinder_body(t_ray ray, t_cylinder *cy);
double		hit_disk(t_ray ray, t_vec3 center, t_vec3 normal, double radius);
double		check_height(t_ray ray, t_cylinder *cy, double t);
double		hit_cylinder_caps(t_ray ray, t_cylinder *cy);

#endif