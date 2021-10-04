#include "mem.h"
#include <TlHelp32.h>
#include <comdef.h> 


Mem::Mem(const char* procces_name)
{
	PROCESSENTRY32 entry;
	entry.dwSize = sizeof(PROCESSENTRY32);

	const auto snapShot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

	while (Process32Next(snapShot,&entry))
	{
		_bstr_t b(entry.szExeFile);
		if (!strcmp(procces_name, b)) 
		{
			this->id_process = entry.th32ProcessID;
			this->process_handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, this->id_process);
			break;
		}
	}

	if (snapShot)
		CloseHandle(snapShot);
}

Mem::~Mem()
{
	//if (this->process_handle)
		//CloseHandle(this->process_handle);
}

DWORD Mem::get_id_process()
{
	return this->id_process;
}

HANDLE Mem::get_process_handle()
{
	return this->process_handle;
}

uintptr_t Mem::get_address(const char* mAddress)
{
	MODULEENTRY32 entry;
	entry.dwSize = sizeof(MODULEENTRY32);

	const auto snapShot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE,this->id_process);

	uintptr_t result = 0;

	while (Module32Next(snapShot,&entry))
	{
		_bstr_t b(entry.szModule);
		if (!strcmp(mAddress, b))
		{
			result = reinterpret_cast<uintptr_t>(entry.modBaseAddr);
			break;
		}
	}

	if (snapShot)
		CloseHandle(snapShot);

	return result;
}