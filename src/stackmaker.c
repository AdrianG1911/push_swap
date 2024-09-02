/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackmaker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrgutie <adrgutie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 17:15:47 by adrgutie          #+#    #+#             */
/*   Updated: 2024/08/31 17:20:46 by adrgutie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*argmakestacka(int argc, char **argv)
{
	int	*stacka;
	int	i;

	stacka = (int *)ft_calloc(argc, sizeof(int));
	if (!stacka)
		return (NULL);
	stacka[0] = argc - 1;
	i = 1;
	while (i < argc)
	{
		stacka[i] = ft_atoi(argv[i]);
		i++;
	}
	stacka = simplifyarray(argc, &stacka);
	return (stacka);
}
int *onemakestacka(int len, char *arg)
{
	int *stacka;
	int	i;
	int	j;

	stacka = (int *)ft_calloc(len + 1, sizeof(int));
	if (!stacka)
		return (NULL);
	stacka[0] = len;
	i = 0;
	j = 1;
	while (j < len + 1)
	{
		while (isitspace(arg[i]))
			i++;
		if (!(isitspace(arg[i])) && arg[i])
			stacka[j] = ft_atoi(arg + i);
		while (!isitspace(arg[i]) && arg[i])
			i++;
		j++;
	}
	stacka = simplifyarray(len + 1, &stacka);
	return (stacka);
}

int *makestacka(int argc, char **argv)
{
	int		i;
	int		len;

	if (argc > 2)
		return (argmakestacka(argc, argv));
	len = 0;
	i = 0;
	while (argv[1][i])
	{
		if (!(isitspace(argv[1][i])))
		{
			len++;
			while (!(isitspace(argv[1][i])) && argv[1][i])
				i++;
		}
		else
			i++;
	}
	return (onemakestacka(len, argv[1]));
}
