/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_utils1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenquin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 22:49:16 by drenquin          #+#    #+#             */
/*   Updated: 2024/10/07 22:34:40 by drenquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

t_node	*find_node(t_node *tail, int x)
{
	t_node	*curr;

	curr = tail;
	while (curr != NULL)
	{
		if (curr->val == x)
			return (curr);
		curr = curr->next;
	}
	return (NULL);
}

void	reverse(t_node **tail, t_node **head)
{
	t_node	*curr;
	t_node	*next;
	t_node	*aux;

	curr = *tail;
	while (curr != NULL)
	{
		next = curr->next;
		curr->next = curr->prev;
		curr->prev = next;
		curr = next;
	}
	aux = *tail;
	*tail = *head;
	*head = aux;
}
