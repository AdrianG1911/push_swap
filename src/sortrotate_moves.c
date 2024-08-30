#include "push_swap.h"

void	forward(int *stacka, int *stackb, int posa, int posb)
{
	while (posa != 1 || posb != 1)
	{
		if (posa != 1)
		{
			if (posb != 1)
			{
				rr(stacka, stackb, 1);
				posa--;
				posb--;
			}
			else
			{
				ra(stacka, 1);
				posa--;
			}
		}
		else if (posb != 1)
		{
			rb(stackb, 1);
			posb--;
		}
	}
	pa(stacka, stackb, 1);
}

void	backward(int *stacka, int *stackb, int posa, int posb)
{
	posa = stacka[0] + 2 - posa;
	posb = stackb[0] + 2 - posb;
	while (posa != 1 || posb != 1)
	{
		if (posa != 1)
		{
			if (posb != 1)
			{
				rrr(stacka, stackb, 1);
				posa--;
				posb--;
			}
			else
			{
				rra(stacka, 1);
				posa--;
			}
		}
		else if (posb != 1)
		{
			rrb(stackb, 1);
			posb--;
		}
	}
	pa(stacka, stackb, 1);
}

void	forbac(int *stacka, int *stackb, int posa, int posb)
{
	posb = stackb[0] + 2 - posb;
	while (posa != 1 || posb != 1)
	{
		if (posa != 1)
		{
			ra(stacka, 1);
			posa--;
		}
		else if (posb != 1)
		{
			rrb(stackb, 1);
			posb--;
		}
	}
	pa(stacka, stackb, 1);
}

void	bacfor(int *stacka, int *stackb, int posa, int posb)
{
	posa = stacka[0] + 2 - posa;
	while (posa != 1 || posb != 1)
	{
		if (posa != 1)
		{
			rra(stacka, 1);
			posa--;
		}
		else if (posb != 1)
		{
			rb(stackb, 1);
			posb--;
		}
	}
	pa(stacka, stackb, 1);
}