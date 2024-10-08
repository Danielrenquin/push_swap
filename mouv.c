/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenquin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 22:49:46 by drenquin          #+#    #+#             */
/*   Updated: 2024/10/07 21:54:00 by drenquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	sa(t_node **tail_a, t_node **head_a)
{
	t_node	*curr;

	curr = *tail_a;
	if (*tail_a == NULL)
		return ;
	if (*tail_a == *head_a)
		return ;
	ft_printf("sa\n");
	if (curr->next->next != NULL)
	{
		curr = curr->next;
		curr->prev->next = curr->next;
		curr->next->prev = curr->prev;
		curr->prev = NULL;
		curr->next = *tail_a;
		(*tail_a)->prev = curr;
		*tail_a = curr;
	}
	if (curr->next->next == NULL)
		reverse(tail_a, head_a);
}

void	sb(t_node **tail_b, t_node **head_b)
{
	t_node	*curr;

	curr = *tail_b;
	if (*tail_b == NULL)
		return ;
	if (*tail_b == *head_b)
		return ;
	ft_printf("sb\n");
	if (curr->next->next != NULL)
	{
		curr = curr->next;
		curr->prev->next = curr->next;
		curr->next->prev = curr->prev;
		curr->prev = NULL;
		curr->next = *tail_b;
		(*tail_b)->prev = curr;
		*tail_b = curr;
	}
	if (curr->next->next == NULL)
		reverse(tail_b, head_b);
}

void	ss(t_node **taila, t_node **heada, t_node **tailb, t_node **headb)
{
	ft_printf("ss\n");
	sa(taila, heada);
	sb(tailb, headb);
}

void	pa(t_node **tail_a, t_node **tail_b, t_node **head_a)
{
	t_node	*first_b;

	if (*tail_b == NULL)
		return ;
	ft_printf("pa\n");
	first_b = *tail_b;
	*tail_b = first_b->next;
	if (*tail_b != NULL)
		(*tail_b)->prev = NULL;
	if (*tail_a == NULL)
	{
		first_b->next = NULL;
		first_b->prev = NULL;
		*tail_a = first_b;
	}
	else
	{
		first_b->next = *tail_a;
		first_b->prev = NULL;
		(*tail_a)->prev = first_b;
		*tail_a = first_b;
		update_headb(tail_a, head_a);
	}
}
