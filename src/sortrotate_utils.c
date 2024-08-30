#include "push_swap.h"

static int	poscalibrate(int *stack, int pos)
{
	pos = (pos % stack[0]) + 1;
	if (pos <= 0)
		pos = stack[0] + pos;
	return (pos);
}

int	pushcheck(int *stacka, int *stackb, int posa, int posb)
{
	posa = poscalibrate(stacka, posa);
	posb = poscalibrate(stackb, posb);
	if (stacka[posa] > stackb[posb])
	{
		posa -= 1;
		if (posa == 0)
			posa = stacka[0];
		if (stacka[posa] < stackb[posb])
			return (1);
	}
	return (0);
}

static int	findmove(int *moves)
{
	int	move;
	int min;
	int i;

	min = INT_MAX;
	i = 0;
	while (i < 4)
	{
		if (min > moves[i])
		{
			min = moves[i];
			move = i;
		}
		i++;
	}
	return (move);
}

static void	move(int *stacka, int *stackb, int *pos, int move)
{
	int posa;
	int posb;

	posa = poscalibrate(stacka, pos[0]);
	posb = poscalibrate(stackb, pos[1]);
	if (move == 0)
		forward(stacka, stackb, posa, posb);
	if (move == 1)
		backward(stacka, stackb, posa, posb);
	if (move == 2)
		forbac(stacka, stackb, posa, posb);
	if (move == 3)
		bacfor(stacka, stackb, posa, posb);
}

void	checklenmove(int *stacka, int *stackb, int *pos)
{
	int backa;
	int backb;
	int posa;
	int posb;
	int	moves[4];

	posa = poscalibrate(stacka, pos[0]);
	posb = poscalibrate(stackb, pos[1]);
	backa = stacka[0] + 1 - posa;
	backb = stackb[0] + 1 - posb;
	if (posa > posb)
		moves[0] = posa - 1;
	else
		moves[0] = posb - 1;
	if (backa > backb)
		moves[1] = backa;
	else
		moves[1] = backb;
	moves[2] = posa - 1 + backb;
	moves[3] = posb - 1 + backa;
	move(stacka, stackb, pos, findmove(moves));
}




