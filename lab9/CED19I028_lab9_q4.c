
// producer-consumer problem using semaphore..

#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <stdio.h>

#define Total_items 10 // Maximum items a producer can produce or a consumer can consume
#define buffer_size 5 // Size of the buffer


int put_in = 0;
int put_out = 0;
int buffer[buffer_size];
sem_t empty;
sem_t full;

void *producer(void *arg) {   
    int item;
    for(int i = 0; i < Total_items; i++) {
        item = rand();          // Produce an random item
        sem_wait(&empty);       // checking empty

        buffer[put_in] = item;
        printf("Producer - Insert Item %d in Buffer Position %d\n", buffer[put_in], put_in);
        put_in = (put_in+1) % buffer_size;

        sem_post(&full);
    }
    printf("\n");
}

void *consumer(void *cno) {

    int item;
    for(int i = 0; i < Total_items; i++) {
        sem_wait(&full);            // checking if buffer is full

        item = buffer[put_out];
        printf("Consumer - Removed Item %d from Buffer Position %d\n", item, put_out);
        put_out = (put_out+1) % buffer_size;

        sem_post(&empty);
    }
    printf("\n");
}

int main() {

    pthread_t PRODUCER, CONSUMER;
    sem_init(&empty,0,buffer_size);
    sem_init(&full,0,0);

    pthread_create(&PRODUCER, NULL, producer, (void*)1);
    pthread_create(&CONSUMER, NULL, consumer, (void*)1);

    pthread_join(PRODUCER, NULL);
    pthread_join(CONSUMER, NULL);

    sem_destroy(&empty);
    sem_destroy(&full);

    return 0;
}
