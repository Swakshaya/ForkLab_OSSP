#include<stdio.h>
#include<unistd.h>
#include<time.h>
int main()
{
int fd[2];//declaring the pipe
pipe(fd);//creating the pipe
int pid,data;//declaring variables for data and pid
int start,end;
double timetaken;
pid=fork();//creating process
if(pid==0)//checking for child
{
printf("Consumer\n ");
close(fd[1]);//close the write end of the pipe because child is reading
for(int i=0;i<5;i++)//creating 5 consumers
{
read(fd[0],&data,sizeof(data));//child is reading the date from the pipe
printf("Consumed %d\n",data);
}
close(fd[0]);
}
else
{
printf("Producer\n ");
close(fd[0]);
for(int i=1;i<=5;i++)
{
data=i*10;
write(fd[1],&data,sizeof(data));
printf("Produced %d\n",data);
}
close(fd[1]);
end=clock();
timetaken=(double)(end-start)/CLOCKS_PER_SEC;
printf("Time taken is %f",timetaken);
}
