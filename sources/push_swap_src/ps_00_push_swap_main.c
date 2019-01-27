/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_00_push_swap_main.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdouniol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 17:41:25 by jdouniol          #+#    #+#             */
/*   Updated: 2019/01/23 19:02:09 by jdouniol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ps_00_push_swap_main.c                                   |
**   |     ft_free_mega(3 lines)                                |
**   |     ft_str_is_full_of_space(19 lines)                    |
**   |     main(25 lines)                                       |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include "../../includes/push_swap.h"

void			ft_free_mega(t_mega *elem)
{
	free(elem->pile_a);
	free(elem->pile_b);
	free(elem);
}

struct s_mega	*ft_init_struct(char *str)
{
	struct s_mega	*new;
	int				*first_array;

	if (!(new = malloc(sizeof(t_mega))))
		return (NULL);
	if ((first_array = ft_str_to_int_array(str, ' ')))
	{
		new->pile_a = first_array;
		if (!(new->pile_b = malloc(sizeof(int) * ft_nbi(str, ' '))))
			return (NULL);
		new->size_a = ft_nbi(str, ' ');
		new->min_a = ft_min_pile_a(new);
		new->index_min_a = ft_id_min_pile_a(new);
		new->max_a = ft_max_pile_a(new);
		new->index_max_a = ft_id_max_pile_a(new);
		new->size_b = 0;
		new->size_max = ft_nbi(str, ' ');
		new->big_min = new->min_a;
		new->big_max = new->max_a;
		return (new);
	}
	else
		return (NULL);
}

int				ft_str_is_full_of_space(int ac, char **av)
{
	int i;
	int j;

	i = 1;
	j = 0;
	(void)ac;
	while (av[i])
	{
		while (av[i][j] == ' ' || av[i][j] == '\t')
			j++;
		if (av[i][j] == '\0')
		{
			j = 0;
			i++;
		}
		else
			return (0);
	}
	return (1);
}

int				main(int argc, char *argv[])
{
	t_mega	*elem;
	char	*str;

	if (argc == 1 || ft_str_is_full_of_space(argc, argv))
		return (0);
	else if (argc >= 2)
	{
		str = ft_all_in_one_str(argc, argv);
		if (str)
		{
			elem = ft_init_struct(str);
			if (elem)
			{
				if (ft_check_double(elem))
					ft_error_and_exit();
				else
					ft_resolve(elem);
			}
			else
				ft_error_and_exit();
			ft_free_mega(elem);
			free(str);
		}
	}
	return (0);
}
