/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortrotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrgutie <adrgutie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 17:15:44 by adrgutie          #+#    #+#             */
/*   Updated: 2024/08/31 17:38:40 by adrgutie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	prepstacks(int *stacka, int *stackb)
{
	int	max;

	max = stacka[0];
	while (stacka[0] > 2)
	{
		if (stacka[1] == max)
			ra(stacka, 1);
		else if (stacka[1] == 1)
			ra(stacka, 1);
		else
			pb(stacka, stackb, 1);
	}
	if (stacka[1] == 1)
		ra(stacka, 1);
}

static int	maxi(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	updateminpos(int min, int *pos, int i, int j)
{
	int	test;

	test = 100;
	if (i >= 0 && j >= 0)
		test = maxi(i, j);
	else if (i >= 0 && j < 0)
		test = i - j;
	else if (i < 0 && j >= 0)
		test = j - i;
	else if (i < 0 && j < 0)
		test = maxi(-i, -j);
	if (test < min)
	{
		min = test;
		pos[0] = i;
		pos[1] = j;
	}
	return (min);
}

void	search(int *stacka, int *stackb, int *pos)
{
	int	i;
	int	j;
	int	min;

	min = INT_MAX;
	i = -(stacka[0] / 2);
	while (i < (stacka[0] / 2) + 1)
	{
		j = -(stackb[0] / 2);
		while (j < (stackb[0] / 2) + 1)
		{
			if (pushcheck(stacka, stackb, i, j))
				min = updateminpos(min, pos, i, j);
			j++;
		}
		i++;
	}
}

void	sortrotate(int *stacka, int *stackb)
{
	int	pos[2];
	int	len;

	len = stacka[0];
	prepstacks(stacka, stackb);
	while (stacka[0] < len)
	{
		search(stacka, stackb, pos);
		checklenmove(stacka, stackb, pos);
	}
	len = 1;
	while (stacka[len] != 1)
		len++;
	if (len <= (stacka[0] / 2))
	{
		while (stacka[1] != 1)
			ra(stacka, 1);
	}
	else
	{
		while (stacka[1] != 1)
			rra(stacka, 1);
	}
}
