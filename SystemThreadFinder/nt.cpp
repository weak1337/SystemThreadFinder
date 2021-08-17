#include "includes.h"
int* nt::get_proc_list() {
	int* proc_list = NULL;
	ULONG proc_list_size = 0;
	NtQuerySystemInformation(SystemProcessInformation, proc_list, proc_list_size, &proc_list_size);
	proc_list = (int*)realloc(proc_list, proc_list_size);
	NtQuerySystemInformation(SystemProcessInformation, proc_list, proc_list_size, &proc_list_size);
	return proc_list;
}
int* nt::get_driver_list() {
	int* driver_list = NULL;
	ULONG driver_list_size = 0;
	NtQuerySystemInformation((SYSTEM_INFORMATION_CLASS)0xB, 0, driver_list_size, &driver_list_size);
	driver_list = (int*)realloc(driver_list, driver_list_size);
	NtQuerySystemInformation((SYSTEM_INFORMATION_CLASS)0xB, driver_list, driver_list_size, &driver_list_size);
	return driver_list;
}