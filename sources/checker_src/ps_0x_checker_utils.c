/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_0x_checker_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdouniol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 13:23:05 by jdouniol          #+#    #+#             */
/*   Updated: 2019/01/23 19:01:44 by jdouniol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ps_0x_checker_utils.c                                    |
**   |     ft_free_two(5 lines)                                 |
**   |     ft_transit_int(3 lines)                              |
**   |     size_of_args(17 lines)                               |
**   |     ft_init_to_null(3 lines)                             |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include <stdlib.h>

char	*ft_free_two(void *ptr1, void *ptr2)
{
	if (ptr1)
		free(ptr1);
	if (ptr2)
		free(ptr2);
	return (NULL);
}

int		ft_transit_int(int nbr, char *str)
{
	if (str)
		free(str);
	return (nbr);
}

size_t	size_of_args(char **av)
{
	size_t	i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	while (av && av[k])
	{
		j = 0;
		while (av[k][j])
		{
			j++;
			i++;
		}
		k++;
	}
	return (i);
}

void	ft_init_to_null(char **str, int *nb1, int *nb2)
{
	*str = NULL;
	*nb1 = 0;
	*nb2 = 0;
}
