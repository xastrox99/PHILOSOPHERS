/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaazzy <mbaazzy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:09:04 by mbaazzy           #+#    #+#             */
/*   Updated: 2022/06/18 20:27:51 by mbaazzy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosophers.h"

void	*thread_effects(void *args)
{
	t_philo	*philo;
	int		i;
	int		num_of_philo;

	philo = args;
	philo->pro_start = get_time();
	num_of_philo = philo->data->number_of_philosophers;
	i = 0;
	if (philo->id % 2 == 0)
		ft_sleep(5, philo->pro_start);
	while (philo->finish == 1)
	{
		locking_forks(philo);
		philo->last_meal = get_time();
		eating(philo);
		philo->num_of_eats--;
		unlocking_forks(philo);
		sleeping(philo);
		ft_print(philo, "Thinking 🤔");
	}
	return (0);
}

void	check_dead(t_philo *philo, char **av)
{
	int			i;
	long long	timestamp;
	int			num_of_philo;

	i = 0;
	num_of_philo = philo[0].data->number_of_philosophers;
	while (i < num_of_philo && check_all(philo, av))
	{
		timestamp = get_time() - philo[i].last_meal;
		if (timestamp > philo[i].data->time_to_die)
		{
			philo[i].finish = 0;
			makeitzero(philo, num_of_philo);
			ft_print(&philo[i], "Die 💀");
			break ;
		}
		if (philo[i].num_of_eats == 0)
			philo[i].finish = 0;
		i++;
		if (i == num_of_philo)
			i = 0;
	}
}

void	thread_go(t_data *all, char **av)
{
	int	i;
	int	num_of_philo;

	i = 0;
	num_of_philo = ft_atoi(av[1]);
	while (i < num_of_philo)
	{
		pthread_create(&all->philo[i].thread, NULL,
			&thread_effects, (void*)&all->philo[i]);
		pthread_detach(all->philo[i].thread);
		i++;
	}
	check_dead(all->philo, av);
}

void	philo_go(t_data *all, char **av, int ac)
{
	int	i;

	i = 0;
	data_init(all, av, ft_atoi(av[1]));
	if (ac == 6)
	{
		while (i < ft_atoi(av[1]))
		{
			all->philo[i].num_of_eats = ft_atoi(av[5]);
			i++;
		}
	}
	thread_go(all, av);
}

int	main(int ac, char **av)
{
	t_data	*all;

	all = malloc(sizeof(t_data));
	parsing(ac, av);
	philo_go(all, av, ac);
	return (0);
}
