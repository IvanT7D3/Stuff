#include <stdio.h>
#include <windows.h>

int main()
{
	HANDLE CreateProc = NULL;
	STARTUPINFOW si;
	PROCESS_INFORMATION pi;

	CreateProc = CreateProcessW(L"C:\\Windows\\System32\\notepad.exe", NULL, NULL, NULL, FALSE, BELOW_NORMAL_PRIORITY_CLASS, NULL, NULL, &si, &pi);
	
	if (CreateProc != NULL)
	{
		printf("[+] Process created With PID: %ld\n", pi.dwProcessId);
		return EXIT_SUCCESS;
	}

	printf("[-] Process can't be created... Error: %ld\n", GetLastError());
	return EXIT_FAILURE;
}
