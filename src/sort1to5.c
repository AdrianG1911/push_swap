/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort1to5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrgutie <adrgutie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 17:15:29 by adrgutie          #+#    #+#             */
/*   Updated: 2024/08/31 17:18:52 by adrgutie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort3(int *stacka)
{
	int	a;
	int	b;
	int	c;

	a = stacka[1];
	b = stacka[2];
	c = stacka[3];
	if (a < c && b > c)
		return (rra(stacka, 1), sa(stacka, 1), (void)0);
	if (a < c && b < a)
		return (sa(stacka, 1), (void)0);
	if (a > c && b > a)
		return (rra(stacka, 1), (void)0);
	if (a > c && b < c)
		return (ra(stacka, 1), (void)0);
	if (a > b && b > c)
		return (ra(stacka, 1), sa(stacka, 1), (void)0);
}

static void	sort4(int *stacka, int *stackb)
{
	while (stacka[0] > 3)
	{
		if (stacka[1] == 1)
			pb(stacka, stackb, 1);
		else
			ra(stacka, 1);
	}
	sort3(stacka);
	pa(stacka, stackb, 1);
}

static void	sort5(int *stacka, int *stackb)
{
	while (stacka[0] > 3)
	{
		if (stacka[1] == 1 || stacka[1] == 2)
			pb(stacka, stackb, 1);
		else
			ra(stacka, 1);
	}
	sort3(stacka);
	if (stackb[1] != 2)
		sb(stackb, 1);
	pa(stacka, stackb, 1);
	pa(stacka, stackb, 1);
}

void	sort1to5(int *stacka, int *stackb)
{
	int	len;

	len = stacka[0];
	if (len == 2)
	{
		if (stacka[1] == 2)
			sa(stacka, 1);
		return ;
	}
	if (len == 3)
		return (sort3(stacka), (void)0);
	if (len == 4)
		return (sort4(stacka, stackb), (void)0);
	if (len == 5)
		return (sort5(stacka, stackb), (void)0);
}
