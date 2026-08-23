#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main()
{
    int fd1, fd2;
    char buffer[100];
    int n;

    fd1 = open("file1.txt", O_RDONLY);
    fd2 = open("file2.txt", O_WRONLY | O_CREAT, 0642);

    n = read(fd1, buffer, 100);

    write(fd2, buffer, n);

    close(fd1);
    close(fd2);

    printf("File copied successfully\n");

    return 0;
}