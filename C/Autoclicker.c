#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main()
{
	printf("Press Z to enable, X to quit, C to pause\n");
	_Bool Click = 0;
	int ClickNum = 0;
	while (1)
	{
		if (GetAsyncKeyState('Z'))
		{
			Click = 1;
		}
		else if (GetAsyncKeyState('X'))
		{
			Click = 0;
			break;
		}
		else if(GetAsyncKeyState('C'))
		{
			Click = 0;
		}
		if (Click == 1)
		{
			mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
			mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
			ClickNum++;
			Sleep(100);
		}
	}
	printf("Total Clicks : %d\n", ClickNum);
	Sleep(5);
	return 0;
}
