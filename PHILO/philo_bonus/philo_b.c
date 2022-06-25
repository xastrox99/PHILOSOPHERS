/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaazzy <mbaazzy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 20:33:18 by mbaazzy           #+#    #+#             */
/*   Updated: 2022/06/18 20:38:30 by mbaazzy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	*effects(t_philo_bonus *philo)
{
	int	i;
	int	num_of_philo;

	philo->pro_start = get_time();
	num_of_philo = philo->data->number_of_philosophers;
	i = 0;
	if (philo->id % 2 == 0)
		ft_sleep_b(5, philo->pro_start);
	while (philo->finish == 1)
	{
		locking_forks_b(philo, philo->data);
		philo->last_meal = get_time();
		philo->num_of_eats--;
		eating_b(philo, philo->data);
		unlocking_forks_b(philo->data);
		sleeping_b(philo, philo->data);
		ft_print_b(philo, philo->data, "Thinking 🤔");
	}
	return (0);
}

void	kill_pro(t_data_bonus *all, int num, int pid)
{
	int	i;

	i = 0;
	while (i < num)
	{
		if (all->philo[i].pid != pid)
			kill(all->philo[i].pid, SIGTERM);
		i++;
	}
}

void	*check_dead(void *args)
{
	int				i;
	long long		timestamp;
	int				num_of_philo;
	t_philo_bonus	*philo;

	i = 0;
	philo = args;
	num_of_philo = philo->data->number_of_philosophers;
	while (1)
	{
		timestamp = get_time() - philo->last_meal;
		if (timestamp > philo->data->time_to_die)
		{
			ft_print_b(philo, philo->data, "Die 💀");
			makeitzero(philo, num_of_philo);
			sem_wait(philo->data->finished);
			exit(0);
		}
		if (philo->num_of_eats == 0)
			exit(0);
	}
	return (NULL);
}

void	process_go(t_data_bonus *all, char **av, int ac)
{
	int	i;
	int	*tab;

	i = -1;
	data_init_b(all, av, ft_atoi(av[1]));
	if (ac == 6)
	{
		while (++i < ft_atoi(av[1]))
			all->philo[i].num_of_eats = ft_atoi(av[5]);
	}
	i = -1;
	ft_sem_init(all);
	tab = malloc(sizeof(int) * ft_atoi(av[1]));
	while (++i < ft_atoi(av[1]))
	{
		all->philo[i].pid = fork();
		if (all->philo[i].pid == 0)
		{
			pthread_create(&all->philo[i].thread, NULL,
				check_dead, &all->philo[i]);
			effects(&all->philo[i]);
		}
		else
			tab[i] = all->philo[i].pid;
	}
}

int	main(int ac, char **av)
{
	t_data_bonus	*all;
	int				num_of_philo;
	int				i;
	int				s_pid;
	int				pid;

	parsing(ac, av);
	i = 0;
	all = malloc(sizeof(t_data_bonus));
	num_of_philo = ft_atoi(av[1]);
	all->philo = malloc(sizeof(t_philo_bonus) * num_of_philo);
	process_go(all, av, ac);
	pid = waitpid(-1, &s_pid, 0);
	kill_pro(all, num_of_philo, pid);
	return (0);
}
