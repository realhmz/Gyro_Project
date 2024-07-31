/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gyro.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-taja <het-taja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 10:44:48 by het-taja          #+#    #+#             */
/*   Updated: 2024/07/31 12:44:08 by het-taja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <unistd.h>
#include <readline/readline.h>
#include <fcntl.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846
#define ANGLE 45

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		h;
	int		w;
	int		bpp;
	int		line_len;
	int		endian;
	void	*win;
}	t_img;

typedef struct s_map_coord
{
	int	abscissa;
	int	ordinate;
	int altitude_min;
	int altitude_max;
	int	***matrix;
}	t_map_coord;

typedef struct s_data
{
    float Xa;  
    float Ya;  
    float Za;
    int     center;
    int     center_y;
    int     cnstx;
    int     cnsty;
    void    *mlx;
    void    *win;
    t_map_coord *map;
    t_img    img;
}        t_data;


// parsing funcs 

void    parce(t_data *data, char *cord);
char	**ft_split(char const *s, char c);
char	*ft_strdup(char *s);
int	ft_strlen(char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int	ft_atoi(const char *nptr);
unsigned int	ft_atoi_base(char *str,char *base);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
int	ft_toupper(int x);

void	ft_get_map(char *filename, t_map_coord *map);
void	ft_get_altitude_min_max(t_map_coord *map);
void	ft_fill_matrix(t_map_coord *map, char *line);
void	ft_error(char *message);


//rendring

void    init(t_data *data);
void    render(t_data *data);
void	put_pixel_img(t_img img, int x, int y, int color);
t_img	new_img(int w, int h, t_data *window);
void draw_map(t_data *fdf);
void    bresenham_line(t_data *data, int x0, int y0, int x1, int y1, int color);

float rad(float deg);
// get_next_line

#define BUFFER_SIZE 100
char	*get_next_line(int fd);
int		ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
