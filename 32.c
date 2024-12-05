#include <stdio.h>
#include <pthread.h>
void *print_message(void*ptr);
int main(void)
{
pthread_t thread1, thread2;
char * message1="Thread1";
char * message2="Thread2";
int ret1, ret2;
ret1=pthread_create(&thread1, NULL, print_message, (void*)message1 );
ret2=pthread_create(&thread2, NULL, print_message, (void*) message2 );
pthread_join(thread1, NULL);
pthread_join(thread2, NULL);
printf("Thread1 returns %d\n",ret1);
printf("Thread2 returns %d\n",ret2);
}
void *print_message(void*ptr)
{
char* message;
message=(char*)ptr;
printf("%s\n", message);
}
