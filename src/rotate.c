#include "push_swap.h"

void	ra(int *stacka, int ra)
{
	int	temp;

	if (ra)
		ft_printf("ra\n");
	if (stacka[0] < 2)
		return ;
	temp = stacka[1];
	shiftleft(stacka);
	stacka[stacka[0]] = temp;
}

void	rb(int *stackb, int rb)
{
	int	temp;

	if (rb)
		ft_printf("rb\n");
	if (stackb[0] < 2)
		return ;
	temp = stackb[1];
	shiftleft(stackb);
	stackb[stackb[0]] = temp;
}

void	rr(int *stacka, int *stackb, int rr)
{
	if (rr)
		ft_printf("rr\n");
	ra(stacka, 0);
	rb(stackb, 0);
}
