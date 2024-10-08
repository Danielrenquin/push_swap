/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenquin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 23:06:18 by drenquin          #+#    #+#             */
/*   Updated: 2024/10/04 16:05:46 by drenquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	check_in(int argc, char **argv)
{
	int			in;
	t_split		s;

	if (argc == 1)
		exit(1);
	else if (argc == 2)
	{
		argc = count_one_more(argv[1]);
		argv = split_one_arg(argv[1], &s);
		in = overflow(argc, argv);
		free_split_result(argv);
		if (in == 0)
			ft_printf("Error\n");
		return (in);
	}
	else if (argc > 2)
	{
		in = overflow(argc, argv);
		if (in == 0)
			ft_printf("Error\n");
		return (in);
	}
	return (0);
}

long int	ft_atoi_lg(char *str)
{
	long int	result;
	int			sign;

	sign = 1;
	result = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - '0';
		str++;
	}
	return (sign * result);
}

int	overflow(int argc, char **argv)
{
	int			i;
	int			j;
	long int	value;

	i = 1;
	j = 0;
	while (i < argc)
	{
		if (only_num(argv[i]) == 0)
		{
			return (0);
		}
		value = ft_atoi_lg(argv[i]);
		if (value < -2147483648 || value > 2147483647)
		{
			return (0);
		}
		i++;
	}
	if (!no_double(argc, argv))
		return (0);
	return (1);
}

int	only_num(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] < 48 || str[i] > 57)
			return (0);
		i++;
	}
	return (1);
}

int	no_double(int argc, char **argv)
{
	int	*tab;
	int	i;
	int	j;
	int	compare;

	i = 0;
	j = 1;
	tab = malloc(sizeof(int) * (argc - 1));
	if (tab == NULL)
		return (0);
	while (j < argc)
		tab[i++] = atoi(argv[j++]);
	compare = no_double1(argc, tab);
	if (compare == 0)
		return (0);
	return (1);
}
