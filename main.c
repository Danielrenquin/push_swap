/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenquin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 22:49:40 by drenquin          #+#    #+#             */
/*   Updated: 2024/10/07 21:29:48 by drenquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*heada;
	t_node	*headb;
	t_node	*taila;
	t_node	*tailb;

	heada = NULL;
	headb = NULL;
	taila = NULL;
	tailb = NULL;
	if (check_in(argc, argv))
	{
		make_list(argc, argv, &heada, &taila);
		sorted(&taila, &heada, &tailb, &headb);
		deallocate(&taila, &heada);
	}
	else
		exit(1);
}
