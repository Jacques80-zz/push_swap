/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_03_resolve.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdouniol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 17:41:47 by jdouniol          #+#    #+#             */
/*   Updated: 2019/01/10 17:41:47 by jdouniol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ps_03_resolve.c                                          |
**   |     ft_resolve(19 lines)                                 |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include "../../includes/push_swap.h"

void	ft_resolve(t_mega *elem)
{
	if (PRINT_MODE)
		ft_print_array(elem);
	if (!(ft_check_sort_ps(elem)))
	{
		if (elem->size_a == 0 || elem->size_a == 1)
			return ;
		else if (elem->size_a >= 2 && elem->size_a <= 3)
			ft_sort_very_small(elem);
		else if (elem->size_a >= 4 && elem->size_a <= 6)
			ft_sort_small(elem);
		else if (elem->size_a >= 7 && elem->size_a <= 40)
			ft_do_it_twice_medium(elem);
		else if (elem->size_a >= 41 && elem->size_a <= 200)
			ft_do_it_twice(elem);
		else if (elem->size_a >= 201)
			ft_do_it_twice2(elem);
	}
	if (PRINT_MODE)
		ft_print_array(elem);
	if (ft_check_sort_ps(elem))
		ft_printf("\0");
}
