#include "philo.h"

static int valid_args(int argc, char **argv)
{
	long v;
	if (argc != 5 && argc != 6)
		return (0);
	for (int i = 1; i < argc; i++)
	{
		/* simple numeric check */
		char *s = argv[i];
		if (*s == '\0') return 0;
		while (*s)
		{
			if (*s < '0' || *s > '9') return 0;
			s++;
		}
		v = ft_atol(argv[i]);
		if (v <= 0 || v > INT_MAX) return 0;
	}
	return 1;
}

t_table *init_table(int argc, char **argv)
{
	t_table *table;
	int n;

	if (!valid_args(argc, argv))
	{
		printf("Uso: %s nb_philos time_die time_eat time_sleep [must_eat]\n", argv[0]);
		return NULL;
	}

	table = (t_table *)ft_calloc(1, sizeof(t_table));
	if (!table) return NULL;

	n = (int)ft_atol(argv[1]);
	table->philos_nb = n;
	table->time_die = (int)ft_atol(argv[2]);
	table->time_eat = (int)ft_atol(argv[3]);
	table->time_sleep = (int)ft_atol(argv[4]);
	table->must_eat = (argc == 6) ? (int)ft_atol(argv[5]) : -1;
	table->end_sim = false;
	table->threads_rdy = false;
	table->start_sim = 0;

	pthread_mutex_init(&table->write_mtx, NULL);
	pthread_mutex_init(&table->table_mutex, NULL);

	table->philos = (t_philo **)ft_calloc(n, sizeof(t_philo *));
	if (!table->philos) { free(table); return NULL; }

	for (int i = 0; i < n; i++)
	{
		table->philos[i] = (t_philo *)ft_calloc(1, sizeof(t_philo));
		if (!table->philos[i]) return NULL;
		table->philos[i]->id = i + 1;
		table->philos[i]->meals = 0;
		table->philos[i]->must_eat = table->must_eat;
		table->philos[i]->table = table;
		pthread_mutex_init(&table->philos[i]->right_fork, NULL);
		pthread_mutex_init(&table->philos[i]->philo_mutex, NULL);
		table->philos[i]->last_meal = 0;
	}

	/* set left_fork pointers: left_fork points to neighbor's right_fork */
	for (int i = 0; i < n; i++)
	{
		if (i == 0)
			table->philos[i]->left_fork = &table->philos[n - 1]->right_fork;
		else
			table->philos[i]->left_fork = &table->philos[i - 1]->right_fork;
	}
	return table;
}
