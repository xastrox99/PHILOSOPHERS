/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaazzy <mbaazzy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 16:47:38 by mbaazzy           #+#    #+#             */
/*   Updated: 2022/06/18 20:27:16 by mbaazzy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosophers.h"

void	forks_init(t_data *all, int num)
{
	int	i;

	i = 0;
	while (i < num)
	{
		pthread_mutex_init(&all->forks[i], NULL);
		i++;
	}
}

void	init_philo(t_data *all, int num)
{
	int	i;

	i = 0;
	while (i < num)
	{
		all->philo[i].finish = 1;
		all->philo[i].data = all;
		all->philo[i].id = i + 1;
		all->philo[i].i = i;
		all->philo[i].last_meal = all->start_time;
		all->philo[i].num_of_eats = -1;
		i++;
	}
}

void	data_init(t_data *all, char **av, int num)
{
	long long		time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	int				i;

	i = 0;
	time = get_time();
	(void)av;
	all->philo = malloc(sizeof(t_philo) * ft_atoi(av[1]));
	all->number_of_philosophers = ft_atoi(av[1]);
	all->time_to_die = ft_atoi(av[2]);
	all->time_to_eat = ft_atoi(av[3]);
	all->time_to_sleep = ft_atoi(av[4]);
	all->start_time = time;
	forks = malloc(sizeof(pthread_mutex_t) * ft_atoi(av[1]));
	all->forks = forks;
	pthread_mutex_init(&print, NULL);
	all->print = &print;
	init_philo(all, all->number_of_philosophers);
	forks_init(all, num);
}

void	makeitzero(t_philo *philo, int num)
{
	int	i;

	i = 0;
	while (i < num)
	{
		philo[i].finish = 0;
		i++;
	}
}
