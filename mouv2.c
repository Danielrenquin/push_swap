/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouv2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenquin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 22:49:56 by drenquin          #+#    #+#             */
/*   Updated: 2024/10/08 18:28:04 by drenquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	rra(t_node **tail_a, t_node **head_a)
{
	t_node	*old_tail;
	t_node	*new_head;

	if (*tail_a == NULL || *head_a == NULL || *tail_a == *head_a)
		return ;
	ft_printf("rra\n");
	old_tail = *head_a;
	new_head = (*head_a)->prev;
	if (new_head != NULL)
		new_head->next = NULL;
	old_tail->prev = NULL;
	old_tail->next = *tail_a;
	(*tail_a)->prev = old_tail;
	*tail_a = old_tail;
	*head_a = new_head;
}

void	rrb(t_node **tail_b, t_node **head_b)
{
	t_node	*old_tail;
	t_node	*new_head;

	if (*tail_b == NULL || *head_b == NULL || *tail_b == *head_b)
		return ;
	ft_printf("rrb\n");
	old_tail = *head_b;
	new_head = (*head_b)->prev;
	if (new_head != NULL)
		new_head->next = NULL;
	old_tail->prev = NULL;
	old_tail->next = *tail_b;
	(*tail_b)->prev = old_tail;
	*tail_b = old_tail;
	*head_b = new_head;
}

void	rrr(t_node **taila, t_node **heada, t_node **tailb, t_node **headb)
{
	ft_printf("rrr\n");
	rra1(taila, heada);
	rrb1(tailb, headb);
}

void	rra1(t_node **tail_a, t_node **head_a)
{
	t_node	*old_tail;
	t_node	*new_head;

	if (*tail_a == NULL || *head_a == NULL || *tail_a == *head_a)
		return ;
	old_tail = *head_a;
	new_head = (*head_a)->prev;
	if (new_head != NULL)
		new_head->next = NULL;
	old_tail->prev = NULL;
	old_tail->next = *tail_a;
	(*tail_a)->prev = old_tail;
	*tail_a = old_tail;
	*head_a = new_head;
}

void	rrb1(t_node **tail_b, t_node **head_b)
{
	t_node	*old_tail;
	t_node	*new_head;

	if (*tail_b == NULL || *head_b == NULL || *tail_b == *head_b)
		return ;
	old_tail = *head_b;
	new_head = (*head_b)->prev;
	if (new_head != NULL)
		new_head->next = NULL;
	old_tail->prev = NULL;
	old_tail->next = *tail_b;
	(*tail_b)->prev = old_tail;
	*tail_b = old_tail;
	*head_b = new_head;
}
