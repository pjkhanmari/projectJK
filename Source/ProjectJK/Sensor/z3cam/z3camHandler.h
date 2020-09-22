// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ProjectJK/Sensor/z3cam/z3camStructures/CR2_ballposition.h"
#include "ProjectJK/Sensor/z3cam/z3camStructures/CR2_shotdata.h"
#include "ProjectJK/Sensor/z3cam/z3camStructures/CR2_shotdataEX.h"
#include "ProjectJK/Sensor/z3cam/z3camStructures/CR2_guid.h"
#include "Windows/WindowsSystemIncludes.h"
#include "z3camHandler.generated.h"

/**
 * 
 */

// ----------Result Code(CR2_result_t)
#define	CR2_OK						0x00000000

#define	CR2_ERR_GENERAL				0x80000000
#define	CR2_ERR_BADHANDLE			0x80000001
#define	CR2_ERR_UNSUPPORTED_CMD		0x80000010
#define	CR2_ERR_BADPARAM			0x80000011
#define	CR2_ERR_CAM_RESERVE_FAIL	0x80000020
#define	CR2_ERR_CAM_NOT_OWNER		0x80000021
#define	CR2_ERR_CAM_CONFIG_FAIL		0x80000022

#define	CR2_IS_RESULT_ERROR(x)	(CR2_ERR_GENERAL & (x))


//---------- Sensor Status
#define	CR2STATUS_NULL				0x00000000
#define	CR2STATUS_READY				0x00000001
#define	CR2STATUS_GOODSHOT			0x00000010
#define	CR2STATUS_TRIALSHOT			0x00000011
#define	CR2STATUS_DISCONNECT		0x00000100
#define	CR2STATUS_BIGSHADOW			0x00000101
#define	CR2STATUS_NOBALL			0x00000102
#define	CR2STATUS_LOWACTIVE			0x00000103

//---------- Club Code
#define	CR2CLUB_WOOD1				1
#define	CR2CLUB_DRIVER				CR2CLUB_WOOD1
#define	CR2CLUB_WOOD2				2
#define	CR2CLUB_WOOD3				3
#define	CR2CLUB_WOOD4				4
#define	CR2CLUB_WOOD5				5
#define	CR2CLUB_WOOD6				6
#define	CR2CLUB_WOOD7				7
#define	CR2CLUB_WOOD8				8
#define	CR2CLUB_WOOD9				9

#define	CR2CLUB_IRON1				11
#define	CR2CLUB_IRON2				12
#define	CR2CLUB_IRON3				13
#define	CR2CLUB_IRON4				14
#define	CR2CLUB_IRON5				15
#define	CR2CLUB_IRON6				16
#define	CR2CLUB_IRON7				17
#define	CR2CLUB_IRON8				18
#define	CR2CLUB_IRON9				19
#define	CR2CLUB_IRONP				20
#define	CR2CLUB_IRONG				21
#define	CR2CLUB_IRONS				22
#define	CR2CLUB_IRONL				23

#define	CR2CLUB_PUTTER				30

#define	CR2CLUB_LADY_ADD			1000
#define	CR2CLUB_LADY(x)				((x) + CR2CLUB_LADY_ADD)

   //---------- mark option
#define	CR2CLUBCALC_DEFAULT			0
#define	CR2CLUBCALC_NOCALC			1
#define	CR2CLUBCALC_CLUB_NOMARK		2
#define	CR2CLUBCALC_CLUB_MARK1		3
#define	CR2CLUBCALC_CLUB_MARK2		4


//---------- Command Code
#define	CR2CMD_NULL					0x00000000
#define	CR2CMD_DLLVERSION			0x00000001
#define	CR2CMD_SENSORCONFIG			0x00000002
#define	CR2CMD_CAMSENSORCONFIG		0x00000003
#define	CR2CMD_OPERATION_START		0x00000010
#define	CR2CMD_OPERATION_STOP		0x00000011
#define	CR2CMD_OPERATION_RESTART	0x00000012					
#define	CR2CMD_OPERATION_ACTIVATE	0x00000013				// p0,  0: Power-Saving mode,  1: Normal Mode
#define	CR2CMD_OPERATION_START1		0x00000014				// p0: callbackfuncion1.   p1: callbackfunction1_id p1; user param.
#define	CR2CMD_USETEE				0x00000020
#define	CR2CMD_USECLUB				0x00000021
#define	CR2CMD_WIND					0x00000022
#define	CR2CMD_SETTEESTATE			0x00000023
#define	CR2CMD_SETRIGHTLEFT			0x00000024				// p0, 0: Right-handed sensor, 1: Left-handed sensor


