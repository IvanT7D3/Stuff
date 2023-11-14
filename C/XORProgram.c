#include <stdio.h>

int main()
{
	int NoToXOR[8];
	int XORKey[8];
	int Text[8];
	int PlainText[8];
	int countNoToXOR = 1;
	int countXORKey = 1;
	int countDecryptText = 1;
	int l = 0;
	int m = 0;
	int Choice;

	system("clear");
	printf("Choose 0 to encrypt. Choose 1 to decrypt: ");
	scanf("%1d", &Choice);
	if (Choice != 0 && Choice != 1)
	{
		printf("Invalid option\n");
		return 1;
	}
	
	if (Choice == 0)
	{
		printf("Welcome To The Encrypt Section\n");
		printf("Same bits should give 0. Different bits should give 1\n");

		for (int i = 0; i < 8; i++) //GetBitsToXOR
		{
			printf("Choose bit %d to store: ", countNoToXOR);
			scanf("%1d", &NoToXOR[i]);
			printf("\n");
			countNoToXOR++;
		}

		for (int j = 0; j < 8; j++) //GetXORKey
		{
			printf("Choose bit %d of the XOR key: ", countXORKey);
			scanf("%1d", &XORKey[j]);
			printf("\n");
			countXORKey++;
		}
		system("clear");
		printf("The bits to XOR are:\n"); //PrintingNumbersToXOR
		for (int x = 0; x < 8; x++)
		{
			printf("%d ", NoToXOR[x]);
		}
		printf("\n\n");
		printf("The bits of the XOR key are:\n"); //PrintingXORKeyBits
		for (int z = 0; z < 8; z++)
		{
			printf("%d ", XORKey[z]);
		}

		printf("\n\nXORed bits are:"); //PrintingXORedBits
		printf("\n");
		for (int k = 0; k < 8; k++)
		{
			Text[k] = NoToXOR[l] ^ XORKey[m];
			printf("%d", Text[k]);
			l++;
			m++;
		}
		printf("\n");
		l = 0;
		m = 0;
	}

	else if (Choice == 1)
	{
		printf("Welcome To The Decrypt Section.\n");
		printf("Same bits should give 0. Different bits should give 1\n");

		for (int i = 0; i < 8; i++) //GetBitsToDecrypt
		{
			printf("Choose bit %d to decrypt: ", i);
			scanf("%1d", &Text[i]);
			printf("\n");
			countDecryptText;
		}

		for (int j = 0; j < 8; j++) //GetXORKeyBits
		{
			printf("Choose bit %d of the XOR key: ", countXORKey);
			scanf("%1d", &XORKey[j]);
			printf("\n");
			countXORKey++;
		}

		system("clear");
		printf("The bits to decrypt are:\n"); //PrintingNumbersToDecrypt
		for (int x = 0; x < 8; x++)
		{
			printf("%d ", Text[x]);
		}
		printf("\n\n");
		printf("The bits of the XOR key are:\n"); //PrintingXORKeyBits
		for (int z = 0; z < 8; z++)
		{
			printf("%d ", XORKey[z]);
		}

		printf("\n\nDecrypted bits are:"); //PrintingDecryptedBits
		printf("\n");
		for (int k = 0; k < 8; k++)
		{
			PlainText[k] = Text[l] ^ XORKey[m];
			printf("%d", PlainText[k]);
			l++;
			m++;
		}
	printf("\n");
	l = 0;
	m = 0;
	}
	return 0;
}
