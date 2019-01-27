/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_03d_sesolve_actualize.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdouniol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 17:43:04 by jdouniol          #+#    #+#             */
/*   Updated: 2019/01/10 17:43:04 by jdouniol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ps_03d_sesolve_actualize.c                               |
**   |     ft_value_next_twentieme2(17 lines)                   |
**   |     ft_id_next_twentieme2(11 lines)                      |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include "../../includes/push_swap.h"

void	ft_value_next_twentieme2(t_mega *elem, int twentieme)
{
	int i;

	i = -1;
	while (++i < elem->size_a)
	{
		if (elem->pile_a[i] > twentieme)
			continue;
		else
		{
			elem->value_next_twentieme = elem->pile_a[i];
			break ;
		}
	}
	if (i == elem->size_a)
	{
		elem->value_next_twentieme = ft_get_twentieme(elem);
	}
}

void	ft_id_next_twentieme2(t_mega *elem, int twentieme)
{
	int index;

	index = -1;
	while (++index < elem->size_a)
	{
		if (elem->pile_a[index] > twentieme)
			continue;
		else
			break ;
	}
	elem->index_next_twentieme = index;
}
