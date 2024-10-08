/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted_small.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenquin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 11:29:24 by drenquin          #+#    #+#             */
/*   Updated: 2024/10/07 23:27:07 by drenquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	sorted(t_node **ta, t_node **ha, t_node **tb, t_node **hb)
{
	unsigned int		size;
	t_node				*tmp;

	if (is_sorted(*ta))
		return ;
	size = count_node(*ta);
	if (size == 2)
		ra(ta, ha);
	else if (size == 3)
		sorted3(ta, ha);
	else if (size == 4)
		sorted4(ta, ha, tb, hb);
	else if (size > 4)
	{
		pb(ta, tb, hb);
		pb(ta, tb, hb);
		third(ta, ha, tb, hb);
		push_m(hb, tb, ta, ha);
		push_b(ta, ha, tb, hb);
		smaler_top(ta, ha);
	}
	return ;
}

void	sorted3(t_node **taila, t_node **heada)
{
	int	num1;
	int	num2;
	int	num3;

	num1 = (*taila)->val;
	num2 = (*taila)->next->val;
	num3 = (*taila)->next->next->val;
	if ((num1 > num2) && (num1 > num3))
		ra(taila, heada);
	else if ((num1 < num2) && (num2 > num3))
		rra(taila, heada);
	if (is_sorted(*taila))
		return ;
	else
		sa(taila, heada);
	return ;
}

int	find_bigger(t_node *taila)
{
	t_node		*curr;
	int			i;
	int			curr_i;
	int			bigger;

	i = 0;
	curr_i = 0;
	bigger = taila->val;
	curr = taila->next;
	while (curr != NULL)
	{
		curr_i++;
		if (curr->val > bigger)
		{
			bigger = curr->val;
			i = curr_i;
		}
		curr = curr->next;
	}
	return (i);
}

void	sorted4(t_node **ta, t_node **ha, t_node **tb, t_node **hb)
{
	int	pos_big;

	pos_big = find_bigger(*ta);
	if (pos_big == 0)
		pb(ta, tb, hb);
	else if (pos_big == 1)
	{
		ra(ta, ha);
		pb(ta, tb, hb);
	}
	else if (pos_big == 2)
	{
		ra(ta, ha);
		ra(ta, ha);
		pb(ta, tb, hb);
	}
	else if (pos_big == 3)
	{
		rra(ta, ha);
		pb(ta, tb, hb);
	}
	sorted3(ta, ha);
	pa(ta, tb, ha);
	ra(ta, ha);
	return ;
}
