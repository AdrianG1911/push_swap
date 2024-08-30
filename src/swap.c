#include "push_swap.h"

static void	swap(int *stack)
{
	int temp;

	temp = stack[1];
	stack[1] = stack[2];
	stack[2] = temp;
}

void	sa(int *stacka, int sa)
{
	if (sa)
		ft_printf("sa\n");
	if (stacka[0] < 2)
		;
	else	
		swap(stacka);
	
}

void	sb(int *stackb, int sb)
{
	if (sb)
		ft_printf("sb\n");
	if (stackb[0] < 2)
		;
	else	
		swap(stackb);
}

void	ss(int *stacka, int *stackb, int ss)
{
	if (ss)
		ft_printf("ss\n");
	sa(stacka, 0);
	sb(stackb, 0);
}
