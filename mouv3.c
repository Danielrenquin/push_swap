/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouv3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenquin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 18:14:41 by drenquin          #+#    #+#             */
/*   Updated: 2024/10/08 18:26:59 by drenquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ra1(t_node **tail_a, t_node **head_a)
{
	t_node	*old_tail;
	t_node	*old_head;

	if (*tail_a == NULL || *head_a == NULL || *tail_a == *head_a)
		return ;
	old_tail = *tail_a;
	old_head = *head_a;
	*tail_a = (*tail_a)->next;
	(*tail_a)->prev = NULL;
	old_tail->next = NULL;
	old_tail->prev = old_head;
	old_head->next = old_tail;
	*head_a = old_tail;
}

void	rb1(t_node **tail_b, t_node **head_b)
{
	t_node	*old_tail;
	t_node	*old_head;

	if (*tail_b == NULL || *head_b == NULL || *tail_b == *head_b)
		return ;
	old_tail = *tail_b;
	old_head = *head_b;
	*tail_b = (*tail_b)->next;
	(*tail_b)->prev = NULL;
	old_tail->next = NULL;
	old_tail->prev = old_head;
	old_head->next = old_tail;
	*head_b = old_tail;
}
