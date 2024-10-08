/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenquin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 23:01:50 by drenquin          #+#    #+#             */
/*   Updated: 2024/10/07 18:41:50 by drenquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	targ_b(t_node **hb, t_node **tb, t_node **ta, t_node **ha)
{
	t_node	*ca;
	t_node	*t;
	t_node	*bf;

	ca = (*ta);
	while (ca != NULL)
	{
		t = (*tb);
		bf = NULL;
		while (t != NULL)
		{
			if (t->val <= ca->val && (bf == NULL || t->val > bf->val))
				bf = t;
			t = t->next;
		}
		if (bf != NULL)
		{
			ca->cost += bf->cost;
			ca->target_val = bf->val;
		}
		else
			targ_b1(bf, tb, ca);
		ca->cost -= 1;
		ca = ca->next;
	}
}

void	targ_b1(t_node *best_fit, t_node **tailb, t_node *curra)
{
	best_fit = find_max(*tailb);
	curra->cost += best_fit->cost;
	curra->target_val = best_fit->val;
}

t_node	*find_max(t_node *stack_b)
{
	t_node	*max_node;
	t_node	*current;

	if (stack_b == NULL)
		return (NULL);
	max_node = stack_b;
	current = stack_b->next;
	while (current != NULL)
	{
		if (current->val > max_node->val)
		{
			max_node = current;
		}
		current = current->next;
	}
	return (max_node);
}

void	costa(t_node **hb, t_node **tb, t_node **ta, t_node **ha)
{
	costup(ta);
	costdown(ha, ta);
	costup(tb);
	costdown(hb, tb);
	targ_b(hb, tb, ta, ha);
	median_a(ta);
	median_b(tb);
}

void	push_m(t_node **hb, t_node **tb, t_node **ta, t_node **ha)
{
	costa(hb, tb, ta, ha);
	a_to_b(hb, tb, ta, ha);
	a_to_b1(hb, tb, ta, ha);
	pb(ta, tb, hb);
	if (count_node(*ta) <= 3)
	{
		sorted3(ta, ha);
		return ;
	}
	push_m(hb, tb, ta, ha);
	return ;
}
