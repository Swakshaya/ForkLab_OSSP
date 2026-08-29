#include <stdio.h>

int main()
{
    char input[50];
    char ch;
    int i = 0;

    printf("Enter command: ");

    while (1)
    {
        ch = getchar();

        if (ch == '\n')
        {
            input[i] = '\0';

            printf("You entered: %s\n", input);

            if (input[0] == 'e' && input[1] == 'x' &&
                input[2] == 'i' && input[3] == 't')
            {
                break;
            }

            i = 0;
            printf("Enter command: ");
        }
        else
        {
            input[i] = ch;
            i++;
        }
    }

    printf("Program ended\n");

    return 0;
}
