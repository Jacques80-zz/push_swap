/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdouniol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 20:13:40 by jdouniol          #+#    #+#             */
/*   Updated: 2017/11/20 21:24:26 by jdouniol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*ft_strcpy(char *dest, const char *src)
{
	int		i;

	i = -1;
	while (src[++i] && i != (int)ft_strlen(src))
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}
