#include"stdafx.h"
#include<Windows.h>
#include<winternl.h>
#include<iostream>

void myProcessDemo() {
	STARTUPINFO startupInfo = { 0 };
	PROCESS_INFORMATION processInfomation = { 0 };
	BOOL bSucess = CreateProcess(
		TEXT("C:\\Windows\\system32\\notepad.exe"), NULL, NULL,
		NULL, FALSE, NULL, NULL, NULL, &startupInfo,
		&processInfomation
	);
	if (bSucess) {
		std::cout << "process started..." << std::endl;
		std::cout << "process ID:    " << processInfomation.dwProcessId << std::endl;
		
	}
	else {
		std::cout << "cannot start process...." << std::endl;
		std::cout << "erro code:    " << GetLastError() << std::endl;
	}
}

typedef NTSTATUS(NTAPI *QEURYINFORMATIONPROCESS)(
	IN HANDLE ProcessHandle,
	IN PROCESSINFOCLASS ProcessInfomationClass,
	OUT PVOID ProcessInfomationLength,
	IN ULONG ProcessInformationLength,
	OUT PULONG ReturnLength OPTIONAL
);

void myProcessDemo1() {
	STARTUPINFO startupInfo = { 0 };
	PROCESS_INFORMATION processInfomation = { 0 };
	BOOL bSucess = CreateProcess(
		TEXT("C:\\Windows\\system32\\notepad.exe"), NULL, NULL,
		NULL, FALSE, NULL, NULL, NULL, &startupInfo,
		&processInfomation
	);
	if (bSucess) {
		std::cout << "process started..." << std::endl;
		std::cout << "process ID:    " << processInfomation.dwProcessId << std::endl;
		PROCESS_BASIC_INFORMATION pbi;
		ULONG uLength = 0;
		HMODULE hDll = LoadLibrary(TEXT("C:\\Windows\\System32\\ntdll.dll"));
		if (hDll) {
			QEURYINFORMATIONPROCESS QueryInformationProcess = 
				(QEURYINFORMATIONPROCESS)GetProcAddress(hDll, "NtQueryInformationProcess");
			if (QueryInformationProcess) {
				NTSTATUS ntStatus = QueryInformationProcess(
					processInfomation.hProcess,
					PROCESSINFOCLASS::ProcessBasicInformation,
					&pbi, sizeof(pbi), &uLength
				);
				if (NT_SUCCESS(ntStatus)) {
					std::cout << "process id (from PCB):  " << pbi.UniqueProcessId << std::endl;
				}
				else {
					std::cout << "cannot open pcd:.." << std::endl;
					std::cout << "eroo code:   " << GetLastError() << std::endl;
				}
			}
			else {
				std::cout << "cannott get nequryinformationprocess function" << std::endl;
				std::cout << "eroo code:  " << GetLastError() << std::endl;
			}
			FreeLibrary(hDll);
		}
		else {
			std::cout << "cannot load ntdll.dll..." << std::endl;
			std::cout << "eroo cod:    " << GetLastError() << std::endl;
		}
	}
	else {
		std::cout << "cannot start process...." << std::endl;
		std::cout << "erro code:    " << GetLastError() << std::endl;
	}
}