#define	CR2CMD_SENSORSTATUS			0x00000030
#define	CR2CMD_SENSORSTATUS2		0x00000031
#define	CR2CMD_AREAALLOW			0x00000032
#define	CR2CMD_BALLPOSITION			0x00000033
#define	CR2CMD_SHOTRESULTEX			0x00000034				// 	p0, 0: Don't clear result, 1: Clear result
															//  p1: CR2_shotdata_ballEx_t
#define	CR2CMD_CALC_TRAJECTORY		0x00000040
#define	CR2CMD_SET_ALTITUDE			0x00000042				// p0: altitutde in m 
#define	CR2CMD_SET_CLUBMODE			0x00000043				// p0: club mode. 0: Default. 1: NO Club CALC. 2: NO Club Marking, 3: Club Marking #1, 4: Club Marking #2
#define	CR2CMD_CAM_RESERVE_CH		0x00000050
#define	CR2CMD_CAM_RELEASE_CH		0x00000051
#define	CR2CMD_CAM_CONFIG			0x00000052
#define	CR2CMD_CAM_OPERATION_START	0x00000053
#define	CR2CMD_CAM_OPERATION_STOP	0x00000054

//----
#define	CR2CMD_SWINGCAM_OPEN			0x00000060
#define	CR2CMD_SWINGCAM_CLOSE			0x00000061
#define	CR2CMD_SWINGCAM_START			0x00000062
#define	CR2CMD_SWINGCAM_STOP			0x00000063
#define	CR2CMD_SWINGCAM_READYREPLAY		0x00000064
#define	CR2CMD_SWINGCAM_MANUALREPLAY	0x00000065
#define	CR2CMD_SWINGCAM_AUTOREPLAY		0x00000066
#define	CR2CMD_SWINGCAM_LOADPLAY		0x00000067

//----	2012/0927
#define	CR2CMD_AUTOTEE_OPEN			0x00000070
#define	CR2CMD_AUTOTEE_CLOSE		0x00000071
#define	CR2CMD_AUTOTEE_SETHEIGHT	0x00000072
#define	CR2CMD_AUTOTEE_GETDATA		0x00000073
#define	CR2CMD_AUTOTEE_GETHEIGHT	0x00000074
#define	CR2CMD_AUTOTEE_GETEVENT		0x00000075
#define	CR2CMD_AUTOTEE_SENDCMD		0x00000076

//----	2012/1009
#define	CR2CMD_SWINGPLATE_OPEN		0x00000080
#define	CR2CMD_SWINGPLATE_CLOSE		0x00000081
#define	CR2CMD_SWINGPLATE_SETDATA	0x00000082
#define	CR2CMD_SWINGPLATE_GETSTATE	0x00000083

//----	2016/0304
#define	CR2CMD_SHOTDATAEX			0x00000090			// Get Extended Shot data
#define	CR2CMD_RIGHTLEFTCONNECTION	0x00000091			// p0: right sensor is connected,  p1: left sensor is connected
#define	CR2CMD_IRONAREAALLOW		0x00000092			// p0: Fairway is allowed. p1: Rough is allowed. p2: Bunker is allowed

//----
#define	CR2CMD_TEST					0x00000100


//---------- Sensor Board Code
#define	CR2SENSORBOARD_N1P1			0x00000011
#define	CR2SENSORBOARD_N1P2			0x00000012
#define	CR2SENSORBOARD_N1PL			0x00000013
#define	CR2SENSORBOARD_N1PL2		0x00000014


//---------- Camera Image Resolution
#define	CR2CAMERA_RESOLUTION_NULL		0x00000000
#define	CR2CAMERA_RESOLUTION_320x240	0x00000001
#define	CR2CAMERA_RESOLUTION_640x480	0x00000002
#define	CR2CAMERA_RESOLUTION_640x240	0x00000003
#define	CR2CAMERA_RESOLUTION_720x480	0x00000004
#define	CR2CAMERA_RESOLUTION_720x240	0x00000005


//---------- Camera Image Color format
#define	CR2CAMERA_IMAGE_RGB					0x00000000
#define	CR2CAMERA_IMAGE_YUV422_PLANAR		0x00000001
#define	CR2CAMERA_IMAGE_YUV422_INTERLACED	0x00000002
#define	CR2CAMERA_IMAGE_YUV420_PLANAR		0x00000003
#define	CR2CAMERA_IMAGE_YUV420_INTERLACED	0x00000004


