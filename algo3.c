/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenquin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 14:12:38 by drenquin          #+#    #+#             */
/*   Updated: 2024/10/07 20:34:00 by drenquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*low_cost(t_node *tailb)
{
	t_node	*current;
	t_node	*min_cost_node;

	if (tailb == NULL)
		return (NULL);
	min_cost_node = tailb;
	current = tailb->next;
	while (current != NULL)
	{
		if (current->cost < min_cost_node->cost)
		{
			min_cost_node = current;
		}
		current = current->next;
	}
	return (min_cost_node);
}

void	costb(t_node **ta, t_node **ha, t_node **tb, t_node **hb)
{
	costup(ta);
	costdown(ha, ta);
	costup(tb);
	costdown(hb, tb);
	targ_a(hb, tb, ta, ha);
	median_a(ta);
	median_b(tb);
}

void	push_b(t_node **ta, t_node **ha, t_node **tb, t_node **hb)
{
	costb(ta, ha, tb, hb);
	b_to_a(hb, tb, ta, ha);
	b_to_a1(hb, tb, ta, ha);
	pa(ta, tb, ha);
	if ((*tb) == NULL)
		return ;
	push_b(ta, ha, tb, hb);
	return ;
}

void	b_to_a(t_node **hb, t_node **tb, t_node **ta, t_node **ha)
{
	t_node	*tmp;
	t_node	*target;

	tmp = low_cost(*tb);
	target = find_node((*ta), tmp->target_val);
	if (tmp->median == 1 && target->median == 1)
	{
		while ((*tb)->val != tmp->val && (*ta)->val != target->val)
			rr(ta, ha, tb, hb);
		while ((*tb)->val != tmp->val)
			rb(tb, hb);
		while ((*ta)->val != target->val)
			ra(ta, ha);
	}
	else if (tmp->median == 0 && target->median == 0)
	{
		while ((*tb)->val != tmp->val && (*ta)->val != target->val)
			rrr(ta, ha, tb, hb);
		while ((*tb)->val != tmp->val)
			rrb(tb, hb);
		while ((*ta)->val != target->val)
			rra(ta, ha);
	}
	return ;
}

void	b_to_a1(t_node **hb, t_node **tb, t_node **ta, t_node **ha)
{
	t_node	*tmp;
	t_node	*target;

	tmp = low_cost(*tb);
	target = find_node((*ta), tmp->target_val);
	if (tmp->median != target->median)
	{
		while ((*tb)->val != tmp->val)
		{
			if (tmp->median == 1)
				rb(tb, hb);
			else
				rrb(tb, hb);
		}
		while ((*ta)->val != target->val)
		{
			if (target->median == 1)
				ra(ta, ha);
			else
				rra(ta, ha);
		}
	}
	return ;
}
