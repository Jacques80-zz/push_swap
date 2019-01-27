/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_03_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdouniol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 10:18:39 by jdouniol          #+#    #+#             */
/*   Updated: 2019/01/23 19:01:30 by jdouniol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ps_03_instructions.c                                     |
**   |     ft_check_sort(19 lines)                              |
**   |     ft_get_instruction2(15 lines)                        |
**   |     ft_get_instruction(17 lines)                         |
**   |     ft_apply_instruct_and_check_sort(25 lines)           |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include "../../includes/push_swap.h"

int		ft_check_sort(t_mega *elem)
{
	int i;

	i = -1;
	while ((++i) < (elem->size_a))
	{
		if ((i + 1 != (elem->size_a) && elem->pile_a[i] < elem->pile_a[i + 1])
			|| ((i + 1) == (elem->size_a)))
		{
			continue ;
		}
		else
		{
			break ;
		}
	}
	if (i == elem->size_a)
		return (1);
	else
		return (0);
}

t_mega	*ft_get_instruction2(t_mega *elem, char *arg)
{
	if (ft_strcmp(arg, "ra") == 0)
		ft_ra(elem);
	else if (ft_strcmp(arg, "rb") == 0)
		ft_rb(elem);
	else if (ft_strcmp(arg, "rr") == 0)
		ft_rr(elem);
	else if (ft_strcmp(arg, "rra") == 0)
		ft_rra(elem);
	else if (ft_strcmp(arg, "rrb") == 0)
		ft_rrb(elem);
	else if (ft_strcmp(arg, "rrr") == 0)
		ft_rrr(elem);
	else
		ft_error_and_exit();
	return (elem);
}

t_mega	*ft_get_instruction(t_mega *elem, char *arg)
{
	if (ft_strcmp(arg, "sa") == 0)
		ft_sa(elem);
	else if (ft_strcmp(arg, "sb") == 0)
		ft_sb(elem);
	else if (ft_strcmp(arg, "ss") == 0)
		ft_ss(elem);
	else if (ft_strcmp(arg, "pa") == 0)
		ft_pa(elem);
	else if (ft_strcmp(arg, "pb") == 0)
		ft_pb(elem);
	else if (ft_strcmp(arg, "debug") == 0)
	{
		ft_print_array(elem);
	}
	else
		ft_get_instruction2(elem, arg);
	return (elem);
}

void	ft_apply_instruct_and_check_sort(t_mega *elem)
{
	char	*arg;
	int		ret;
	t_mega	*new;
	int		not_first;

	not_first = 0;
	while ((ret = get_next_line(STDIN_FILENO, &arg)) == 1)
	{
		if (!(not_first++))
			new = ft_get_instruction(elem, arg);
		else
			new = ft_get_instruction(new, arg);
		free(arg);
	}
	if (ret == 0)
	{
		if (!(not_first))
			(ft_check_sort(elem) && elem->size_b == 0) ? ft_printf("OK\n")
				: ft_printf("KO\n");
		else
			(ft_check_sort(new) && elem->size_b == 0) ? ft_printf("OK\n")
				: ft_printf("KO\n");
	}
	if (ret == -1)
		ft_printf("ERROR\n");
}
