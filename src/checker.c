#include "push_swap.h"

int	checkinst(char *inst)
{
	if (ft_strncmp(inst, "sa\n", 3) == 0)
		return (1);
	if (ft_strncmp(inst, "sb\n", 3) == 0)
		return (1);
	if (ft_strncmp(inst, "ss\n", 3) == 0)
		return (1);
	if (ft_strncmp(inst, "pa\n", 3) == 0)
		return (1);
	if (ft_strncmp(inst, "pb\n", 3) == 0)
		return (1);
	if (ft_strncmp(inst, "ra\n", 3) == 0)
		return (1);
	if (ft_strncmp(inst, "rb\n", 3) == 0)
		return (1);
	if (ft_strncmp(inst, "rr\n", 3) == 0)
		return (1);
	if (ft_strncmp(inst, "rra\n", 4) == 0)
		return (1);
	if (ft_strncmp(inst, "rrb\n", 4) == 0)
		return (1);
	if (ft_strncmp(inst, "rrr\n", 4) == 0)
		return (1);
	return (0);
}

int buildstr(char **str)
{
	char	*line;
	char	*temp;

	*str = (char *)ft_calloc(1, sizeof(char));
	if (!(*str))
		return (0);
	line = get_next_line(0);
	while (line)
	{
		if (!checkinst(line))
			return (free(line), free(*str), 0);
		temp = (*str);
		(*str) = ft_strjoin((*str), line);
		free(line);
		free(temp);
		if (!(*str))
			return (0);
		line = get_next_line(0);
	}
	return (1);
}

void	makemove(int *stacka, int *stackb, char *inst)
{
	if (ft_strncmp(inst, "sa\n", 3) == 0)
		sa(stacka, 0);
	else if (ft_strncmp(inst, "sb\n", 3) == 0)
		sb(stackb, 0);
	else if (ft_strncmp(inst, "ss\n", 3) == 0)
		ss(stacka, stackb, 0);
	else if (ft_strncmp(inst, "pa\n", 3) == 0)
		pa(stacka, stackb, 0);
	else if (ft_strncmp(inst, "pb\n", 3) == 0)
		pb(stacka, stackb, 0);
	else if (ft_strncmp(inst, "ra\n", 3) == 0)
		ra(stacka, 0);
	else if (ft_strncmp(inst, "rb\n", 3) == 0)
		rb(stackb, 0);
	else if (ft_strncmp(inst, "rr\n", 3) == 0)
		rr(stacka, stackb, 0);
	else if (ft_strncmp(inst, "rra\n", 4) == 0)
		rra(stacka, 0);
	else if (ft_strncmp(inst, "rrb\n", 4) == 0)
		rrb(stackb, 0);
	else if (ft_strncmp(inst, "rrr\n", 4) == 0)
		rrr(stacka, stackb, 0);
	return ;
}

void	parseinst(int *stacka, int *stackb, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		makemove(stacka, stackb, str + i);
		while (str[i] != '\n')
			i++;
		i++;
	}
	i = 1;
	while (i <= stacka[0])
	{
		if (stacka[i] != i)
			break ;
		i++;
	}
	if (i == stacka[0] + 1)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

int	main(int argc, char *argv[])
{
	char *str;
	int *stacka;
	int *stackb;

	if (argc < 2)
		return (0);
	if (errorcheck(argc, argv))
		return (ft_putstr_fd("Error\n", 2), 0);
	stacka = makestacka(argc, argv);
	if (!stacka)
		return (ft_putstr_fd("Error\n", 2), 0);
	stackb = (int *)ft_calloc(argc + 1, sizeof(int));
	if (!stackb)
		return (free(stacka), ft_putstr_fd("Error\n", 2), 0);
	if (!buildstr(&str))
		return (free(stacka), free(stackb), ft_putstr_fd("Error\n", 2), 0);
	parseinst(stacka, stackb, str);
	free (str);
	return (free(stacka), free(stackb), 0);
}
