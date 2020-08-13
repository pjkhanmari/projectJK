// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
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


//---------- Command Code
#define	CR2CMD_NULL					0x00000000
#define	CR2CMD_DLLVERSION			0x00000001
#define	CR2CMD_SENSORCONFIG			0x00000002
#define	CR2CMD_CAMSENSORCONFIG		0x00000003
#define	CR2CMD_OPERATION_START		0x00000010
#define	CR2CMD_OPERATION_STOP		0x00000011
#define	CR2CMD_OPERATION_RESTART	0x00000012					
#define	CR2CMD_OPERATION_ACTIVATE	0x00000013				// p0,  0: Power-Saving mode,  1: Normal Mode
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

UCLASS()
class PROJECTJK_API Uz3camHandler : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
// 	UFUNCTION(BlueprintCallable, Category = "z3cam")
// 		static FString GetVersion();
// 	UFUNCTION(BlueprintCallable, Category = "z3cam")
// 		static int SetHeightIncline(int height, int vangleadd);
// 	UFUNCTION(BlueprintCallable, Category = "z3cam")
// 		static int ConfigureCamSensor(int usage);
// 	UFUNCTION(BlueprintCallable, Category = "z3cam")
// 		static int Set_Tee(int usage, double height);
// 	UFUNCTION(BlueprintCallable, Category = "z3cam")
// 		static int Set_Club(int clubcode);
// 	UFUNCTION(BlueprintCallable, Category = "z3cam")
// 		static int Set_Wind(float mag, float dir);
// 	UFUNCTION(BlueprintCallable, Category = "z3cam")
// 		static int  Set_MainHand(int _hand);
// 	UFUNCTION(BlueprintCallable, Category = "z3cam")
// 		static int SetTeeState(int p0, int p1);
// 	UFUNCTION(BlueprintCallable, Category = "z3cam")
// 		static int GetSensorState(int* state);
// 	UFUNCTION(BlueprintCallable, Category = "z3cam")
// 		static int AllowArea(int tee, int ground, int putting);
// 	UFUNCTION(BlueprintCallable, Category = "z3cam")
// 		static int CheckBallPosition(_CR2_ballposition &tee, _CR2_ballposition &ground, _CR2_ballposition &putting);
	
};
