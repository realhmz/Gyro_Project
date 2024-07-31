/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-taja <het-taja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 11:03:43 by het-taja          #+#    #+#             */
/*   Updated: 2024/07/31 11:20:54 by het-taja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gyro.h"

void    init(t_data *data)
{
    data->mlx = mlx_init();
    data->win = mlx_new_window(data->mlx, 1000, 1000, "Gyro");
    data->img = new_img(1000, 1000, data);
}
void    render(t_data *data)
{
    int i = 0;
    while (i < 100)
    {
        put_pixel_img(data->img, data->Xa +i,data->Ya, 0xFFD700);
        i++;
    }
    
    mlx_put_image_to_window(data->mlx, data->win, data->img.img_ptr, 0, 0);
}

void	put_pixel_img(t_img img, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && y >= 0 && x < img.w && y < img.h)
	{
		dst = img.addr + (y * img.line_len + x * (img.bpp / 8));
		*(unsigned int *) dst = color;
	}
}
t_img	new_img(int w, int h, t_data *window)
{
	t_img	image;

	image.win = window;
	image.img_ptr = mlx_new_image(window->mlx, w, h);
	image.addr = mlx_get_data_addr(image.img_ptr, &(image.bpp),
			&(image.line_len), &(image.endian));
	image.w = w;
	image.h = h;
	return (image);
}