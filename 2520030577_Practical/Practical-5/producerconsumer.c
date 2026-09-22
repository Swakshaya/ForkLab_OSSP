#include<stdio.h>
#include<unistd.h>
#include<time.h>
int main()
{
int fd[2];
pipe(fd);
int pid,data;
int count;
double communication_Ef;
pid=fork();
double start,end;
double timetaken;
start=clock();
if(pid==0)
{
printf("Consumer");
close(fd[1]);//close write(parent) as it is child(read)
for(int i=0;i<5;i++)//creating 5 consumers
{
read(fd[0],&data,sizeof(data));//child reading data from pipe
printf("Consumed %d\n",data);//print consumed data
}
close(fd[0]);//closing the read end of pipe
}
else
{
printf("Producer");
close(fd[0]);
for(int i=1;i<=5;i++)//producing 5 items
{
data=i*10;
write(fd[1],&data,sizeof(data));//write data into pipe by parent for child
printf("produced %d\n",data);
}
close(fd[1]);
end=clock();
timetaken=(end-start)/CLOCKS_PER_SEC;
printf("communication time is %lf",timetaken);
communication_Ef = count / timetaken;
printf("Communication Efficiency = %lf\n",communication_Ef);
}
}
