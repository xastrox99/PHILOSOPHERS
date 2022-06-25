/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   locks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaazzy <mbaazzy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 17:30:40 by mbaazzy           #+#    #+#             */
/*   Updated: 2022/06/18 20:29:35 by mbaazzy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosophers.h"

void	locking_forks(t_philo *philo)
{
	if (philo->id == philo->data->number_of_philosophers)
	{
		pthread_mutex_lock(&philo->data->forks[philo->i]);
		ft_print(philo, "has taken a fork 🍴");
		pthread_mutex_lock(&philo->data->forks[0]);
		ft_print(philo, "has taken a fork 🍴");
	}
	else
	{
		pthread_mutex_lock(&philo->data->forks[philo->i]);
		ft_print(philo, "has taken a fork 🍴");
		pthread_mutex_lock(&philo->data->forks[philo->i + 1]);
		ft_print(philo, "has taken a fork 🍴");
	}
}

void	unlocking_forks(t_philo *philo)
{
	if (philo->id == philo->data->number_of_philosophers)
	{
		pthread_mutex_unlock(&philo->data->forks[philo->i]);
		pthread_mutex_unlock(&philo->data->forks[0]);
	}
	else
	{
		pthread_mutex_unlock(&philo->data->forks[philo->i]);
		pthread_mutex_unlock(&philo->data->forks[philo->i + 1]);
	}
}
