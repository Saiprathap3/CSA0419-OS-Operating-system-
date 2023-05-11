#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define N 5

sem_t chopsticks[N];

void *philosopher(void *arg) {
    int id = *(int *) arg;
    int left = id;
    int right = (id + 1) % N;
while (1) {
            printf("Philosopher %d is thinking\n", id);
            sleep(1);

            printf("Philosopher %d is hungry\n", id);
            sem_wait(&chopsticks[left]);
            sem_wait(&chopsticks[right]);

            printf("Philosopher %d is eating\n", id);
            sleep(1);

            sem_post(&chopsticks[left]);
            sem_post(&chopsticks[right]);
            
    }
}

int main() {
    pthread_t philosophers[N];
    int ids[N];

    for (int i = 0; i < N; i++) {
        sem_init(&chopsticks[i], 0, 1);
        ids[i] = i;
    }

    for (int i = 0; i < N; i++) {
        pthread_create(&philosophers[i], NULL, philosopher, &ids[i]);
    }

    for (int i = 0; i < N; i++) {
        pthread_join(philosophers[i], NULL);
    }

    return 0;
}