/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdouniol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 14:57:19 by jdouniol          #+#    #+#             */
/*   Updated: 2018/12/18 14:57:21 by jdouniol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "ft_printf.h"

# define PRINT_MODE 0

typedef	struct		s_mega
{
	int				*pile_a;
	int				*pile_b;
	int				min_a;
	int				index_min_a;
	int				max_a;
	int				index_max_a;
	int				min_b;
	int				index_min_b;
	int				max_b;
	int				index_max_b;
	int				size_a;
	int				size_b;
	int				size_max;
	int				big_min;
	int				big_max;
	int				value_next_twentieme;
	int				index_next_twentieme;
	int				approx_plus_value;
	int				approx_min_value;
	int				index_approx_plus;
	int				index_approx_min;
}					t_mega;

/*
**	PS_01 Gere les arguments pour checker et push swap
*/
char				*ft_all_in_one_str(int ac, char **av);
int					*ft_str_to_int_array(char const *s, char c);
int					ft_check_double(t_mega *elem);

/*
**	Outils pour la structure necessaire pour checker et push swap
*/

int					ft_nbi(char const *s, char c);
int					ft_id_max_pile_a(t_mega *elem);
int					ft_id_max_pile_b(t_mega *elem);
int					ft_id_min_pile_b(t_mega *elem);
int					ft_id_min_pile_a(t_mega *elem);
int					ft_min_pile_a(t_mega *elem);
int					ft_min_pile_b(t_mega *elem);
int					ft_max_pile_a(t_mega *elem);
int					ft_max_pile_b(t_mega *elem);
int					ft_average_pile_a(t_mega *elem);
int					ft_average_pile_b(t_mega *elem);

/*
**		Prend les instructions et les traite pour checker
*/

t_mega				*ft_get_instruction(t_mega *elem, char *arg);
void				ft_apply_instruct_and_check_sort(t_mega *elem);

/*
**	Print et debug pour checker et push swap
*/
void				ft_print_array(t_mega *elem);
void				ft_print_struct(t_mega *elem);
void				ft_error(void);
void				ft_error_and_exit(void);

/*
**	Instructions pour checker et push swap
*/

t_mega				*ft_sa(t_mega *elem);
t_mega				*ft_sb(t_mega *elem);
t_mega				*ft_ss(t_mega *elem);
t_mega				*ft_pa(t_mega *elem);
t_mega				*ft_pb(t_mega *elem);
t_mega				*ft_ra(t_mega *elem);
t_mega				*ft_rb(t_mega *elem);
t_mega				*ft_rr(t_mega *elem);
t_mega				*ft_rra(t_mega *elem);
t_mega				*ft_rrb(t_mega *elem);
t_mega				*ft_rrr(t_mega *elem);

/*
**	Resolve necessaire pour push swap
*/

void				ft_resolve(t_mega *elem);
void				ft_do_it_twice(t_mega *elem);
int					ft_pile_b_is_sort2(t_mega *elem);
int					ft_pile_a_is_sort2(t_mega *elem);
int					ft_pile_b_is_decrease_sort(t_mega *elem);
int					ft_get_twentieme(t_mega *elem);
void				ft_get_the_rest(t_mega *elem, int twentieme);
void				ft_actualize_infos3(t_mega *elem, int twentieme);
char				*ft_free_two(void *ptr1, void *ptr2);
int					ft_transit_int(int nbr, char *str);
void				ft_init_to_null(char **str, int *nb1, int *nb2);
void				ft_do_it_last(t_mega *elem);
void				ft_sort_pile_a(t_mega *elem);
void				ft_manage_pb2(t_mega *elem);
void				ft_do_it_twice_medium(t_mega *elem);
void				ft_get_the_rest_medium(t_mega *elem, int minus_three);
int					ft_get_minus_three(t_mega *elem);
void				ft_sort_pile_b_decreas(t_mega *elem);
void				ft_sort_pile_b_decreas_small(t_mega *elem);
int					ft_check_sort_ps(t_mega *elem);
void				ft_sort_small(t_mega *elem);
void				ft_sort_very_small(t_mega *elem);
int					ft_check_sort2(t_mega *elem);
void				ft_sort_very_small2(t_mega *elem);
void				ft_manage_pb2(t_mega *elem);
void				ft_value_next_twentieme2(t_mega *elem, int twentieme);
void				ft_id_next_twentieme2(t_mega *elem, int twentieme);
size_t				size_of_args(char **av);
int					ft_get_fiftieme(t_mega *elem);
void				ft_do_it_last(t_mega *elem);
void				ft_get_the_rest2(t_mega *elem, int fiftieme);
void				ft_do_it_twice2(t_mega *elem);
int					ft_get_minus_three(t_mega *elem);

#endif
