/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-taja <het-taja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 17:38:26 by het-taja          #+#    #+#             */
/*   Updated: 2024/07/31 18:33:50 by het-taja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    int fd = open("out", O_RDWR);
    float i = 0;
    float j = 0.5;
    float k = 0;
    while (i <= 10)
    {
        // if (i >= 0.5)
        //     j += 0.05;
        // if (j >= 0.5)
        //     k += 0.05;
        i += 0.02;
        printf("%f , %f , %f \n",i,j,k);
        // usleep(400000);
    }
    while (i >= 0)
    {
        i -= 0.02;
        j += 0.02;
        printf("%f , %f , %f \n",i,j,k);
    }
    while (j >= 0)
    {
        j -= 0.02;
        printf("%f , %f , %f \n",i,j,k);

    }
    
    
    
        
}