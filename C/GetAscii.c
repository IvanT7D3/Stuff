#include <stdio.h>

int main()
{
  char character;
  while (1)
  {
    printf("Insert A Character: ");
    scanf("%2c", &character);
    printf("\n");
    if (character == 'Q')
    {
      printf("Quitting...");
      return 0;
    }
    else
    {
      int ASCII = character;
      printf("Character is: %c | ASCII Value is: %d\n", character, ASCII);
    }
  }
}
