/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablrome <pablrome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 14:04:15 by pablrome          #+#    #+#             */
/*   Updated: 2025/09/30 14:04:32 by pablrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_table	*table;

	table = init_table(argc, argv);
	if (!table)
		return (1);
	init_threads(table);

	/* join monitor (god) */
	pthread_join(table->god, NULL);

	/* join philosophers threads */
	for (int i = 0; i < table->philos_nb; i++)
		pthread_join(table->philos[i]->thread_id, NULL);

	cleanup(table);
	return (0);
}
