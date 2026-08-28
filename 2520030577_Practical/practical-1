#include<unistd.h>
#include<stdio.h>
int main()
{
char command[50];
int pid;
scanf("%s", command);
pid=fork();
if(pid<0)
{
printf("Fork failed\n");
return 1;
}

if(pid==0)
{
printf("child pid: %d\n", getpid());
printf("parent pid: %d\n",getppid());
execlp(command,command,NULL);
}
else
{
printf("current pid: %d\n", getpid());
printf("parent pid: %d\n", getppid());
}
}
