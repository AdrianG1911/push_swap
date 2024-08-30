#include "push_swap.h"

void	rra(int *stacka, int rra)
{
	int	temp;

	if (rra)
		ft_printf("rra\n");
	if (stacka[0] < 2)
		return ;
	temp = stacka[stacka[0]];
	stacka[0]--;
	shiftright(stacka);
	stacka[0]++;
	stacka[1] = temp;
}

void	rrb(int *stackb, int rrb)
{
	int	temp;

	if (rrb)
		ft_printf("rrb\n");
	if (stackb[0] < 2)
		return ;
	temp = stackb[stackb[0]];
	stackb[0]--;
	shiftright(stackb);
	stackb[0]++;
	stackb[1] = temp;
}

void	rrr(int *stacka, int *stackb, int rrr)
{
	if (rrr)
		ft_printf("rrr\n");
	rra(stacka, 0);
	rrb(stackb, 0);
}