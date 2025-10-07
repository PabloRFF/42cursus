#include "philo.h"

void init_threads(t_table *table)
{
    int n = table->philos_nb;

    for (int i = 0; i < n; i++)
        pthread_create(&table->philos[i]->thread_id, NULL,
                       philo_pre_routine, table->philos[i]);

    table->start_sim = get_timestamp_ms();
    table->threads_rdy = true;

    pthread_create(&table->god, NULL, monitoring, table);
}
