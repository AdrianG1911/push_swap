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

int	isdigitcheck(const char *str, int args)
{
	size_t	i;

	i = whitepass(str);
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i] && !(isitspace(str[i])))
	{
		if (!(ft_isdigit(str[i])))
			return (0);
		i++;
	}
	if (isitspace(str[i]) && args)
		return (0);
	return (1);
}

int	repeatcheck(int *tings, int num)
{
	int	i;

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

int	isiterror(int *tings, char *num, int args)
{
	if (!(isdigitcheck(num, args)))
		return (1);
	if (ft_atol(num) > INT_MAX)
		return (2);
	if (ft_atol(num) < INT_MIN)
		return (2);
	if (repeatcheck(tings, ft_atoi(num)))
		return (3);
	return (0);
}