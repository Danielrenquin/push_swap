/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenquin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 21:09:45 by drenquin          #+#    #+#             */
/*   Updated: 2024/10/04 16:49:16 by drenquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	free_split_result(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		free (tab[i]);
		i++;
	}
	free (tab);
}

void	make_list(int argc, char **argv, t_node **heada, t_node **taila)
{
	int		val;
	int		i;
	t_split	s;

	if (argc == 2)
	{
		make_list2(argv, heada, taila);
		return ;
	}
	i = 2;
	val = ft_atoi(argv[1]);
	init(taila, heada, val);
	while (i < argc)
	{
		val = ft_atoi(argv[i]);
		add_end(&(*heada), val);
		i++;
	}
}

void	make_list2(char **argv, t_node **heada, t_node **taila)
{
	int				val;
	int				i;
	int				argc;
	t_split			s;

	argc = count_one_more (argv[1]);
	argv = split_one_arg (argv[1], &s);
	i = 2;
	val = ft_atoi (argv[1]);
	init (taila, heada, val);
	while (i < argc)
	{
		val = ft_atoi(argv[i]);
		add_end (&(*heada), val);
		i++;
	}
	free_split_result (argv);
}

int	count_node(t_node *tail)
{
	t_node	*curr;
	int		i;

	curr = tail;
	i = 0;
	while (curr != NULL)
	{
		curr = curr->next;
		i++;
	}
	return (i);
}

int	is_sorted(t_node *tail)
{
	t_node	*curr;

	curr = tail;
	if (tail == NULL)
		return (1);
	while (curr->next != NULL)
	{
		if (curr->val > curr->next->val)
			return (0);
		curr = curr->next;
	}
	return (1);
}
