/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_0x_debug.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdouniol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 17:44:07 by jdouniol          #+#    #+#             */
/*   Updated: 2019/01/23 19:03:25 by jdouniol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ps_0x_debug.c                                            |
**   |     ft_print_array(25 lines)                             |
**   |     ft_print_struct(16 lines)                            |
**   |     ft_check_double(20 lines)                            |
**   |     ft_error_and_exit(2 lines)                           |
**   |     ft_error(1 lines)                                    |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include "../../includes/push_swap.h"

void	ft_print_array(t_mega *elem)
{
	int i;
	int j;
	int show_a;
	int show_b;

	i = -1;
	j = -1;
	show_a = 0;
	show_b = 0;
	while (++i < elem->size_a)
	{
		if (!show_a)
			ft_printf("pile_A:\n");
		show_a = 1;
		ft_printf("A[%d]~ %d ~\n", i, elem->pile_a[i]);
	}
	ft_printf("\n");
	while (++j < elem->size_b)
	{
		if (!show_b)
			ft_printf("pile_B:\n");
		show_b = 1;
		ft_printf("B[%d]~ %d ~\n", j, elem->pile_b[j]);
	}
	ft_printf("\n");
}

void	ft_print_struct(t_mega *elem)
{
	ft_print_array(elem);
	ft_printf("Infos Struct:\n");
	ft_printf("min_a = %d\n", elem->min_a);
	ft_printf("index min a = %d\n", elem->index_min_a);
	ft_printf("max a = %d\n", elem->max_a);
	ft_printf("index max a = %d\n", elem->index_max_a);
	ft_printf("min b = %d\n", elem->min_b);
	ft_printf("index min b = %d\n", elem->index_min_b);
	ft_printf("max b = %d\n", elem->max_b);
	ft_printf("index max b = %d\n", elem->index_max_b);
	ft_printf("size a = %d\n", elem->size_a);
	ft_printf("size b = %d\n", elem->size_b);
	ft_printf("size max = %d\n", elem->size_max);
	ft_printf("approx min b a = %d\n", elem->approx_min_value);
	ft_printf("index approx min b = %d\n", elem->index_approx_min);
	ft_printf("Reste a faire le average index\n");
}

int		ft_check_double(t_mega *elem)
{
	int i;
	int j;

	i = 0;
	j = 1;
	while (i < elem->size_a)
	{
		while ((i + j) < elem->size_a)
		{
			if (elem->pile_a[i] == elem->pile_a[i + j])
				return (-1);
			j++;
		}
		i++;
		j = 1;
	}
	if (i == elem->size_a)
		return (0);
	else
		return (-1);
}

void	ft_error_and_exit(void)
{
	ft_printf("ERROR\n");
	exit(0);
}

void	ft_error(void)
{
	ft_printf("ERROR\n");
}
