#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main()
{
	MessageBoxW(NULL, L"MSGBox Text", L"MSGBox Title", MB_OKCANCEL | MB_ICONINFORMATION);
	return EXIT_SUCCESS;
}
