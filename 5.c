#include<stdio.h>
#include<stdlib.h>
#include<sys/shm.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>  // Changed from <wait.h>

int main()
{
//file to key
key_t key=ftok("sharedfile.txt",65); //72847618746186
//shared memory id = shared memory get for creation
int shmid=shmget(key,1024,0666|IPC_CREAT);
char *shared_memory =(char*)shmat(shmid,NULL,0);
pid_t pid=fork();//create a new process
if (pid<0)
{
printf("Error");
}
else if(pid==0)
{
//child
char *messages[]={"HELLO","WORLD"};
for (int i=0;i<2;i++)
{
//string copy
strcpy(shared_memory,messages[i]);
printf("child writes %s\n",messages[i]);
sleep(2);
}
//shared memory deattach
shmdt(shared_memory);
}
else
{
//parent will read from the memory
for (int i=0;i<2;i++)
{
sleep(1);
printf("parent read from memory %s\n",shared_memory);
}
wait(NULL);//parent waits for the child
shmdt(shared_memory);
}
return 0;  // Added return statement
}
