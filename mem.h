#pragma once
#include <Windows.h>
#include <iostream>

class Mem {
private:
	DWORD id_process = NULL;
	HANDLE process_handle = nullptr;

public:
	Mem(const char* procces_name);
	~Mem();

	DWORD get_id_process();
	HANDLE get_process_handle();
	
	uintptr_t get_address(const char* mAddress);

	template<typename T>
	T Read(uintptr_t address) {
		T mValue;
		ReadProcessMemory(this->process_handle, (LPCVOID)address, &mValue, sizeof(T), NULL);
		return mValue;
	}

	template<typename T>
	bool Write(uintptr_t address, T value) {
		return WriteProcessMemory(this->process_handle, (LPVOID)address, &value, sizeof(T), NULL);
	}
};