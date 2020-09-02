// Fill out your copyright notice in the Description page of Project Settings.

#include "z3camSDK.h"
#include "ProjectJK/ProjectJK.h"

Uz3camSDK::Uz3camSDK()
{
}

Uz3camSDK::~Uz3camSDK()
{
}

#if defined(_WIN64)
typedef void*(*_get_cr2_init)(uint32 sensorcode, uint32 sensornum, int64 p0, int64 p1, int64 p2, int64 p3);
#else
typedef void*(*_get_cr2_init)(uint32 sensorcode, uint32 sensornum, int32 p0, int32 p1, int32 p2, int32 p3);
#endif

typedef int(*_get_cr2_delete)(void* hand);

#if defined(_WIN64)
typedef int(*_get_cr2_command)(void* h, uint32 cmd, int64 p0, int64 p1, int64 p2, int64 p3);
#else
typedef int(*_get_cr2_command)(void* h, uint32 cmd, int32 p0, int32 p1, int32 p2, int32 p3);
#endif

_get_cr2_init m_cr2_init;
_get_cr2_delete m_cr2_delete;
_get_cr2_command m_cr2_command;

void *v_dllHandle;

#pragma region Load DLL
// Method to import a DLL.
bool Uz3camSDK::importDLL(FString folder, FString name)
{
	FString filePath = *FPaths::ProjectContentDir() + folder + "/" + name;

	if (FPaths::FileExists(filePath))
	{
		v_dllHandle = FPlatformProcess::GetDllHandle(*filePath); // Retrieve the DLL.
		if (v_dllHandle != NULL)
		{
			return true;
		}
	}
	return false;    // Return an error.
}
#pragma endregion Load DLL

#pragma region Unload DLL
void Uz3camSDK::freeDLL()
{
	if (v_dllHandle != NULL)
	{
		FPlatformProcess::FreeDllHandle(v_dllHandle);
		v_dllHandle = NULL;
	}
}
#pragma  endregion UnloadDLL


bool Uz3camSDK::import_initMethod()
{
	if (v_dllHandle != NULL)
	{
		m_cr2_init = NULL;
		FString procName = "CR2_init";    // Needs to be the exact name of the DLL method.
		m_cr2_init = (_get_cr2_init)FPlatformProcess::GetDllExport(v_dllHandle, *procName);

		if (m_cr2_init != NULL)
			return true;
	}
	return false;    // Return an error.
}
#if defined(_WIN64)
void* Uz3camSDK::CR2_init(uint32 sensorcode, uint32 sensornum, int64 p0, int64 p1, int64 p2, int64 p3)
#else
void* Uz3camSDK::CR2_init(uint32 sensorcode, uint32 sensornum, int32 p0, int32 p1, int32 p2, int32 p3)
#endif
{
	if (m_cr2_init != NULL)
		return m_cr2_init(sensorcode, sensornum, p0, p1, p2, p3);
	else
		return nullptr;
}

bool Uz3camSDK::import_deleteMethod()
{
	if (v_dllHandle != NULL)
	{
		m_cr2_delete = NULL;
		FString procName = "CR2_delete";    // Needs to be the exact name of the DLL method.
		m_cr2_delete = (_get_cr2_delete)FPlatformProcess::GetDllExport(v_dllHandle, *procName);

		if (m_cr2_delete != NULL)
			return true;
	}
	return false;    // Return an error.
}

int Uz3camSDK::CR2_delete(void* hand)
{
	if (m_cr2_delete != NULL)
		return m_cr2_delete(hand);
	else
		return -1;
}

bool Uz3camSDK::import_commandMethod()
{
	if (v_dllHandle != NULL)
	{
		m_cr2_command = NULL;
		FString procName = "CR2_command";    // Needs to be the exact name of the DLL method.
		m_cr2_command = (_get_cr2_command)FPlatformProcess::GetDllExport(v_dllHandle, *procName);

		if (m_cr2_command != NULL)
			return true;
	}
	return false;    // Return an error.
}

#if defined(_WIN64)
int Uz3camSDK::CR2_command(void* h, uint32 cmd, int64 p0, int64 p1, int64 p2, int64 p3)
#else
int Uz3camSDK::CR2_command(void* h, uint32 cmd, int32 p0, int32 p1, int32 p2, int32 p3)
#endif
{
	if (m_cr2_command != NULL)
		return m_cr2_command(h, cmd, p0, p1, p2, p3);
	else
		return -1;
}
