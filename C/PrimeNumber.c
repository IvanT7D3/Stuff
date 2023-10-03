#include <stdio.h>

int main()
{
        int Number;
        printf("Insert a positive number that is not 0 or 1: ");
        BEGIN:
        scanf("%d", &Number);
        if (Number <= 0 || Number == 1)
        {
                printf("\nYou can't use negative numbers, 0, or 1.\nTry again: ");
                goto BEGIN;
        }
        for (int i = 2; i < Number; i++)
        {
                if (Number % i == 0)
                {
                        printf("The number you chose (%d) is not a prime number!\n", Number);
                        return 0;
                }
        }
        printf("The number you chose (%d) is a prime number!\n", Number);
        return 0;
}
