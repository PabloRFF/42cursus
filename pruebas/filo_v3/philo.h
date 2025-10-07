/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablrome <pablrome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 14:03:52 by pablrome          #+#    #+#             */
/*   Updated: 2025/09/30 14:07:08 by pablrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <stdlib.h>
# include <stdbool.h>
# include <pthread.h>
# include <sys/time.h>
# include <string.h>

# define EATING "is eating"
# define SLEEPING "is sleeping"
# define THINKING "is thinking"
# define DIED "died"
# define FORK_1 "has taken a fork"
# define FORK_2 "has taken a fork"

typedef struct s_philo	t_philo;

typedef struct s_table
{
	int					philos_nb;
	int					time_die;
	int					time_eat;
	int					time_sleep;
	int					must_eat;
	bool				end_sim;
	bool				threads_rdy;
	long long			start_sim;   /* ms */
	pthread_mutex_t		write_mtx;
	pthread_t			god;
	t_philo				**philos;
	pthread_mutex_t		table_mutex; /* optional general mutex */
}				t_table;

typedef struct s_philo
{
	int							id;
	int							meals;
	int							must_eat;
	pthread_t					thread_id;
	pthread_mutex_t				right_fork;
	pthread_mutex_t				*left_fork;
	long long					last_meal; /* ms */
	t_table						*table;
	pthread_mutex_t				philo_mutex;
}						t_philo;

/* init */
t_table		*init_table(int argc, char **argv);
void		init_threads(t_table *table);

/* time / sleep */
long long	get_timestamp_ms(void);
long long	get_now_time(t_table *table);
void		philo_sleep(t_table *table, int time_ms);

/* routines */
void		*philo_pre_routine(void *data);
void		philo_routine(t_philo *philo);

/* monitor */
void		*monitoring(void *data);

/* utils */
void		write_status(const char *status, t_philo *philo);
int			all_philos_ate(t_table *table);
int			is_simulation_end(t_table *table);

/* cleanup */
void		destroy_mutexes(t_table *table);
void		cleanup(t_table *table);

/* small helpers */
void		*ft_calloc(size_t nmemb, size_t size);
long		ft_atol(const char *str);
int			ft_strncmp(const char *s1, const char *s2, unsigned int n);

#endif
