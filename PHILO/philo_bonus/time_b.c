/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaazzy <mbaazzy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 15:48:16 by mbaazzy           #+#    #+#             */
/*   Updated: 2022/06/18 20:43:17 by mbaazzy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosophers_bonus.h"

long long	get_time(void)
{
	static struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	ft_sleep_b(long time, long start_time)
{
	usleep(time * 1000 * 0.98);
	while (get_time() - start_time < time)
	{
	}
}
