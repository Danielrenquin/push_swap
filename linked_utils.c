/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenquin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 22:48:47 by drenquin          #+#    #+#             */
/*   Updated: 2024/10/07 21:21:01 by drenquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	deallocate(t_node **tail, t_node **head)
{
	t_node	*curr;

	if (*tail == NULL)
		return ;
	curr = *tail;
	while (curr->next != NULL)
	{
		curr = curr->next;
		free(curr->prev);
	}
	free(curr);
	*tail = NULL;
	*head = NULL;
}

void	init(t_node **tail, t_node **head, int x)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (new == NULL)
	{
		exit(1);
		return ;
	}
	new->val = x;
	new->prev = NULL;
	new->next = NULL;
	*tail = new;
	*head = new;
}

void	add_end(t_node **head, int x)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (new == NULL)
	{
		exit(1);
		return ;
	}
	new->val = x;
	new->next = NULL;
	new->prev = *head;
	(*head)->next = new;
	*head = new;
}
