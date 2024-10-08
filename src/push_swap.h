/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrgutie <adrgutie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 17:15:16 by adrgutie          #+#    #+#             */
/*   Updated: 2024/09/13 21:01:51 by adrgutie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

// stack making
int		*makestacka(int argc, char **argv);
void	simploop(int argc, int *stacka, int **newstacka);
int		*simplifyarray(int argc, int **stacka);
int		isitspace(int c);

// operation helper
void	shiftleft(int *stack);
void	shiftright(int *stack);

// operations
void	sa(int *stack, int sa);
void	sb(int *stack, int sb);
void	ss(int *stacka, int *stackb, int ss);
void	pa(int *stacka, int *stackb, int pa);
void	pb(int *stacka, int *stackb, int pb);
void	ra(int *stack, int ra);
void	rb(int *stack, int rb);
void	rr(int *stacka, int *stackb, int rr);
void	rra(int *stack, int rra);
void	rrb(int *stack, int rrb);
void	rrr(int *stacka, int *stackb, int rrr);

// short sort and binradix sort
void	binradixsort(int *stacka, int *stackb);
void	sort1to5(int *stacka, int *stackb);

// helpers for sortrotate
void	forward(int *stacka, int *stackb, int posa, int posb);
void	backward(int *stacka, int *stackb, int posa, int posb);
void	forbac(int *stacka, int *stackb, int posa, int posb);
void	bacfor(int *stacka, int *stackb, int posa, int posb);
int		pushcheck(int *stacka, int *stackb, int posa, int posb);
void	checklenmove(int *stacka, int *stackb, int *pos);

// sort rotate and combined sort function
void	sortrotate(int *stacka, int *stackb);
void	sort(int *stacka, int *stackb);

// error
int		errorcheck(int argc, char **argv);
int		isdigitcheck(const char *str, int args);
int		repeatcheck(int *tings, int num);
int		isiterror(int *tings, char *num, int args);

// get_next_line
char	*get_next_line(int fd);
char	*free_ft_strjoin(char **s1, char **s2);
char	*free_ft_substr(char **s, unsigned int start, size_t len);
void	freeptr(char **p1, char **p2, char **p3);

#endif