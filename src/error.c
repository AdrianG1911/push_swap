/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortanderror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrgutie <adrgutie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 17:15:32 by adrgutie          #+#    #+#             */
/*   Updated: 2024/08/31 17:19:15 by adrgutie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	argerrorcheck(int argc, char **argv)
{
	int	i;
	int	*tings;

	tings = (int *)ft_calloc(argc, sizeof(int));
	if (!tings)
		return (6);
	i = 1;
	while (i < argc)
	{
		if (isiterror(tings, argv[i], 1))
			return (free(tings), 1);
		i++;
	}
	free(tings);
	return (0);
}


int	oneerrorcheck(int len, char *arg)
{
	int *tings;
	int	i;

	if (len == 0)
		return (1);
	tings = (int *)ft_calloc(len + 1, sizeof(int));
	if (!tings)
		return (1);
	i = 0;
	while (len > 0)
	{
		while (isitspace(arg[i]))
			i++;
		if (!(isitspace(arg[i])) && arg[i])
		{
			if (isiterror(tings, arg + i, 0))
				return (free(tings), 1);
		}
		while (!isitspace(arg[i]) && arg[i])
			i++;
		len--;
	}
	free(tings);
	return (0);
}

int	errorcheck(int argc, char **argv)
{
	int		i;
	int		len;

	if (argc > 2)
		return (argerrorcheck(argc, argv));
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
	return (oneerrorcheck(len, argv[1]));
}
