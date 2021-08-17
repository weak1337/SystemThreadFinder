namespace nt {
	int* get_proc_list();
	int* get_driver_list();
}

typedef struct _VM_COUNTERS {
	SIZE_T PeakVirtualSize;
	SIZE_T VirtualSize;
	ULONG PageFaultCount;
	SIZE_T PeakWorkingSetSize;
	SIZE_T WorkingSetSize;
	SIZE_T QuotaPeakPagedPoolUsage;
	SIZE_T QuotaPagedPoolUsage;
	SIZE_T QuotaPeakNonPagedPoolUsage;
	SIZE_T QuotaNonPagedPoolUsage;
	SIZE_T PagefileUsage;
	SIZE_T PeakPagefileUsage;
} VM_COUNTERS;



typedef struct _CLIENT_ID
{
	PVOID UniqueProcess;
	PVOID UniqueThread;
} CLIENT_ID, * PCLIENT_ID;


typedef struct
{
	FILETIME ProcessorTime;
	FILETIME UserTime;
	FILETIME CreateTime;
	ULONG WaitTime;
#ifdef _WIN64
	ULONG pad1;
#endif
	PVOID StartAddress;
	CLIENT_ID Client_Id;
	LONG CurrentPriority;
	LONG BasePriority;
	ULONG ContextSwitchesPerSec;
	ULONG ThreadState;
	ULONG ThreadWaitReason;
	ULONG pad2;
} SYSTEM_THREAD_INFORMATION;

typedef struct
{
	ULONG NextOffset;
	ULONG ThreadCount;
	LARGE_INTEGER WorkingSetPrivateSize;
	ULONG HardFaultCount;
	ULONG NumberOfThreadsHighWatermark;
	ULONGLONG CycleTime;
	FILETIME CreateTime;
	FILETIME UserTime;
	FILETIME KernelTime;
	UNICODE_STRING ImageName;
	long BasePriority;
#ifdef _WIN64
	ULONG pad1;
#endif
	ULONG ProcessId;
#ifdef _WIN64
	ULONG pad2;
#endif
	ULONG InheritedFromProcessId;
#ifdef _WIN64
	ULONG pad3;
#endif
	ULONG HandleCount;
	ULONG SessionId;
	ULONG_PTR UniqueProcessKey;
	VM_COUNTERS VirtualMemoryCounters;
	ULONG_PTR PrivatePageCount;
	IO_COUNTERS IoCounters;
	SYSTEM_THREAD_INFORMATION ThreadInfos[1];
} SYSTEM_PROCESS_INFORMATION;
typedef enum _SYSTEM_INFORMATION_CLASS {
	SystemBasicInformation = 0,
	SystemPerformanceInformation = 2,
	SystemTimeOfDayInformation = 3,
	SystemProcessInformation = 5,
	SystemProcessorPerformanceInformation = 8,
	SystemInterruptInformation = 23,
	SystemExceptionInformation = 33,
	SystemRegistryQuotaInformation = 37,
	SystemLookasideInformation = 45,
	SystemCodeIntegrityInformation = 103,
	SystemPolicyInformation = 134,
} SYSTEM_INFORMATION_CLASS;

typedef struct _SYSTEM_MODULE_ENTRY {
	HANDLE Section;
	PVOID MappedBase;
	PVOID ImageBase;
	ULONG ImageSize;
	ULONG Flags;
	USHORT LoadOrderIndex;
	USHORT InitOrderIndex;
	USHORT LoadCount;
	USHORT OffsetToFileName;
	UCHAR FullPathName[256];
} SYSTEM_MODULE_ENTRY, * PSYSTEM_MODULE_ENTRY;

typedef struct _SYSTEM_MODULE_INFORMATION {
	ULONG Count;
	SYSTEM_MODULE_ENTRY Module[1];
} SYSTEM_MODULE_INFORMATION, * PSYSTEM_MODULE_INFORMATION;

extern "C" NTSTATUS NtQuerySystemInformation(SYSTEM_INFORMATION_CLASS SystemInformationClass, PVOID SystemInformation, ULONG SystemInformationLength, PULONG ReturnLength);