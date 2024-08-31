/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrgutie <adrgutie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 17:15:13 by adrgutie          #+#    #+#             */
/*   Updated: 2024/08/31 18:03:12 by adrgutie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(int *stacka, int *stackb)
{
	int	i;

	i = 1;
	while (i <= stacka[0])
	{
		if (stacka[i] != i)
			break ;
		i++;
	}
	if (i == stacka[0] + 1)
		return ;
	if (stacka[0] <= 5)
		sort1to5(stacka, stackb);
	else if (stacka[0] < 900)
		sortrotate(stacka, stackb);
	else
		binradixsort(stacka, stackb);
}

int	main(int argc, char *argv[])
{
	int	*stacka;
	int	*stackb;

	if (argc < 2)
		return (0);
	if (errorcheck(argc, argv))
		return (ft_putstr_fd("Error\n", 2), 0);
	stacka = makestacka(argc, argv);
	if (!stacka)
		return (ft_printf("Error\nfailed to allocate memmory\n"), 0);
	stackb = (int *)ft_calloc(argc + 1, sizeof(int));
	if (!stackb)
	{
		free(stacka);
		ft_printf("Error\nfailed to allocate memmory\n");
		return (0);
	}
	sort(stacka, stackb);
	free(stacka);
	free(stackb);
	return (0);
}
