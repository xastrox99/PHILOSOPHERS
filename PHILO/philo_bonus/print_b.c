/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaazzy <mbaazzy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 15:47:06 by mbaazzy           #+#    #+#             */
/*   Updated: 2022/06/18 20:43:10 by mbaazzy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosophers_bonus.h"

void	ft_print_b(t_philo_bonus *philo, t_data_bonus *all, char *str)
{
	sem_wait(all->print);
	printf("%lld      The PHILO %d is %s\n",
		get_time() - philo->data->start_time, philo->id, str);
	if (ft_strncmp("Die 💀", str, ft_strlen("Die 💀")) == 0)
		return ;
	sem_post(all->print);
}

void	sleeping_b(t_philo_bonus *philo, t_data_bonus *all)
{	
	ft_print_b(philo, all, "Sleeping 😴");
	ft_sleep_b(all->philo->data->time_to_sleep, all->philo->data->start_time);
}

void	eating_b(t_philo_bonus *philo, t_data_bonus *all)
{
	ft_print_b(philo, all, "Eating 😋");
	ft_sleep_b(all->philo->data->time_to_eat, all->philo->data->start_time);
}
