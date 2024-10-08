/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenquin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 11:51:29 by drenquin          #+#    #+#             */
/*   Updated: 2024/10/04 16:21:44 by drenquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	no_double1(int argc, int *tab)
{
	int	i;
	int	j;

	i = 0;
	while (i < (argc - 1))
	{
		j = (i + 1);
		while (j < (argc - 1))
		{
			if (tab[i] == tab[j])
			{
				free (tab);
				return (0);
			}
			j++;
		}
		i++;
	}
	free (tab);
	return (1);
}

char	*ft_strncpy(char *s1, const char *s2, int n)
{
	int	i;

	i = 0;
	while ((s2[i] != '\0') && i < n)
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

int	count_one_more(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 1;
	while (str[i])
	{
		while (str[i] && (str[i] == ' '))
			i++;
		if (str[i])
			count++;
		while (str[i] && (str[i] != ' '))
			i++;
	}
	return (count);
}

int	init_split(char *str, t_split *s)
{
	s->i = 0;
	s->k = 1;
	s->count = count_one_more(str);
	s->tab = (char **)malloc(sizeof(char *) * (s->count + 1));
	if (!s->tab)
		return (0);
	s->tab[0] = (char *)malloc(sizeof(char) * (ft_strlen("push_swap") + 1));
	if (!s->tab[0])
	{
		free(s->tab);
		return (0);
	}
	ft_strncpy(s->tab[0], "push_swap", ft_strlen("push_swap"));
	return (1);
}

char	**split_one_arg(char *str, t_split *s)
{
	if (!init_split(str, s))
		return (NULL);
	while (str[s->i])
	{
		while (str[s->i] && (str[s->i] == ' '))
			s->i++;
		s->j = s->i;
		while (str[s->i] && (str[s->i] != ' '))
			s->i++;
		if (s->i > s->j)
		{
			s->tab[s->k] = (char *)malloc(sizeof(char) * (s->i - s->j + 1));
			if (!s->tab[s->k])
			{
				while (--s->k >= 0)
					free(s->tab[s->k]);
				free(s->tab);
				return (NULL);
			}
			ft_strncpy(s->tab[s->k++], &str[s->j], s->i - s->j);
		}
	}
	s->tab[s->k] = NULL;
	return (s->tab);
}
