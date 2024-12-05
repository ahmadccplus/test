#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
sem_t semaphore; // Declare a semaphore
void* thread_function(void* arg) {
// Wait (decrease the semaphore count)
sem_wait(&semaphore);
printf("Thread %ld is in the critical section\n", (long)arg);
// Simulate some work in the critical section
sleep(2);
printf("Thread %ld is leaving the critical section\n", (long)arg);
// Signal (increase the semaphore count)
sem_post(&semaphore);
return NULL;
}

int main() {
pthread_t t1, t2, t3;
// Initialize the semaphore with a count of 1 (only one thread allowed in)
sem_init(&semaphore, 0, 1);
// Create three threads
pthread_create(&t1, NULL, thread_function, (void*)1);
pthread_create(&t2, NULL, thread_function, (void*)2);
pthread_create(&t3, NULL, thread_function, (void*)3);
// Wait for the threads to complete
pthread_join(t1, NULL);
pthread_join(t2, NULL);
pthread_join(t3, NULL);
// Destroy the semaphore
sem_destroy(&semaphore);
return 0;
}
