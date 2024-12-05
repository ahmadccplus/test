#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
pid_t child= fork();
if (child <0)
printf("error");
else if (child ==0)
{  
printf( "Hello from the child %d \n" , getpid());
printf("my parent %d \n",getppid());
}
else if (child>0)
{
printf ("Hello from the parent %d \n" , getpid ());}}
