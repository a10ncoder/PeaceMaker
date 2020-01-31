#pragma once
#include "common.h"
#include "DetectionLogic.h"
#include "ImageHistoryFilter.h"
#include "FSFilter.h"
#include "RegistryFilter.h"

typedef class IOCTLCommunication
{
	static PDRIVER_OBJECT DriverObject;
	static PDETECTION_LOGIC Detector;
	static PIMAGE_HISTORY_FILTER ImageProcessFilter;
	static PFLT_FILTER FileFilterHandle;
	static PFS_BLOCKING_FILTER FilesystemMonitor;
	static PREGISTRY_BLOCKING_FILTER RegistryMonitor;

	NTSTATUS InitializeDriverIOCTL(VOID);
	VOID UninitializeDriverIOCTL(VOID);

	static NTSTATUS IOCTLCreateClose(
		_In_ PDEVICE_OBJECT DeviceObject,
		_In_ PIRP Irp
		);
	static NTSTATUS IOCTLDeviceControl(
		_In_ PDEVICE_OBJECT DeviceObject,
		_In_ PIRP Irp
		);

public:
	IOCTLCommunication(
		_In_ PDRIVER_OBJECT Driver,
		_In_ PFLT_FILTER_UNLOAD_CALLBACK UnloadRoutine,
		_Inout_ NTSTATUS* InitializeStatus
		);
	~IOCTLCommunication(VOID);
} IOCTL_COMMUNICATION, *PIOCTL_COMMUNICATION;

#define DETECTION_LOGIC_TAG 'lDmP'
#define IMAGE_HISTORY_FILTER_TAG 'fImP'
#define FILE_MONITOR_TAG 'mFmP'
#define REGISTRY_MONITOR_TAG 'mRmP'