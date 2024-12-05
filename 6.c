#include<stdio.h>
#include<stdlib.h>
int main()
{
FILE *file;
char data[100];
file=fopen("example.txt","w");
//file print
fprintf(file,"Hello this is a test file");
fclose(file);
printf("Data Written to file\n");
file=fopen("example.txt","r");
printf("Data Read from the file\n");
while(fgets(data,sizeof(data),file)!=NULL)
{
printf("%s",data);
}
fclose(file);
}
