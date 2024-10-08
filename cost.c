/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenquin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 19:11:34 by drenquin          #+#    #+#             */
/*   Updated: 2024/10/04 19:26:28 by drenquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	update_headb(t_node **tailb, t_node **headb)
{
	t_node	*current;

	current = *tailb;
	while (current && current->next != NULL)
	{
		current = current->next;
	}
	*headb = current;
}

int	bigger_val(t_node *tailb)
{
	t_node	*curr;
	int		big_b;

	curr = tailb;
	big_b = tailb->val;
	while (curr != NULL)
	{
		if (curr->val > big_b)
			big_b = curr->val;
		curr = curr->next;
	}
	return (big_b);
}

int	smaller_val(t_node *tailb)
{
	t_node	*curr;
	int		small_b;

	curr = tailb;
	small_b = tailb->val;
	while (curr != NULL)
	{
		if (curr->val < small_b)
			small_b = curr->val;
		curr = curr->next;
	}
	return (small_b);
}

void	smaler_top(t_node **taila, t_node **heada)
{
	int			small_a;
	t_node		*smaller;

	small_a = smaller_val(*taila);
	smaller = find_node((*taila), small_a);
	while ((*taila)->val != small_a)
	{
		if (smaller->median == 1)
			ra(taila, heada);
		else if (smaller->median == 0)
			rra(taila, heada);
	}
	return ;
}
