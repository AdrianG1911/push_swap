#include "push_swap.h"

void	simploop(int argc, int *stacka, int **newstacka)
{
	int i;
	int j;
	int jloc;
	int min;

	i = 1;
	while (i < argc)
	{
		j = 1;
		jloc = j;
		min = INT_MAX;
		while (j < argc)
		{
			if (min > stacka[j])
			{
				min = stacka[j];
				jloc = j;
			}	
			j++;
		}
		stacka[jloc] = INT_MAX;
		(*newstacka)[jloc] = i;
		i++;
	}
}

int	*simplifyarray(int argc, int **stacka)
{
	int *newstacka;

	newstacka = (int *)ft_calloc(argc, sizeof(int));
	if (!newstacka)
		return (free(*stacka), NULL);
	newstacka[0] = argc - 1;
	simploop(argc, *stacka, &newstacka);
	free(*stacka);
	return (newstacka);
}

int	*makestacka(int argc, char **argv)
{
	int	*stacka;
	int	i;

	stacka = (int *)calloc(argc, sizeof(int));
	if (!stacka)
		return (NULL);
	stacka[0] = argc - 1;
	i = 1;
	while (i < argc)
	{
		stacka[i] = ft_atoi(argv[i]);
		i++;
	}
	stacka = simplifyarray(argc, &stacka);
	if (!stacka)
		return (NULL);
	return (stacka);
}
