/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrgutie <adrgutie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 17:15:19 by adrgutie          #+#    #+#             */
/*   Updated: 2024/08/31 17:18:38 by adrgutie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	shiftleft(int *stack)
{
	int	i;
	int	len;

	len = stack[0];
	i = 1;
	while (i < len)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[len] = 0;
}

void	shiftright(int *stack)
{
	int	len;

	len = stack[0];
	while (len > 0)
	{
		stack[len + 1] = stack[len];
		len--;
	}
	stack[1] = 0;
}

static void	push(int *stack1, int *stack2)
{
	if (stack2[0] == 0)
		return ;
	shiftright(stack1);
	stack1[1] = stack2[1];
	stack1[0]++;
	shiftleft(stack2);
	stack2[0]--;
}

void	pa(int *stacka, int *stackb, int pa)
{
	if (pa)
		ft_printf("pa\n");
	push(stacka, stackb);
}

void	pb(int *stacka, int *stackb, int pb)
{
	if (pb)
		ft_printf("pb\n");
	push(stackb, stacka);
}
