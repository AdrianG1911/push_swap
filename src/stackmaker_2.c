/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackmaker_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrgutie <adrgutie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 21:00:21 by adrgutie          #+#    #+#             */
/*   Updated: 2024/09/13 21:03:11 by adrgutie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	isitspace(int c)
{
	if (((c > 8 && c < 14) || c == 32))
		return (1);
	return (0);
}

void	simploop(int argc, int *stacka, int **newstacka)
{
	int	i;
	int	j;
	int	jloc;
	int	min;

	i = 1;
	while (i < argc)
	{
		j = 1;
		jloc = j;
		min = INT_MAX;
		while (j < argc)
		{
			if (min > stacka[j])
			{
				min = stacka[j];
				jloc = j;
			}	
			j++;
		}
		stacka[jloc] = INT_MAX;
		(*newstacka)[jloc] = i;
		i++;
	}
}

int	*simplifyarray(int argc, int **stacka)
{
	int	*newstacka;

	newstacka = (int *)ft_calloc(argc, sizeof(int));
	if (!newstacka)
		return (free(*stacka), NULL);
	newstacka[0] = argc - 1;
	simploop(argc, *stacka, &newstacka);
	free(*stacka);
	return (newstacka);
}
