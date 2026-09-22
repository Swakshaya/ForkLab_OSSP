#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
int main()
{
int pid[3];
for(int i=0;i<3;i++)
{
pid[i]=fork();
if(pid[i]==0)
{
printf("Child %d pid=%d\n",i+1,getpid());
sleep(i+1);
exit(0);
}
}
wait(NULL);//taking the status of one child
printf("Parent: any one child completes with wait()\n");//one parent prinitng its status
waitpid(pid[2],NULL,0);//taking status of 3rd chils
printf("Parent: Child 3 compelets with waitpid()\n");//one parent printing 3rd child status
wait(NULL);
printf("parent:All the child completed\n");
}