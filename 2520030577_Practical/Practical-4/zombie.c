#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
int main()
{
int pid;
pid=fork();
if(pid==0)
{
printf("Child process %d",getpid());//priniting child process id
exit(0);//exiting the standard input
}
else//parent process
{
printf("parent process %d\n",getpid());//print child id
sleep(30);//making the parent process wait without collecting the status of child
//wait(NULL);
printf("parent process completed");

}
}
