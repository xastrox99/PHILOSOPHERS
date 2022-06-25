/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaazzy <mbaazzy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 11:14:22 by mbaazzy           #+#    #+#             */
/*   Updated: 2022/06/18 20:43:21 by mbaazzy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosophers.h"

long long	get_time(void)
{
	static struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	ft_sleep(long time, long start_time)
{
	usleep(time * 1000 * 0.98);
	while (get_time() - start_time < time)
	{
		usleep(50);
	}
}
