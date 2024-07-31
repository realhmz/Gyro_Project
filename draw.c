/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-taja <het-taja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 12:37:55 by het-taja          #+#    #+#             */
/*   Updated: 2024/07/31 18:28:54 by het-taja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gyro.h"
float rad(float deg)
{
	return(deg * PI / 180);
}
static int	ft_is_outofscreen(t_data *fdf, int x, int y, int z)
{
	// y1 *= -1;
	x = (x * cos(rad(ANGLE)) - y * sin(rad(ANGLE)));
	y = (x * sin(rad(ANGLE)) + y * cos(rad(ANGLE)));
	y = (y * sin(rad(30)) - z * cos(rad(30)));
	x += fdf->center;
	y += fdf->center_y;
	if (x * fdf->cnstx < 0 || x * fdf->cnstx > 1000 || x * fdf->cnstx > 1000)
	{
		printf("return -1 ->  const x %d, consty  %d \n\n", fdf->cnstx * x, fdf->cnsty * y);
		// fdf->cnstx--;
		return (-1);
	}
	if (y * fdf->cnsty < 0 || y * fdf->cnsty > 1000 || y * fdf->cnsty > 1000)
	{
		
		printf("return -1 ->  const x %d, consty  %d \n\n", fdf->cnstx * x, fdf->cnsty * y);
		return (-1);
	}
	// if (f)
	// {
	// 	/* code */
	// }
	
	return (0);
}
static int	ft_calc_const(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map->ordinate)
	{
		j = 0;
		while (j < data->map->abscissa)
		{
			if (ft_is_outofscreen(data, j, i, data->map->matrix[i][j][0]) != 0)
			{
				if (data->cnstx > 1 && data->cnsty > 1)
				{
					data->cnstx--;
					data->cnsty--;
					data->center_y += 2;
					data->center += 2;
                    if (data->cnstx == 0)
                        data->cnstx = 1;
                    if (data->cnsty == 0)
                        data->cnsty = 1;
					// data->center++;
					return (-1);
				}
			}
			j++;
		}
		i++;
	}
	return (0);
}

static void	ft_center(t_data *data)
{
	float	i;
	float	d;
	int		z;

	// printf("data y %d \n",data->cnsty);
	z = data->map->matrix[data->map->ordinate / 2][data->map->abscissa / 2][0];
	i = ((data->map->abscissa / 2) - (data->map->ordinate / 2)) * cos(data->Xa);
	if ((500) > i)
		data->center = (1000 / 2 / data->cnstx) - i;
	else if ((1000 / 2) < i)
		data->center = i - (1000 / 2 / data->cnstx);
	data->center_y = 1000 / 3 / data->cnsty;
	if (data->cnsty == 2)
		data->center_y = 1;
		// data->center_y = data->win_h / 10 / data->cnsty;; 
	
}
void    bresenham_line(t_data *data, int x0, int y0, int x1, int y1, int color)
{
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = x0 < x1 ? 1 : -1;
    int sy = y0 < y1 ? 1 : -1;
    int err = dx - dy;

    while (1) 
	{
        put_pixel_img(data->img, x0, y0, color);
        if (x0 == x1 && y0 == y1)
			break;
        int e2 = err * 2;
        if (e2 > -dy) {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y0 += sy;
        }
    }
}

void draw_map(t_data *fdf)
{
    int x;
    int y;
	float x1;
	float y1;
    int color;
	float angle;
	int z;
	int x2;
	int x3;
	float tx2;
	float ty2;
	int y2;
	int y3;
	int z2;
	int z3;
	float	ty3;
	float	tx3;

	x = 0;
	y = 0;
	y2 = 0;
	y3 = 1;
	angle = fdf->Za;
	// ft_calc_const(fdf);
	// ft_center(fdf);
	// while (ft_calc_const(fdf) != 0)
    fdf->cnsty = 10;
    fdf->cnstx = 10;
	ft_center(fdf);
	fdf->center_y += fdf->center_y / 2;

    while (y < fdf->map->ordinate)
    {
        x = 0;
		x2 = x + 1;
		x3 = x;
        while (x < fdf->map->abscissa)
        {
			z = fdf->map->matrix[y][x][0];
			if (y2 < fdf->map->ordinate && x2 < fdf->map->abscissa)
				z2 = fdf->map->matrix[y2][x2][0];
			if (y3 < fdf->map->ordinate && x3 < fdf->map->abscissa)
				z3 = fdf->map->matrix[y3][x3][0];
			// printf("z :  %d\n", fdf->map->matrix[y][x][0]);
			color = fdf->map->matrix[y][x][1];
			if(color == -1)
				color = 0xFFFFFF;
			x1 = x;
			y1 = y;
			tx2 = x2;
			tx3 = x3;
			ty2 = y2;
			ty3 = y3;
			x1 = (x * cos(fdf->Xa) - y * sin(fdf->Ya));
			y1 = (x * sin(fdf->Xa) + y * cos(fdf->Ya));

			y1 = (y * sin(fdf->Ya) - z * cos(fdf->Za));

			tx2 = (x2 * cos(fdf->Xa) - y2 * sin(fdf->Ya));
			ty2 = (x2 * sin(fdf->Xa) + y2 * cos(fdf->Ya));
			ty2 = (y2 * sin(fdf->Ya) - z2 * cos(fdf->Za));
			
			tx3 = (x3 * cos(fdf->Xa) - y3 * sin(fdf->Ya));
			ty3 = (x3 * sin(fdf->Xa) + y3 * cos(fdf->Ya));
			ty3 = (y3 * sin(fdf->Ya) - z3 * cos(fdf->Za));


			x1 += fdf->center;
			y1 += fdf->center_y;
			tx2 += fdf->center;
			tx3 += fdf->center;
			ty2 += fdf->center_y;
			ty3 += fdf->center_y;
            // printf("pixel point x : %f,y : %f\n\n", x1 *fdf->cnstx, y1 *fdf->cnsty);
			put_pixel_img(fdf->img, x1 * fdf->cnstx, y1 * fdf->cnsty, color);

			if (y3 < fdf->map->ordinate && x3 < fdf->map->abscissa - 1)
				bresenham_line(fdf, x1 * fdf->cnstx, y1 * fdf->cnsty, tx3 * fdf->cnstx, ty3 * fdf->cnsty, color);
			if (y3 < fdf->map->ordinate && x3 < fdf->map->abscissa )
				bresenham_line(fdf, x1 * fdf->cnstx, y1 * fdf->cnsty, tx2 * fdf->cnstx, ty2 * fdf->cnsty, color);
            // mlx_pixel_put(fdf->mlx, fdf->win, x1 * fdf->cnstx, y1 * fdf->cnsty, color);
			
			x++;
			x2++;
			x3++;
        }
        y++;
        y2++;
        y3++;
    }
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img.img_ptr, 0, 0);
}
