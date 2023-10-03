#include <stdio.h>
#include <stdlib.h>

int WinsP1 = 0;
int WinsP2 = 0;
int Draws = 0;

int main()
{
	system("clear");
	BEGIN:
	int ChoiceP1;
	int ChoiceP2;
	int RockP1 = 9;
	int PaperP1 = 8;
	int ScissorP1 = 7;
	int RockP2 = 6;
	int PaperP2 = 5;
	int ScissorP2 = 4;
	int NewGame = 3;
	CHOICEP1:
	printf("\n");
	printf("Player 1's choice\n1 : Rock\n2 : Paper\n3 : Scissor\n:");
	scanf("%d", &ChoiceP1);
	if (ChoiceP1 == 1)
	{
		RockP1 = 1;
	}
	else if (ChoiceP1 == 2)
	{
		PaperP1 = 1;
	}
	else if (ChoiceP1 == 3)
	{
		ScissorP1 = 1;
	}
	else
	{
		goto CHOICEP1;
	}
	system("clear");
	CHOICEP2:
	printf("Player 2's choice\n1 : Rock\n2 : Paper\n3 : Scissor\n:");
	scanf("%d", &ChoiceP2);
	if (ChoiceP2 == 1)
	{
		RockP2 = 1;
	}
	else if (ChoiceP2 == 2)
	{
		PaperP2 = 1;
	}
	else if (ChoiceP2 == 3)
	{
		ScissorP2 = 1;
	}
	else
	{
		goto CHOICEP2;
	}
	if(RockP1 == RockP2)
	{
		printf("Draw\n");
		Draws++;
	}
	else if(PaperP1 == PaperP2)
	{
		printf("Draw\n");
		Draws++;
	}
	else if(ScissorP1 == ScissorP2)
	{
		printf("Draw\n");
		Draws++;
	}
	else if(RockP1 == PaperP2)
	{
		printf("Player 2 Wins\n");
		WinsP2++;
	}
	else if(RockP1 == ScissorP2)
	{
		printf("Player 1 Wins\n");
		WinsP1++;
	}
	else if(PaperP1 == RockP2)
	{
		printf("Player 1 Wins\n");
		WinsP1++;
	}
	else if(PaperP1 == ScissorP2)
	{
		printf("Player 2 Wins\n");
		WinsP2++;
	}
	else if(ScissorP1 == RockP2)
	{
		printf("Player 2 Wins\n");
		WinsP2++;
	}
	else if(ScissorP1 == PaperP2)
	{
		printf("Player 1 Wins\n");
		WinsP1++;
	}
	CHOOSE:
	printf("Results:\nWins Player 1 : %d\nWins Player 2 : %d\nDraws : %d\n", WinsP1, WinsP2, Draws);
	printf("Do you want to play again?\n1 : Yes, 2 : No:");
	scanf("%d", &NewGame);
	if(NewGame == 1)
	{
		system("clear");
		goto BEGIN;
	}
	else if (NewGame == 2)
	{
		printf("Thanks for playing :)\n\n");
		printf("Results:\nWins Player 1 : %d\nWins Player 2 : %d\nDraws : %d\n", WinsP1, WinsP2, Draws);
		return 0;
	}
	else
	{
		printf("Results:\nWins Player 1 : %d\nWins Player 2 : %d\nDraws : %d\n", WinsP1, WinsP2, Draws);
		printf("Unknown choice.\n Do you want to play again?\n1 : Yes, 2 : No:");
		goto CHOOSE;
	}
	return 0;
}
