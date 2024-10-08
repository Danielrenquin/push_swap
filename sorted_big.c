/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted_big.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenquin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:50:02 by drenquin          #+#    #+#             */
/*   Updated: 2024/10/08 15:36:53 by drenquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	third(t_node **ta, t_node **ha, t_node **tb, t_node **hb)
{
	int	big_b;
	int	small_b;

	big_b = bigger_val((*tb));
	small_b = smaller_val((*tb));
	while (count_node(*ta) > 3 && !is_sorted(*ta))
	{
		if ((*ta)->val > big_b || (*ta)->val < small_b)
		{
			if ((*tb)->val == big_b)
				pb(ta, tb, hb);
			else
				mouv2(ta, tb, hb);
			return ;
		}
		else
		{
			if ((*tb)->val == big_b)
				mouv2(ta, tb, hb);
			else
				pb(ta, tb, hb);
			return ;
		}
	}
}

void	median_a(t_node **taila)
{
	int			i;
	int			median;
	t_node		*curra;

	i = 0;
	curra = (*taila);
	if (curra == NULL)
		return ;
	median = count_node(*taila) / 2;
	while (curra != NULL)
	{
		curra->index = i;
		if (i <= median)
			curra->median = 1;
		else if (i > median)
			curra->median = 0;
		curra = curra->next;
		i++;
	}
}

void	median_b(t_node **tailb)
{
	int			i;
	int			median;
	t_node		*currb;

	i = 0;
	currb = (*tailb);
	if (currb == NULL)
		return ;
	median = count_node(*tailb) / 2;
	while (currb != NULL)
	{
		currb->index = i;
		if (i <= median)
			currb->median = 1;
		else if (i > median)
			currb->median = 0;
		currb = currb->next;
		i++;
	}
}

void	mouv2(t_node **taila, t_node **tailb, t_node **headb)
{
	rb(tailb, headb);
	pb(taila, tailb, headb);
	return ;
}
