/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenquin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 18:18:05 by drenquin          #+#    #+#             */
/*   Updated: 2024/10/07 16:48:24 by drenquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	costup(t_node **taila)
{
	int		lst_size;
	int		median;
	int		i;
	t_node	*curr;

	i = 1;
	curr = (*taila);
	lst_size = count_node(*taila);
	if ((lst_size % 2) == 0)
		median = (lst_size / 2) + 1;
	else
		median = ((lst_size + 1) / 2);
	while (i <= median)
	{
		curr->cost = i;
		curr = curr->next;
		i++;
	}
}

void	costdown(t_node **heada, t_node **taila)
{
	int		lst_size;
	int		median;
	int		i;
	t_node	*curr;

	i = 2;
	curr = (*heada);
	lst_size = count_node(*taila);
	if ((lst_size % 2) == 0)
		median = (lst_size / 2) + 1;
	else
		median = ((lst_size + 1) / 2);
	while (i <= median)
	{
		curr->cost = i;
		curr = curr->prev;
		i++;
	}
}

t_node	*to_s(t_node **hb, t_node **tb, t_node **ta, t_node **ha)
{
	t_node	*curra;
	int		i;

	i = 1;
	curra = (*ta);
	if ((*tb)->next->val == (*hb)->val)
	{
		if (is_sorted(*tb))
			rb(tb, hb);
	}
	while (curra != NULL)
	{
		curra = curra->next;
		if (curra == NULL)
		{
			curra = (*ta);
			i++;
		}
		if (curra->cost == i)
			return (curra);
	}
	return (NULL);
}

void	targ_a1(t_node *best_fit, t_node **taila, t_node *currb)
{
	best_fit = find_min(*taila);
	currb->cost += best_fit->cost;
	currb->target_val = best_fit->val;
}
