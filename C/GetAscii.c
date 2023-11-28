#include <stdio.h>

int main()
{
  char Character;
  while (1)
  {
    printf("Insert A Character: ");
    scanf(" %1c", &Character);
    printf("\n");
    if (Character == 'Q')
    {
      printf("Quitting...");
      return 0;
    }
    else
    {
      int ASCII = Character;
      printf("Character is: %c | ASCII Value is: %d\n", Character, ASCII);
    }
  }
}
