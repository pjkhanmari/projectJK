// Fill out your copyright notice in the Description page of Project Settings.


#include "z3camSDK.h"

z3camSDK::z3camSDK()
{
}

z3camSDK::~z3camSDK()
{
}

typedef void*(*_get_cr2_init)(int sensorcode, int sensornum, long long p0, long long p1, long long p2, long long p3);
typedef int(*_get_cr2_delete)(void* hand);
typedef int(*_get_cr2_command)(void* h, unsigned int cmd, long long p0, long long p1, long long p2, long long p3);

_get_cr2_init m_cr2_init;
_get_cr2_delete m_cr2_delete;
_get_cr2_command m_cr2_command;

void *v_dllHandle;

#pragma region Load DLL
// Method to import a DLL.
bool z3camSDK::importDLL(FString folder, FString name)
{
	FString filePath = *FPaths::EnginePluginsDir() + folder + "/" + name;

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
void z3camSDK::freeDLL()
{
	if (v_dllHandle != NULL)
	{
		FPlatformProcess::FreeDllHandle(v_dllHandle);
		v_dllHandle = NULL;
	}
}
#pragma  endregion UnloadDLL


bool z3camSDK::import_initMethod()
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

void* z3camSDK::CR2_init(int sensorcode, int sensornum, long long p0, long long p1, long long p2, long long p3)
{
	if (m_cr2_init != NULL)
		return m_cr2_init(sensorcode, sensornum, p0, p1, p2, p3);
	else
		return nullptr;
}

bool z3camSDK::import_deleteMethod()
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

int z3camSDK::CR2_delete(void* hand)
{
	if (m_cr2_delete != NULL)
		return m_cr2_delete(hand);
	else
		return -1;
}

bool z3camSDK::import_commandMethod()
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

int z3camSDK::CR2_command(void* h, unsigned int cmd, long long p0, long long p1, long long p2, long long p3)
{
	if (m_cr2_command != NULL)
		return m_cr2_command(h, cmd, p0, p1, p2, p3);
	else
		return -1;
}