#define	CR2CAM_STATE_NULL			0x00000000	
#define	CR2CAM_STATE_INITED			0x00000001
#define	CR2CAM_STATE_RESERVED		0x00000002
#define	CR2CAM_STATE_STARTED		0x00000003


//-------  2012/0927, for Autotee interface.
#define AUTOTEE_VENDOR_NULL					0
#define AUTOTEE_VENDOR_DEFAULT				(AUTOTEE_VENDOR_NULL)
#define AUTOTEE_VENDOR_JUNGWON_MAGICSHOT	0x0001
#define AUTOTEE_VENDOR_CITYANDTECH			0x0002

#define AUTOTEE_MODEL_NULL					0x0000
#define AUTOTEE_MODEL_DEFAULT				(AUTOTEE_MODEL_NULL)

	// Model number for JUNGWONG Magicshot.
#define AUTOTEE_MODEL_JUNGWON_S50			0x0001
#define AUTOTEE_MODEL_JUNGWON_S100			0x0002
#define AUTOTEE_MODEL_JUNGWON_S185			0x0003
#define AUTOTEE_MODEL_JUNGWON_S125			0x0004

#define AUTOTEE_MODEL_CITYANDTECH_JD001		0x0011

	// Current state of Autotee
#define AUTOTEE_STATE_NULL					0x0000
#define AUTOTEE_STATE_CONNECTED				0x0001
#define AUTOTEE_STATE_NEWDATA				0x0002
#define AUTOTEE_STATE_DISCONNECTED			0x0003
#define AUTOTEE_STATE_ERROR					0x0004

	// Current state of Autotee
#define AUTOTEE_EVENT_NULL					0x0000
#define AUTOTEE_EVENT_HEIGHT				0x0001
#define AUTOTEE_EVENT_KEY					0x0002


//-------  2012/1009, for SwingPlate interface.
#define SWINGPLATE_VENDOR_NULL					0
#define SWINGPLATE_VENDOR_DEFAULT				(AUTOTEE_VENDOR_NULL)
#define SWINGPLATE_VENDOR_JUNGWON				0x0001

#define SWINGPLATE_MODEL_NULL					0x0000
#define SWINGPLATE_MODEL_DEFAULT				(AUTOTEE_MODEL_NULL)

	// Model number for JUNGWONG 
#define SWINGPLATE_MODEL_JUNGWON_1				0x0001

	// Current state of Autotee
#define SWINGPLATE_STATE_NULL					0x0000
#define SWINGPLATE_STATE_CONNECTED				0x0001
#define SWINGPLATE_STATE_BUSY					0x0002
#define SWINGPLATE_STATE_DISCONNECTED			0x0003
#define SWINGPLATE_STATE_ERROR					0x0004

	// Swing Plate Direction code for type1 data.
#define SPDIR_INIT				0
#define SPDIR_DN				1
#define SPDIR_NE				2
#define SPDIR_DE				3
#define SPDIR_SE				4
#define SPDIR_DS				5
#define SPDIR_SW				6
#define SPDIR_DW				7
#define SPDIR_NW				8

//  Contact Creatz Inc. for valid ccode.            
#define		IANA_OPMODE_DEFAULT				0x0000
#define		IANA_OPMODE_CAM					0x0001
#define		IANA_OPMODE_FILE				0x0002

#define GET_VARIABLE_NAME(Variable) (#Variable)

#define CLIENT_CODE_LENGTH 16

USTRUCT(BlueprintType)
struct FHAND {

	GENERATED_USTRUCT_BODY()

public:
	void* h;
	TArray<uint32> ccode;
	std::function<int32(Uz3camHandler&, void* h, uint32 status, void* hsd, uint32 cbfuncid, int64 userparam)> cb;
};

static int32 cbWrapper(void* h, uint32 status, void* hsd, uint32 cbfuncid, int64 userparam);

UCLASS()
class PROJECTJK_API Uz3camHandler : public UObject
{
	GENERATED_BODY()
		
