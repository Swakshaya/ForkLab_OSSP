#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
int pid;//variable to collect the status of fork
pid=fork();//creating a process
if(pid==0)//chechking whether it is child or not
{
printf("child process %d\n",getpid());//printling the child process along with its pid
exit(0);//exiting the
}
else
{
printf("Parent process %d\n",getpid());
sleep(30);
//wait(NULL);
printf("Parent process completed");
}
}
