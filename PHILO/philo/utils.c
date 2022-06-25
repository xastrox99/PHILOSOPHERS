/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaazzy <mbaazzy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 13:46:23 by mbaazzy           #+#    #+#             */
/*   Updated: 2022/06/18 20:56:02 by mbaazzy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosophers.h"

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

int	check_all(t_philo *philo, char **av)
{
	int	i;
	int	x;
	int	j;

	i = 0;
	j = 0;
	x = ft_atoi(av[1]);
	while (i < ft_atoi(av[1]))
	{
		if (philo[i].finish == 0)
			j++;
		i++;
	}
	if (x == j)
		return (0);
	return (1);
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
