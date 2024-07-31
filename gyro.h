/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gyro.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-taja <het-taja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 10:44:48 by het-taja          #+#    #+#             */
/*   Updated: 2024/07/31 11:04:24 by het-taja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <unistd.h>
#include <readline/readline.h>
#include <fcntl.h>
#include <stdlib.h>



typedef struct s_data
{
    int Xa;  
    int Ya;  
    int Za;
    void    *mlx;
    void    *win;
    void    *img;
}        t_data;




// parsing funcs 

void    parce(t_data *data, char *cord);
char	**ft_split(char const *s, char c);
char	*ft_strdup(char *s);
int	ft_strlen(char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int	ft_atoi(const char *nptr);
