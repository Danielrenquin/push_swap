/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenquin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 16:33:23 by drenquin          #+#    #+#             */
/*   Updated: 2024/10/07 17:06:31 by drenquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	targ_a(t_node **hb, t_node **tb, t_node **ta, t_node **ha)
{
	t_node	*cb;
	t_node	*t;
	t_node	*bf;

	cb = (*tb);
	while (cb != NULL)
	{
		t = (*ta);
		bf = NULL;
		while (t != NULL)
		{
			if (t->val >= cb->val && (bf == NULL || t->val < bf->val))
				bf = t;
			t = t->next;
		}
		if (bf != NULL)
		{
			cb->cost += bf->cost;
			cb->target_val = bf->val;
		}
		else
			targ_a1(bf, ta, cb);
		cb->cost += 1;
		cb = cb->next;
	}
}

t_node	*find_min(t_node *stack_a)
{
	t_node	*min_node;
	t_node	*current;

	if (stack_a == NULL)
		return (NULL);
	min_node = stack_a;
	current = stack_a->next;
	while (current != NULL)
	{
		if (current->val < min_node->val)
		{
			min_node = current;
		}
		current = current->next;
	}
	return (min_node);
}
