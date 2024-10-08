/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouv1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenquin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 22:49:51 by drenquin          #+#    #+#             */
/*   Updated: 2024/10/07 22:06:55 by drenquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	pb(t_node **tail_a, t_node **tail_b, t_node **head_b)
{
	t_node	*first_a;

	first_a = *tail_a;
	if (*tail_a == NULL)
		return ;
	ft_printf("pb\n");
	*tail_a = first_a->next;
	if (*tail_a != NULL)
		(*tail_a)->prev = NULL;
	if (*tail_b == NULL)
	{
		first_a->next = NULL;
		first_a->prev = NULL;
		*tail_b = first_a;
	}
	else
	{
		first_a->next = *tail_b;
		first_a->prev = NULL;
		(*tail_b)->prev = first_a;
		*tail_b = first_a;
		update_headb(tail_b, head_b);
	}
}

void	ra(t_node **tail_a, t_node **head_a)
{
	t_node	*old_tail;
	t_node	*old_head;

	if (*tail_a == NULL || *head_a == NULL || *tail_a == *head_a)
		return ;
	ft_printf("ra\n");
	old_tail = *tail_a;
	old_head = *head_a;
	*tail_a = (*tail_a)->next;
	(*tail_a)->prev = NULL;
	old_tail->next = NULL;
	old_tail->prev = old_head;
	old_head->next = old_tail;
	*head_a = old_tail;
}

void	rb(t_node **tail_b, t_node **head_b)
{
	t_node	*old_tail;
	t_node	*old_head;

	if (*tail_b == NULL || *head_b == NULL || *tail_b == *head_b)
		return ;
	ft_printf("rb\n");
	old_tail = *tail_b;
	old_head = *head_b;
	*tail_b = (*tail_b)->next;
	(*tail_b)->prev = NULL;
	old_tail->next = NULL;
	old_tail->prev = old_head;
	old_head->next = old_tail;
	*head_b = old_tail;
}

void	rr(t_node **taila, t_node **heada, t_node **tailb, t_node **headb)
{
	ft_printf("rr\n");
	ra1(taila, heada);
	rb1(tailb, headb);
}
