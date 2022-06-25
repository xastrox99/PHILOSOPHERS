/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   locks_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaazzy <mbaazzy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 15:37:13 by mbaazzy           #+#    #+#             */
/*   Updated: 2022/06/18 20:33:05 by mbaazzy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosophers_bonus.h"

void	unlocking_forks_b(t_data_bonus *all)
{
	sem_post(all->forks);
	sem_post(all->forks);
}

void	locking_forks_b(t_philo_bonus *philo, t_data_bonus *all)
{
	sem_wait(all->forks);
	ft_print_b(philo, all, "has taken a fork 🍴");
	sem_wait(all->forks);
	ft_print_b(philo, all, "has taken a fork 🍴");
}
