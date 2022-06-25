/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaazzy <mbaazzy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 11:15:39 by mbaazzy           #+#    #+#             */
/*   Updated: 2022/06/18 20:29:55 by mbaazzy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosophers.h"

void	ft_print(t_philo *philo, char *str)
{
	pthread_mutex_lock(philo->data->print);
	printf("%lld      The PHILO %d %s\n", get_time() - philo->data->start_time,
		philo->id, str);
	pthread_mutex_unlock(philo->data->print);
}

void	sleeping(t_philo *philo)
{	
	ft_print(philo, "Sleeping 😴");
	ft_sleep(philo->data->time_to_sleep, philo->data->start_time);
}

void	eating(t_philo *philo)
{
	ft_print(philo, "Eating 😋");
	ft_sleep(philo->data->time_to_eat, philo->data->start_time);
}
