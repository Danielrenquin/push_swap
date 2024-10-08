/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenquin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 18:02:50 by drenquin          #+#    #+#             */
/*   Updated: 2024/10/07 20:29:31 by drenquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_to_b(t_node **hb, t_node **tb, t_node **ta, t_node **ha)
{
	t_node	*tmp;
	t_node	*targ;

	tmp = to_s(hb, tb, ta, ha);
	targ = find_node((*tb), tmp->target_val);
	if (tmp->median == 1 && targ->median == 1)
	{
		while ((*ta)->val != tmp->val && (*tb)->val != targ->val)
			rr(ta, ha, tb, hb);
		while ((*ta)->val != tmp->val)
			ra(ta, ha);
		while ((*tb)->val != targ->val)
			rb(tb, hb);
	}
	else if (tmp->median == 0 && targ->median == 0)
	{
		while ((*ta)->val != tmp->val && (*tb)->val != targ->val)
			rrr(ta, ha, tb, hb);
		while ((*ta)->val != tmp->val)
			rra(ta, ha);
		while ((*tb)->val != targ->val)
			rrb(tb, hb);
	}
	return ;
}

void	a_to_b1(t_node **hb, t_node **tb, t_node **ta, t_node **ha)
{
	t_node	*tmp;
	t_node	*targ;

	tmp = to_s(hb, tb, ta, ha);
	targ = find_node((*tb), tmp->target_val);
	if (tmp->median != targ->median)
	{
		while ((*ta)->val != tmp->val)
		{
			if (tmp->median == 1)
				ra(ta, ha);
			else
				rra(ta, ha);
		}
		while ((*tb)->val != targ->val)
		{
			if (targ->median == 1)
				rb(tb, hb);
			else
				rrb(tb, hb);
		}
	}
	return ;
}
