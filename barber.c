#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define NUM_CUSTOMERS 10
#define NUM_CHAIRS 3

sem_t barber_sem;
sem_t customer_sem;
sem_t mutex;

int waiting_customers = 0;

void* barber_thread(void* arg) {
    while (1) {
        sem_wait(&customer_sem); // Wait for a customer to arrive
        sem_wait(&mutex);

        waiting_customers--; // One customer will now be served
        printf("Barber is cutting hair. Customers waiting: %d\n", waiting_customers);

        sem_post(&mutex);

        sleep(2); // Simulate haircut time
        sem_post(&barber_sem); // Signal that haircut is done
    }
    return NULL;
}

void* customer_thread(void* arg) {
    while (1) {
        sem_wait(&mutex);

        if (waiting_customers < NUM_CHAIRS) {
            waiting_customers++;
            printf("Customer is waiting. Customers waiting: %d\n", waiting_customers);

            sem_post(&customer_sem); // Notify the barber
            sem_post(&mutex);

            sem_wait(&barber_sem); // Wait for haircut
        } else {
            printf("Customer leaves because the waiting room is full.\n");
            sem_post(&mutex);
        }

        sleep(rand() % 5 + 1); // Simulate time before returning
    }
    return NULL;
}

int main() {
    pthread_t barber;
    pthread_t customers[NUM_CUSTOMERS];

    sem_init(&barber_sem, 0, 0);
    sem_init(&customer_sem, 0, 0);
    sem_init(&mutex, 0, 1);

    pthread_create(&barber, NULL, barber_thread, NULL);

    for (int i = 0; i < NUM_CUSTOMERS; i++) {
        pthread_create(&customers[i], NULL, customer_thread, NULL);
    }

    pthread_join(barber, NULL);
    for (int i = 0; i < NUM_CUSTOMERS; i++) {
        pthread_join(customers[i], NULL);
    }

    sem_destroy(&barber_sem);
    sem_destroy(&customer_sem);
    sem_destroy(&mutex);

    return 0;
}
