/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaazzy <mbaazzy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 19:46:02 by mbaazzy           #+#    #+#             */
/*   Updated: 2022/06/18 20:56:27 by mbaazzy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosophers_bonus.h"

void	makeitzero(t_philo_bonus *philo, int num)
{
	int	i;

	i = 0;
	while (i < num)
	{
		philo[i].finish = 0;
		i++;
	}
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (*s++ != '\0')
		i++;
	return (i);
}

void	check_arg(char **av)
{
	if ((ft_atoi(av[1]) < 0 || ft_atoi(av[1]) > 200)
		|| (ft_atoi(av[2]) < 60 || ft_atoi(av[3]) < 60 || ft_atoi(av[4]) < 60))
	{
		printf("ARGUMENTS ARE NOT VALID :(\n");
		exit(0);
	}
}

void	parsing(int ac, char **av)
{
	int	i;
	int	j;

	if (ac != 5 && ac != 6)
	{
		printf("ARGUMENTS ARE NOT VALID :(\n");
		exit(0);
	}
	i = 1;
	while (i < ac)
	{
		j = 0;
		while (j < ft_strlen(av[i]))
		{
			if (!ft_isdigit(av[i][j]))
			{
				printf("ARGUMENTS ARE NOT VALID :(\n");
				exit(0);
			}
			j++;
		}
		i++;
	}
	check_arg(av);
}
