/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortbinradix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrgutie <adrgutie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 17:15:35 by adrgutie          #+#    #+#             */
/*   Updated: 2024/08/31 17:21:57 by adrgutie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	pushback(int *stacka, int *stackb, int place, int maxplace)
{
	int	mask;
	int	len;

	if (place == maxplace)
	{
		while (stackb[0])
			pa(stacka, stackb, 1);
	}
	else
	{
		mask = 1 << (place);
		len = stackb[0];
		while (len > 0)
		{
			if (stackb[1] & mask)
				pa(stacka, stackb, 1);
			else
				rb(stackb, 1);
			len--;
		}
	}
}

static void	find0pushandback(int *stacka, int *stackb, int place, int maxplace)
{
	int	mask;
	int	len;

	mask = 1 << (place - 1);
	len = stacka[0];
	while (len > 0)
	{
		if (!(stacka[1] & mask))
			pb(stacka, stackb, 1);
		else
			ra(stacka, 1);
		len--;
	}
	pushback(stacka, stackb, place, maxplace);
}

void	binradixsort(int *stacka, int *stackb)
{
	int	maxplace;
	int	max;
	int	place;

	max = stacka[0];
	maxplace = 0;
	while (max)
	{
		max /= 2;
		maxplace += 1;
	}
	place = 1;
	while (place <= maxplace)
	{
		find0pushandback(stacka, stackb, place, maxplace);
		place++;
	}
}
