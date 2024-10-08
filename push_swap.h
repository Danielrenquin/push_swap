/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenquin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 22:50:15 by drenquin          #+#    #+#             */
/*   Updated: 2024/10/08 16:54:25 by drenquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "lib/ftprintf/ft_printf.h"
# include "lib/libft/libft.h"
# include <unistd.h>
# include <stdlib.h>

typedef struct s_node
{
	int				val;
	int				target_val;
	int				cost;
	int				median;
	int				index;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_list
{
	int				len;
	struct s_node	*head;
	struct s_node	*tails;
}	t_list;

typedef struct s_split
{
	char	**tab;
	int		count;
	int		i;
	int		j;
	int		k;
}	t_split;

int			check_in(int argc, char **argv);
long int	ft_atoi_lg(char *str);
int			overflow(int argc, char **argv);
int			only_num(char *str);
int			no_double(int argc, char **argv);
int			no_double1(int argc, int *tab);
char		*ft_strncpy(char *s1, const char *s2, int n);
int			count_one_more(char *str);
int			init_split(char *str, t_split *s);
char		**split_one_arg(char *str, t_split *s);
void		free_split_result(char **tab);
void		deallocate(t_node **tail, t_node **head);
void		init(t_node **tail, t_node **head, int x);
void		add_end(t_node **head, int x);
void		reverse(t_node **tail, t_node **head);
t_node		*find_node(t_node *tail, int x);
void		sa(t_node **tail_a, t_node **head_a);
void		sb(t_node **tail_b, t_node **head_b);
void		ss(t_node **taila, t_node **heada, t_node **tailb, t_node **headb);
void		pa(t_node **tail_a, t_node **tail_b, t_node **head_a);
void		pb(t_node **tail_a, t_node **tail_b, t_node **head_b);
void		ra(t_node **tail_a, t_node **head_a);
void		rb(t_node **tail_b, t_node **head_b);
void		rr(t_node **taila, t_node **heada, t_node **tailb, t_node **headb);
void		rra(t_node **tail_a, t_node **head_a);
void		rrb(t_node **tail_b, t_node **head_b);
void		rrr(t_node **taila, t_node **heada, t_node **tailb, t_node **headb);
void		make_list(int argc, char **argv, t_node **head_a, t_node **taila);
void		make_list2(char **argv, t_node **heada, t_node **taila);
int			count_node(t_node *tail);
int			is_sorted(t_node *tail);
void		sorted(t_node **ta, t_node **ha, t_node **tb, t_node **hb);
void		sorted3(t_node **taila, t_node **heada);
int			find_bigger(t_node *taila);
void		sorted4(t_node **ta, t_node **ha, t_node **tb, t_node **hb);
void		update_headb(t_node **tailb, t_node **headb);
int			bigger_val(t_node *tailb);
int			smaller_val(t_node *tailb);
void		costup(t_node **taila);
void		costdown(t_node **heada, t_node **taila);
t_node		*to_s(t_node **hb, t_node **tb, t_node **ta, t_node **ha);
void		push_m(t_node **hb, t_node **tb, t_node **ta, t_node **ha);
void		third(t_node **ta, t_node **ha, t_node **tb, t_node **hb);
void		push_b(t_node **ta, t_node **ha, t_node **tb, t_node **hb);
void		median_a(t_node **taila);
void		median_b(t_node **tailb);
void		targ_b(t_node **hb, t_node **tb, t_node **ta, t_node **ha);
t_node		*find_max(t_node *stack_b);
void		smaler_top(t_node **taila, t_node **heada);
void		targ_a(t_node **hb, t_node **tb, t_node **ta, t_node **ha);
t_node		*find_min(t_node *stack_a);
t_node		*low_cost(t_node *tailb);
void		targ_a1(t_node *best_fit, t_node **taila, t_node *currb);
void		targ_b1(t_node *best_fit, t_node **tailb, t_node *curra);
void		costa(t_node **hb, t_node **tb, t_node **ta, t_node **ha);
void		a_to_b(t_node **hb, t_node **tb, t_node **ta, t_node **ha);
void		a_to_b1(t_node **hb, t_node **tb, t_node **ta, t_node **ha);
void		costb(t_node **ta, t_node **ha, t_node **tb, t_node **hb);
void		b_to_a(t_node **hb, t_node **tb, t_node **ta, t_node **ha);
void		b_to_a1(t_node **hb, t_node **tb, t_node **ta, t_node **ha);
void		mouv2(t_node **ta, t_node **tb, t_node **hb);
void		rra1(t_node **tail_a, t_node **head_a);
void		rrb1(t_node **tail_b, t_node **head_b);
void		ra1(t_node **tail_a, t_node **head_a);
void		rb1(t_node **tail_b, t_node **head_b);
#endif
