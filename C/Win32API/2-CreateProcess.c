#include <stdio.h>
#include <windows.h>

int main()
{
	BOOL CreateProc = 0;
	STARTUPINFOW si = {0};
	PROCESS_INFORMATION pi;

	CreateProc = CreateProcessW(L"C:\\Windows\\System32\\notepad.exe", NULL, NULL, NULL, FALSE, BELOW_NORMAL_PRIORITY_CLASS, NULL, NULL, &si, &pi);

	if (CreateProc == 0)
	{
		printf("[-] Process can't be created... Error: %ld\n", GetLastError());
		return EXIT_FAILURE;
	}

	printf("[+] Process created With PID: %ld\n", pi.dwProcessId);
	WaitForSingleObject(pi.hProcess, INFINITE);
	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);

	return EXIT_SUCCESS;
}
