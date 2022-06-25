/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaazzy <mbaazzy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 15:19:43 by mbaazzy           #+#    #+#             */
/*   Updated: 2022/06/18 20:42:32 by mbaazzy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosophers_bonus.h"

int	ft_strncmp(const char *s1, const char *s2, int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s1[i] == s2[i] && i < n - 1)
	{
		if (s1[i] != s2[i])
			break ;
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	ft_sem_init(t_data_bonus *all)
{
	sem_unlink("forks");
	sem_unlink("print");
	sem_unlink("finished");
	all->forks = sem_open("forks", O_CREAT, 0644, all->number_of_philosophers);
	all->print = sem_open("print", O_CREAT, 0644, 1);
	all->finished = sem_open("finished", O_CREAT, 0644, 1);
	if (all->forks == SEM_FAILED || all->print == SEM_FAILED
		|| all->finished == SEM_FAILED)
		return (free(all), exit(0));
}

void	data_init_b(t_data_bonus *all, char **av, int num)
{
	long long	time;
	int			i;

	i = 0;
	time = get_time();
	(void)av;
	all->number_of_philosophers = ft_atoi(av[1]);
	all->time_to_die = ft_atoi(av[2]);
	all->time_to_eat = ft_atoi(av[3]);
	all->time_to_sleep = ft_atoi(av[4]);
	all->start_time = time;
	while (i < num)
	{
		all->philo[i].finish = 1;
		all->philo[i].num_of_eats = -1;
		all->philo[i].id = i + 1;
		all->philo[i].last_meal = time;
		i++;
	}
	i = -1;
	while (++i < num)
		all->philo[i].data = all;
}
