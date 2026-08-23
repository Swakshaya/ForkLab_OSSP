#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main()
{
    int pid;
    char buffer[20];

    printf("Enter Linux command: ");
    scanf("%s", buffer);

    pid = fork();

    if (pid == 0)
    {
        printf("Child PID: %d\n", getpid());

        execlp(buffer, buffer, NULL);
    }
    else
    {
        printf("Parent PID: %d\n", getpid());

        wait(NULL);

        printf("Child process completed\n");
    }

    return 0;
}