#include "push_swap.h"

static size_t	whitepass(const char *str)
{
	size_t	i;
	char	c;

	i = 0;
	c = str[i];
	while ((c > 8 && c < 14) || c == 32)
	{
		i++;
		c = str[i];
	}
	return (i);
}

static int	isdigitcheck(const char *str)
{
	size_t	i;

	i = whitepass(str);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!(ft_isdigit(str[i])))
			return (0);
		i++;
	}
	return (1);
}
int	repeatcheck(int *tings, int num)
{
	int i;

	i = 1;
	while (i <= tings[0])
	{
		if (tings[i] == num)
			return (1);
		i++;
	}
	tings[i] = num;
	tings[0]++;
	return (0);
}

int	errorcheck(int argc, char **argv)
{
	int	i;
	int *tings;

	tings = (int *)ft_calloc(argc, sizeof(int));
	if (!tings)
		return (6);
	i = 1;
	while (i < argc)
	{
		if (!(isdigitcheck(argv[i])))
			return (free(tings), 1);
		if (ft_atol(argv[i]) > INT_MAX)
			return (free(tings), 2);
		if (ft_atol(argv[i]) < INT_MIN)
			return (free(tings), 2);
		if (repeatcheck(tings, ft_atoi(argv[i])))
			return (free(tings), 3);
		i++;
	}
	free(tings);
	return (0);
}