	Uz3camHandler(const FObjectInitializer& ObjectInitializer);
	~Uz3camHandler();

public:
#if defined(_WIN64)
	int32 (WINAPI CR2_CALLBACKFUNC)(void* h, uint32 status, FCR2_shotdata *psd, int64 userparam);
#else
	int32 (WINAPI CR2_CALLBACKFUNC)(void* h, uint32 status, FCR2_shotdata *psd, int32 userparam);
#endif

#if defined(_WIN64)
	int32 (WINAPI CR2_CALLBACKFUNC1)(void* h, uint32 status, void* hsd, uint32 cbfuncid, int64 userparam);
#else
	int32 (WINAPI CR2_CALLBACKFUNC1)(void* h, uint32 status, void* hsd, uint32 cbfuncid, int32 userparam);
#endif
	void Initialize();
	void DeInitialize();
	bool Init();
	FString Start();
	FString Restart();
	bool Stop();
	FString Shutdown();
	/// <summary>
	/// Get version of CR2 Interface API dll
	/// </summary>
	FString GetVersion();

	/// <summary>
	/// Set Lamp height and base value of incline
	/// height : Height between sensor and lamp. Unit : cm
	/// vangleadd : Base value of incline. Unit : degree
	/// </summary>
#if(_WIN64)
	void SetHeightIncline(int64 height, int64 vangleadd);
#else
	void SetHeightIncline(int32 height, int32 vangleadd);
#endif

	/// <summary>
	/// Set usage of Camera Sensor
	/// usage : camera sensor usage 0 -> Do not use, 1 -> Use
	/// </summary>
#if(_WIN64)
	void ConfigureCamSensor(int64 usage);
#else
	void ConfigureCamSensor(int32 usage);
#endif

	/// <summary>
	/// Usage of tee for current shot and set tee height
	/// usage : 0->No Use, 1->Use
	/// height : tee height. Unit : 1/1000m
	/// </summary>
#if(_WIN64)
	void Set_Tee(int64 usage, int64 height);
#else
	void Set_Tee(int32 usage, int32 height);
#endif

	/// <summary>
	/// Set Club
	/// clubcode : DRIVER->1, IRON7->17, PUTTER->30
	/// </summary>
#if(_WIN64)
	void Set_Club(int64 clubcode);
#else
	void Set_Club(int32 clubcode);
#endif

	/// <summary>
	/// Set Wind information
	/// mag : Wind velocity. Unit : 1/10ms
	/// dir : Direction of WInd. Unit : degree ( Direction reference is target line and increase clockwise)
	/// </summary>
#if(_WIN64)
	void Set_Wind(int64 mag, int64 dir);
#else
	void Set_Wind(int32 mag, int32 dir);
#endif

	/// <summary>
	/// Set Main Hand
	/// hand : 1 is LEFT handed, 0 is RIGHT handed
	/// </summary>
#if(_WIN64)
	void Set_MainHand(int64 _hand);
#else
	void Set_MainHand(int32 _hand);
#endif

	/// <summary>
	/// Set Altitude
	/// altitude : default is 0, Unit : m
	/// </summary>
#if(_WIN64)
	void Set_Altitude(int64 altitude);
#else
	void Set_Altitude(int32 altitude);
#endif

	/// <summary>
	/// Set Club data calculate option
	/// option : 0 -> default, 1->no calculate, 2->no mark, 3 -> mark1, 4 -> mark2 (just use 1, 2, 3)
	/// </summary>
#if(_WIN64)
	void Set_ClubdataCalOption(int64 altitude);
#else
	void Set_ClubdataCalOption(int32 altitude);
#endif

	/// <summary>
	/// Set Tee State?
	/// </summary>
#if(_WIN64)
	void SetTeeState(int64 param1, int64 param2);
#else
	void SetTeeState(int32 param1, int32 param2);
#endif

	/// <summary>
	/// Get current operation status of Sensor
	/// state should allocate 4 byte
	/// </summary>
	/// <returns>
	/// status value of Sensor operation
	/// </returns>
	int32 GetSensorState();

	/// <summary>
	/// Set allow Area to Sensor. tee area, ground area, putting area
	/// whole three area : 0 -> Not allow, 1 -> Allow
	/// </summary>
#if(_WIN64)
	void AllowArea(int64 tee, int64 ground, int64 putting);
#else
	void AllowArea(int32 tee, int32 ground, int32 putting);
#endif

	int CalCulateTrajectory(FCR2_shotdata* data);

	/// <summary>
	/// Check ball position and existing in area
	/// exist check tee, ground, putting area, also check detail position on x, y, z property
	/// </summary>
	void CheckBallPosition();

	FString PrintResult(const FString title, int result);

public:
	UPROPERTY()
	bool showLog = true;
	UPROPERTY()
	bool importSuccess;
	UPROPERTY()
	FHAND hand;
};
