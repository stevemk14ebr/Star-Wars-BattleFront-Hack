// Generated using ReClass 2014
#pragma once
#define OFFSET_DX11RENDERER 0x142E2C4B0//0x142E1A330;
#define OFFSET_MAIN 0x142A111D0//0x1429FF0C0;
#define OFFSET_GAMERENDERER 0x142E2C618//0x142E1A498;
#define OFFSET_GETENTITYLIST 0x143B32090 //0x143B099C0;
#define OFFSET_FIRSTTYPEINFO 0x142A2B648

#include "Engine/TypeInfo.h"
#include <d3d11.h>
class Main;
class Client;
class GameContext;
class ClientSettings;
class PlayerManager;
class ClientPlayer;
class Player;
class ClientSoldierEntity;
class ClientSoldierPhysicsComponent;
class ClientSoldierHealthComponent;
class ClientAntAnimatableEntity;
class ClientSoldierWeaponsComponent;
class WeaponnHandler;
class ClientSoldierWeapon;
class ClientWeapon;
class WeaponFiring;
class PrimaryFire;
class FiringFunctionData;
class ShotConfigData;
class BulletEntityData;
class ProjectileEntityData;
class WeaponSuppressionData;
class MeshProjectileEntityData;
class WeaponSway;
class GunSwayData;
class SoldierAimingSimulation;
class ClientAimEntity;
class AimAssist;
class ClientRagdollComponent;
class AnimationSkeleton;
class SkeletonAsset;
class UpdatePoseResultData;
class ClientVehicleEntity;
class ClientVehicleHealthComponent;
class ClientVehiclePhysicsComponent;
class ppQuatTransform;
class QuatTransform;

class Main
{
public:
	char _0x0000[80];
	Client* m_Client; //0x0050
	static Main* GetInstance()
	{
		return *(Main**)OFFSET_MAIN;
	}
};//Size=0x0058

class Client
{
public:
	char _0x0000[56];
	GameContext* m_GameContext; //0x0038 
	ClientSettings* m_ClientSettings; //0x0040 
	char _0x0048[8];
	PlayerManager* m_PlayerManager; //0x0050 
	char _0x0058[32];
};//Size=0x0078

class PhysicsManager
{
public:
	char _0x0000[64];
};//Size=0x0040

class Level
{
public:
	char _0x0000[24];
	__int64 m_LevelData; //0x0018 
	char _0x0020[232];
	PhysicsManager* m_pHavokPhysicsManager; //0x0108 
	char _0x0110[8];
	__int64 m_pGameWorld; //0x0118 
	char _0x0120[16];
};//Size=0x0130

class GameContext
{
public:
	char _0x0000[48];
	Level* m_pLevel; //0x0030 
	char _0x0038[8];
};//Size=0x0040

class ClientSettings
{
public:
	char _0x0000[64];
};//Size=0x0040

class PlayerManager
{
public:
	char _0x0000[1360];
	ClientPlayer* m_pLocalPlayer; //0x0550 
	char _0x0558[504];
	ClientPlayer** m_ppPlayers; //0x0750 
	ClientPlayer* GetPlayerById(unsigned int id)
	{
		if (id < 40)
			return this->m_ppPlayers[id];
		return nullptr;
	}
};//Size=0x0758

class Player
{
public:
	virtual ~Player();
	virtual void* GetCharacterEntity(); // ClientSoldierEntity + 188 
	virtual void* GetCharacterUserData(); // PlayerCharacterUserData
	virtual void* GetEntryComponent();
	virtual bool InVehicle();
	virtual unsigned int GetId();
	virtual bool hasUnlockAsset(LPVOID, bool);
	virtual void getUnlockAssets(void**);
	virtual bool isUnlocked(LPVOID);

	char _0x0000[16];
	char* m_LocalName; //0x0018 
	char _0x0020[32];
	char m_Name[32]; //0x0040 
};//Size=0x0060

class ClientPlayer : public Player
{
public:
	char _0x0060[7156];
	__int32 m_TeamId; //0x1C54 
	char _0x1C58[248];
	ClientVehicleEntity* m_AttachedControllable; //0x1D50 
	char _0x1D58[8];
	ClientSoldierEntity* m_ControlledControllable; //0x1D60 

	ClientSoldierEntity* GetSoldierEntity()
	{
		if (this->InVehicle())
			return nullptr; //TODO

		if (m_ControlledControllable)
			return m_ControlledControllable;
		return nullptr;
	}
	ClientVehicleEntity* GetVehicleEntity()
	{
		if (this->InVehicle())
			return m_AttachedControllable;
		return nullptr;
	}
};//Size=0x1D68

class LinearTransform
{
public:
	union
	{
		struct
		{
			SM::Vector3 left;
			SM::Vector3 up;
			SM::Vector3 forward;
			SM::Vector3 trans;
		};
		FLOAT data[4][4];
	};
	LinearTransform()
	{}
};

class AxisAlignedBox
{
public:
	SM::Vector4 m_Min; //0x0000 
	SM::Vector4 m_Max; //0x0010 

	AxisAlignedBox()
	{}
};//Size=0x0020

struct TransformAABBStruct {
	LinearTransform Transform;
	AxisAlignedBox AABB;
	SM::Matrix pad;

	TransformAABBStruct()
	{}
};

class ClientControllableEntity
{
public:
	virtual void* GetTypeInfo();
	virtual void Function1(); //
	virtual void Function2(); //
	virtual void Function3(); //
	virtual void Function4(); //
	virtual void Function5(); //
	virtual void Function6(); //
	virtual void Function7(); //
	virtual void Function8(); //
	virtual void Function9(); //
	virtual void Function10(); //
	virtual void Function11(); //
	virtual void Function12(); //
	virtual void Function13(); //
	virtual void Function14(); //
	virtual void Function15(); //
	virtual void Function16(); //
	virtual void Function17(); //
	virtual void Function18(); //
	virtual void Function19(); //
	virtual void Function20(); //
	virtual void Function21(); //
	virtual void Function22();
	virtual void GetAABB(TransformAABBStruct* pAABB);
	virtual void GetTransform(SM::Matrix* mTransform);
};

class ClientSoldierEntity : public ClientControllableEntity
{
public:
	char _0x0000[16];
	unsigned char m_UnkFlag; //0x0018 
	unsigned char m_UnkFlag2; //0x0019 
	unsigned char m_OcclusionFlags; //0x001A 
	char _0x001B[21];
	__int64 m_Data; //0x0030 
	char _0x0038[40];
	ClientSoldierPhysicsComponent* m_PhysicsComponenet; //0x0060 
	char _0x0068[160];
	__int64 m_SpawnEntity; //0x0108 
	char _0x0110[136];
	ClientSoldierHealthComponent* m_HealthComponent; //0x0198 
	char _0x01A0[160];
	ClientAntAnimatableEntity* m_Animatable; //0x0240 
	ClientAntAnimatableEntity* m_Animatable2; //0x0248 
	char _0x0250[776];
	__int32 m_Pose; //0x0558 
	unsigned char m_RenderFlags; //0x055C 
	unsigned char m_Chams; //0x055D 
	char _0x055E[90];
	ClientSoldierWeaponsComponent* m_WeaponComponent; //0x05B8 
	char _0x05C0[8];
	ClientRagdollComponent* m_RagdollComponent; //0x05C8 
	char _0x05D0[16];
	ClientAimEntity* m_AimEntity; //0x05E0 
	char _0x05E8[24];
	unsigned char m_Sprinting; //0x0600 
	unsigned char m_Occluded; //0x0601 

};//Size=0x0602

class ClientSoldierPhysicsComponent
{
public:
	char _0x0000[64];

};//Size=0x0040

class ClientSoldierHealthComponent
{
public:
	char _0x0000[32];
	float m_Health; //0x0020 
	float m_MaxHealth; //0x0024 
	char _0x0028[24];
	float m_PreviousHealth; //0x0040 
};//Size=0x0044

class ClientAntAnimatableEntity
{
public:
	char _0x0000[128];
};//Size=0x0080

class ClientSoldierWeaponsComponent
{
public:
	char _0x0000[224];
	SM::Matrix m_WeaponTransform; //0x00E0 
	char _0x0120[1912];
	WeaponnHandler* m_SoldierWeaponHandler; //0x0898 
	char _0x08A0[96];
	ClientSoldierEntity* m_Owner; //0x0900 
	char _0x0908[136];
	__int32 m_CurrentWeaponIndex; //0x0990 
	__int32 m_LastWeaponIndex; //0x0994 
	__int32 m_LastGunIndex; //0x0998 
	char _0x099C[36];
	__int32 m_CurrentZoomLevel; //0x09C0 
	__int32 m_MaxZoomLevel; //0x09C4 
};//Size=0x09C8

class WeaponnHandler
{
public:
	ClientSoldierWeapon* m_pWeaponList[7]; //0x0000 
};//Size=0x0008

class ClientSoldierWeapon
{
public:
	char _0x0000[48];
	__int64 m_Data; //0x0030 
	char _0x0038[18880];
	ClientWeapon* m_pWeapon; //0x49F8 
	char _0x4A00[16];
	WeaponFiring* m_pPrimary; //0x4A10 
	char _0x4A18[56];
};//Size=0x4A50

class ClientWeapon
{
public:
	char _0x0000[8];
	__int64 m_BlasterWeaponData; //0x0008 
	char _0x0010[8];
	PrimaryFire* m_WeaponFiringData; //0x0018 
	char _0x0020[16];
	SM::Vector4 m_Velocity; //0x0030 
	SM::Matrix m_ShootSpace; //0x0040 
	SM::Matrix m_ShootSpaceIdentity; //0x0080 
};//Size=0x00C0

class WeaponFiring
{
public:
	char _0x0000[128];
	WeaponSway* m_pWeaponSway; //0x0080 
	char _0x0088[168];
	PrimaryFire* m_pPrimaryFire; //0x0130 
	char _0x0138[32];
	__int32 m_WeaponState; //0x0158 
	__int32 m_LastWeaponState; //0x015C 
	__int32 m_NextWeaponState; //0x0160 
	char _0x0164[96];
	unsigned char m_IsNotFiring; //0x01C4 
	unsigned char m_IsFiring; //0x01C5 
	unsigned char m_IsOverHeated; //0x01C6 
};//Size=0x01C7

class PrimaryFire
{
public:
	char _0x0000[16];
	FiringFunctionData* m_FiringData; //0x0010 
	char _0x0018[24];
	__int64 m_GunSwayData; //0x0030 
};//Size=0x0038

class ShotConfigData
{
public:
	SM::Vector4 m_PositionOffset; //0x0000 
	SM::Vector4 m_Direction; //0x0010 
	SM::Vector4 m_Velocity; //0x0020 
	char _0x0030[32];
	BulletEntityData* m_ProjectileData; //0x0050 
	char _0x0058[24];
	float m_SpawnDelay; //0x0070 
	__int32 m_BulletsPerShell; //0x0074 
	__int32 m_BulletsPerShot; //0x0078 
	__int32 m_BulletsPerBurst; //0x007C 
	unsigned char m_RelativeTargetAiming; //0x0080 
	unsigned char m_ForceSpawnToWeapon; //0x0081 
	unsigned char m_SpawnVisualAtWeaponBone; //0x0082 
	unsigned char m_ActiveForceSpawnToWeapon; //0x0083 
	char _0x0084[12]; //0x0084 
};//Size=0x0090

class FiringFunctionData
{
public:
	char _0x0000[96];
	ShotConfigData m_ShotConfigData; //0x0060 
};//Size=0x00F0

class ProjectileEntityData
{
public:
	char _0x0000[96];
	char* m_Name; //0x0060 
	char _0x0068[40];
	float m_InitialSpeed; //0x0090 
	float m_TimeToLive; //0x0094 
	__int32 m_MaxCount; //0x0098 
	float m_InitMeshHideTime; //0x009C 
	float m_VisualConvergeDistance; //0x00A0 
	float m_VisualConvergeDelay; //0x00A4 
	float m_ProxyVisualConvergeDelay; //0x00A8 
	float m_ProxyVisualConvergeDuration; //0x00AC 
	char _0x00B0[16];
	WeaponSuppressionData* m_pSuppressionData; //0x00C0 
	char _0x00C8[12];
	__int32 m_HitReactionWeaponType; //0x00D4 
	unsigned char m_DetonateOnTimeout; //0x00D8 
	unsigned char m_ServerProjectileDisabled; //0x00D9 
	char N0000192A[6]; //0x00DA 
};//Size=0x00E0

class MeshProjectileEntityData
{
public:
	SM::Vector4 m_AngularVelocity; //0x0000 
	char _0x0010[16];
	float m_InstantAttachableTestDistance; //0x0020 
	float m_InstantAttachableVisualConvergenceDelay; //0x0024 
	float m_InstantAttachableVisualConvergenceDuration; //0x0028 
	float m_MaxAttachableInclination; //0x002C 
	float m_UnspawnAfterDetonationDelay; //0x0030 
	unsigned char m_IsAttachable; //0x0034 
	unsigned char m_InstantAttachableUnderReticle; //0x0035 
	unsigned char m_ExtraDamping; //0x0036 
	char N000019C7[9]; //0x0037 
};//Size=0x0040

class BulletEntityData : public ProjectileEntityData
{
public:
	MeshProjectileEntityData m_MeshProjectileEntityData; //0x00E0 
	char _0x0120[32];
	float m_Gravity; //0x0140 
	float m_ImpactImpulse; //0x0144 
	float m_DetonationTimeVariance; //0x0148 
	float m_VehicleDetonationRadius; //0x014C 
	float m_VehicleDetonationActivationDelay; //0x0150 
	float m_FlyBySoundRadius; //0x0154 
	float m_FlyBySoundSpeed; //0x0158 
	float m_Stamina; //0x015C 
	float m_DistributeDamageOverTime; //0x0160 
	float m_StartDamage; //0x0164 
	float m_EndDamage; //0x0168 
	float m_DamageFalloffStartDist; //0x016C 
	float m_DamageFalloffEndDist; //0x0170 
	float m_TimeToArmExplosion; //0x0174 
	float m_FirstFrameTravelDistance; //0x0178 
	unsigned char m_HasVehicleDetonation; //0x017C 
	unsigned char m_ShowTrailEffectOnUnspawn; //0x017D 
	unsigned char m_TrailEffectOnUnspawn2; //0x017E 
	unsigned char m_TrailEffectOnUnspawn3; //0x017F 
};//Size=0x0180

class WeaponSuppressionData
{
public:
	char _0x0000[16];
	float m_MinMultiplier; //0x0010 
	float m_MaxMultiplier; //0x0014 
	float m_MinDistance; //0x0018 
	float m_MaxDistance; //0x001C 
};//Size=0x0020

class WeaponSway
{
public:
	char _0x0000[8];
	GunSwayData* m_Data; //0x0008 
};//Size=0x0010

class GunSwayData
{
public:
	char _0x0000[880];
	float m_ShootingRecoilDecreaseScale; //0x0370 
	float m_FirstShotRecoilMultiplier; //0x0374 
	__int64 m_CameraRecoilData; //0x0378 
};//Size=0x0380

class SoldierAimingSimulation
{
public:
	char _0x0000[48];
	AimAssist* m_pFPSAimer; //0x0030 
	SM::Vector2 m_AimAngles; //0x0038 
	SM::Vector2 m_AimTimer; //0x0040 
	char _0x0048[8];
	float m_DeltaTime; //0x0050 
	SM::Vector2 m_Unk; //0x0054 
	SM::Vector2 m_DeltaAimAngles; //0x005C 
};//Size=0x0064

class ClientAimEntity
{
public:
	char _0x0000[448];
	SoldierAimingSimulation* m_pAimingSimulation; //0x01C0 
	char _0x01C8[632];
};//Size=0x0440

class AimAssist
{
public:
	char _0x0000[20];
	SM::Vector2 m_AimAngles; //0x0014 
	char _0x001C[40];
};//Size=0x0044

class QuatTransform
{
public:
	SM::Vector4 m_TransAndScale; //0x0000 
	SM::Vector4 m_Rotation; //0x0010 
};//Size=0x0020

class UpdatePoseResultData
{
public:
	enum BONES
	{
		Reference = 0,
		AITrajectory = 1,
		Trajectory = 2,
		TrajectoryEnd = 3,
		Hips = 4,
		Spine = 5,
		Spine1 = 6,
		Spine2 = 7,
		LeftShoulder = 8,
		LeftArm = 9,
		LeftArmRoll = 10,
		LeftArm_Phys_Base01 = 11,
		LeftArm_Phys_01 = 12,
		LeftElbowRoll = 13,
		LeftForeArm = 14,
		LeftForeArmRoll = 15,
		LeftForeArmRoll1 = 16,
		LeftHand = 17,
		LeftHandRing0 = 18,
		LeftHandRing1 = 19,
		LeftHandRing2 = 20,
		LeftHandRing3 = 21,
		LeftHandRing4 = 22,
		LeftHandPinky0 = 23,
		LeftHandPinky1 = 24,
		LeftHandPinky2 = 25,
		LeftHandPinky3 = 26,
		LeftHandPinky4 = 27,
		LeftHandIndex0 = 28,
		LeftHandIndex1 = 29,
		LeftHandIndex2 = 30,
		LeftHandIndex3 = 31,
		LeftHandIndex4 = 32,
		LeftHandThumb1 = 33,
		LeftHandThumb2 = 34,
		LeftHandThumb3 = 35,
		LeftHandThumb4 = 36,
		LeftHandMiddle0 = 37,
		LeftHandMiddle1 = 38,
		LeftHandMiddle2 = 39,
		LeftHandMiddle3 = 40,
		LeftHandMiddle4 = 41,
		LeftHand_Phys_Base01 = 42,
		LeftHand_Phys_01 = 43,
		LeftHandAttach = 44,
		LeftForeArmRoll2 = 45,
		LeftArmRoll1 = 46,
		LeftArmBend = 47,
		Neck = 48,
		Neck1 = 49,
		Head = 50,
		HeadEnd = 51,
		Face = 52,
		Jaw = 53,
		LeftLowerLip = 54,
		LeftLowerInnerLip = 55,
		LowerLip = 56,
		LowerInnerLip = 57,
		RightLowerLip = 58,
		RightLowerInnerLip = 59,
		Tongue = 60,
		TongueTip = 61,
		Chin = 62,
		LeftLowCheek = 63,
		RightLowCheek = 64,
		LeftEye = 65,
		LeftIris = 66,
		RightEye = 67,
		RightIris = 68,
		LeftUpCheek = 69,
		LeftUpInnerCheek = 70,
		RightUpInnerCheek = 71,
		RightUpCheek = 72,
		LeftCheek = 73,
		RightCheek = 74,
		LeftMouth = 75,
		LeftInnerMouth = 76,
		LeftMiddleCrease = 77,
		LeftUpperLip = 78,
		LeftUpperInnerLip = 79,
		UpperLip = 80,
		UpperInnerLip = 81,
		RightUpperLip = 82,
		RightUpperInnerLip = 83,
		RightMouth = 84,
		RightInnerMouth = 85,
		RightMiddleCrease = 86,
		LeftUpEyelid = 87,
		RightUpEyelid = 88,
		LeftLowEyelid = 89,
		RightLowEyelid = 90,
		LeftInnerEyebrow = 91,
		LeftOuterEyebrow = 92,
		RightInnerEyebrow = 93,
		RightOuterEyebrow = 94,
		LeftNose = 95,
		RightNose = 96,
		LeftCrease = 97,
		RightCrease = 98,
		LeftLowMiddleEyebrow = 99,
		RightMiddleEyebrow = 100,
		LeftLowEyelidCrease = 101,
		LeftLowOuterEyebrow = 102,
		NoseTip = 103,
		RightLowOuterEyebrow = 104,
		LeftMiddleEyebrow = 105,
		RightLowMiddleEyebrow = 106,
		RightLowEyelidCrease = 107,
		LowNose = 108,
		Head_Phys_Base01 = 109,
		Head_Phys_01 = 110,
		Hair_01_Base = 111,
		Hair_01_Extra01 = 112,
		Hair_01_Extra02 = 113,
		Hair_02_Base = 114,
		Hair_02_Extra01 = 115,
		Hair_02_Extra02 = 116,
		Hair_03_Base = 117,
		Hair_03_Extra01 = 118,
		Hair_03_Extra02 = 119,
		Hair_04_Base = 120,
		Hair_04_Extra01 = 121,
		Hair_04_Extra02 = 122,
		Hair_05_Base = 123,
		Hair_05_Extra01 = 124,
		Hair_05_Extra02 = 125,
		Hair_05_Extra03 = 126,
		Hair_06_Base = 127,
		Hair_06_Extra01 = 128,
		Hair_06_Extra02 = 129,
		Hair_06_Extra03 = 130,
		Hair_07_Base = 131,
		Hair_07_Extra01 = 132,
		Hair_07_Extra02 = 133,
		Hair_08_Base = 134,
		Hair_08_Extra01 = 135,
		Hair_08_Extra02 = 136,
		Hair_08_Extra03 = 137,
		Throat = 138,
		HeadRoll = 139,
		Wep2_Root = 140,
		Spine2_Phys = 141,
		Spine2_Phys_Ext_Base01 = 142,
		Spine2_Phys_Ext_01 = 143,
		Spine2_Phys_Ext_Base02 = 144,
		Spine2_Phys_Ext_02 = 145,
		Spine2_Phys_Ext_Base03 = 146,
		Spine2_Phys_Ext_03 = 147,
		Spine2_Phys_Ext_Base04 = 148,
		Spine2_Phys_Ext_04 = 149,
		Backpack_Phys_Base01 = 150,
		Backpack_Phys_01 = 151,
		Backpack_Phys_Ext_Base01 = 152,
		Backpack_Phys_Ext_01 = 153,
		Backpack_Phys_Ext_Base02 = 154,
		Backpack_Phys_Ext_02 = 155,
		Backpack_Phys_Ext_Base03 = 156,
		Backpack_Phys_Ext_03 = 157,
		Backpack_Phys_Ext_Base04 = 158,
		Backpack_Phys_Ext_04 = 159,
		Backpack_Phys_Weapon_Base01 = 160,
		Backpack_Phys_Weapon_01 = 161,
		LeftArmpit = 162,
		LeftDeltoidBulge = 163,
		NeckCollar = 164,
		RightShoulder = 165,
		RightArm = 166,
		RightArmRoll = 167,
		RightArm_Phys_Base01 = 168,
		RightArm_Phys_01 = 169,
		RightElbowRoll = 170,
		RightForeArm = 171,
		RightForeArmRoll = 172,
		RightForeArmRoll1 = 173,
		RightHand = 174,
		RightHandRing0 = 175,
		RightHandRing1 = 176,
		RightHandRing2 = 177,
		RightHandRing3 = 178,
		RightHandRing4 = 179,
		RightHandPinky0 = 180,
		RightHandPinky1 = 181,
		RightHandPinky2 = 182,
		RightHandPinky3 = 183,
		RightHandPinky4 = 184,
		RightHandIndex0 = 185,
		RightHandIndex1 = 186,
		RightHandIndex2 = 187,
		RightHandIndex3 = 188,
		RightHandIndex4 = 189,
		RightHandThumb1 = 190,
		RightHandThumb2 = 191,
		RightHandThumb3 = 192,
		RightHandThumb4 = 193,
		RightHandMiddle0 = 194,
		RightHandMiddle1 = 195,
		RightHandMiddle2 = 196,
		RightHandMiddle3 = 197,
		RightHandMiddle4 = 198,
		RightHand_Phys_Base01 = 199,
		RightHand_Phys_01 = 200,
		RightHandAttach = 201,
		RightForeArmRoll2 = 202,
		RightArmRoll1 = 203,
		RightArmBend = 204,
		RightArmpit = 205,
		RightDeltoidBulge = 206,
		Wep_Root = 207,
		Wep_Trigger = 208,
		Wep_Slide = 209,
		Wep_Grenade1 = 210,
		Wep_Grenade2 = 211,
		Wep_Mag = 212,
		Wep_Mag_Ammo = 213,
		Wep_Mag_Extra1 = 214,
		Wep_Scope1 = 215,
		Wep_Scope2 = 216,
		Wep_Belt1 = 217,
		Wep_Belt2 = 218,
		Wep_Belt3 = 219,
		Wep_Belt4 = 220,
		Wep_Belt5 = 221,
		Wep_Bipod1 = 222,
		Wep_Bipod2 = 223,
		Wep_Bipod3 = 224,
		IK_Joint_LeftHand = 225,
		IK_Joint_RightHand = 226,
		Wep_Physic1 = 227,
		Wep_Physic2 = 228,
		Wep_Physic3 = 229,
		Wep_Extra1 = 230,
		Wep_Extra2 = 231,
		Wep_Extra3 = 232,
		Wep_Extra4 = 233,
		Wep_Muzzle = 234,
		Wep_ButtStock = 235,
		Wep_Lag = 236,
		Wep_Aim = 237,
		Spine1_Phys = 238,
		Spine1_Phys_Ext_Base01 = 239,
		Spine1_Phys_Ext_01 = 240,
		Spine1_Phys_Ext_Base02 = 241,
		Spine1_Phys_Ext_02 = 242,
		Spine1_Phys_Ext_Base03 = 243,
		Spine1_Phys_Ext_03 = 244,
		Spine1_Phys_Ext_Base04 = 245,
		Spine1_Phys_Ext_04 = 246,
		Spine_Phys = 247,
		Spine_Phys_Ext_Base01 = 248,
		Spine_Phys_Ext_01 = 249,
		Spine_Phys_Ext_Base02 = 250,
		Spine_Phys_Ext_02 = 251,
		Spine_Phys_Ext_Base03 = 252,
		Spine_Phys_Ext_03 = 253,
		Spine_Phys_Ext_Base04 = 254,
		Spine_Phys_Ext_04 = 255,
		Spine_Phys_Weapon_Base01 = 256,
		Spine_Phys_Weapon_01 = 257,
		LeftUpLeg = 258,
		LeftLeg = 259,
		LeftFoot = 260,
		LeftToeBase = 261,
		LeftToe = 262,
		LeftLeg_Phys_Base01 = 263,
		LeftLeg_Phys_01 = 264,
		LeftKneeLow = 265,
		LeftUpLeg_Phys_Base01 = 266,
		LeftUpLeg_Phys_01 = 267,
		LeftKneeUp = 268,
		LeftUpLegRoll = 269,
		LeftKneeRoll = 270,
		Hips_Phys = 271,
		Hips_Phys_Ext_Base01 = 272,
		Hips_Phys_Ext_01 = 273,
		Hips_Phys_Ext_Base02 = 274,
		Hips_Phys_Ext_02 = 275,
		Hips_Phys_Ext_Base03 = 276,
		Hips_Phys_Ext_03 = 277,
		Hips_Phys_Ext_Base04 = 278,
		Hips_Phys_Ext_04 = 279,
		Hips_Phys_Ext_Base05 = 280,
		Hips_Phys_Ext_05 = 281,
		Hips_Phys_Ext_Base06 = 282,
		Hips_Phys_Ext_06 = 283,
		LeftHipsRoll = 284,
		RightUpLeg = 285,
		RightLeg = 286,
		RightFoot = 287,
		RightToeBase = 288,
		RightToe = 289,
		RightLeg_Phys_Base01 = 290,
		RightLeg_Phys_01 = 291,
		RightKneeLow = 292,
		RightUpLeg_Phys_Base01 = 293,
		RightUpLeg_Phys_01 = 294,
		RightKneeUp = 295,
		RightUpLegRoll = 296,
		RightKneeRoll = 297,
		RightHipsRoll = 298,
		CameraBase = 299,
		CameraJoint = 300,
		Connect = 301,
		ConnectEnd = 302,
		Ground = 303
	};
	QuatTransform* m_LocalTransforms; //0x0000 
	QuatTransform* m_WorldTransforms; //0x0008 
	QuatTransform* m_Unk; //0x0010 
	QuatTransform* m_Unk1; //0x0018 
	QuatTransform* m_Unk2; //0x0020 
	QuatTransform* m_ActiveWorldTransforms; //0x0028 
	QuatTransform* m_ActiveLocalTransforms; //0x0030 
	__int32 m_Slot; //0x0038 
	__int32 m_ReaderIndex; //0x003C 
	unsigned char m_ValidTransforms; //0x0040 
	unsigned char m_PoseUpdateNeeded; //0x0041 
	unsigned char m_PoseNeeded; //0x0042 
};//Size=0x0043

class SkeletonAsset
{
public:
	char _0x0000[24];
	char** m_ppBoneNames; //0x0018 
};//Size=0x0020

class AnimationSkeleton
{
public:
	SkeletonAsset* m_SkeletonAsset; //0x0000 
	__int32 m_BoneCount; //0x0008 
	char* GetBoneNameAt(int i)
	{
		if (i <= m_BoneCount)
			return m_SkeletonAsset->m_ppBoneNames[i];
		return "";
	}
};//Size=0x000C

class ClientRagdollComponent
{
public:
	char _0x0000[16];
	__int64 m_Data; //0x0010 
	char _0x0018[8];
	__int64 m_pEntry; //0x0020 
	char _0x0028[40];
	AnimationSkeleton* m_AnimationSkeleton; //0x0050 
	char _0x0058[32];
	UpdatePoseResultData m_PoseResultData; //0x0078 
	char _0x00BB[168];

	bool GetBone(const UpdatePoseResultData::BONES BoneId, SM::Vector3& BoneOut)
	{
		UpdatePoseResultData PoseResult = this->m_PoseResultData;
		if (PoseResult.m_ValidTransforms)
		{
			QuatTransform* pQuat = PoseResult.m_ActiveWorldTransforms;
			if (!PLH::IsValidPtr(pQuat))
				return false;

			SM::Vector4 Bone = pQuat[BoneId].m_TransAndScale;
			BoneOut = SM::Vector3(Bone.x, Bone.y, Bone.z);
			return true;
		}
		return false;
	}
	bool GetBone(const char* BoneName, SM::Vector3& BoneOut)
	{
		int BoneId = -1;

		AnimationSkeleton* pSkeleton = m_AnimationSkeleton;
		if (!PLH::IsValidPtr(pSkeleton))
			return false;

		for (int i = 0; i < pSkeleton->m_BoneCount; i++)
		{
			char* name = pSkeleton->GetBoneNameAt(i);
			if (_stricmp(name, BoneName) == 0)
				BoneId = i;
		}

		if (BoneId == -1)
			return false;

		UpdatePoseResultData PoseResult = this->m_PoseResultData;
		if (PoseResult.m_ValidTransforms)
		{
			QuatTransform* pQuat = PoseResult.m_ActiveWorldTransforms;
			if (!PLH::IsValidPtr(pQuat))
				return false;

			SM::Vector4 Bone = pQuat[BoneId].m_TransAndScale;
			BoneOut = SM::Vector3(Bone.x, Bone.y, Bone.z);
			return true;
		}
		return false;
	}
};//Size=0x0163


class ClientVehicleEntity
{
public:
	char _0x0000[96];
	ClientVehiclePhysicsComponent* m_PhysicsComponent; //0x0060 
	char _0x0068[304];
	ClientVehicleHealthComponent* m_HealthComponent; //0x0198 
	char _0x01A0[672];
};//Size=0x0440

class ClientVehicleHealthComponent
{
public:
	char _0x0000[32];
	float m_Health; //0x0020 
	float m_MaxHealth; //0x0024 
};//Size=0x0028

class ClientVehiclePhysicsComponent
{
public:
	char _0x0000[192];
};//Size=0x00C0

class Screen
{
public:
	char _0x0000[584];
	__int32 m_Width; //0x0248 
	__int32 m_Height; //0x024C 
	__int32 m_WindowWidth; //0x0250 
	__int32 m_WindowHeight; //0x0254 
	char _0x0258[32];
	IDXGISwapChain* m_pSwapChain; //0x0278 
};//Size=0x0580

class DX11Renderer
{
public:
	char _0x0000[2016];
	Screen* m_pScreen; //0x07E0 
	char _0x07E8[112];
	ID3D11Device* m_pDevice; //0x0858 
	char _0x0860[32];
	static DX11Renderer* GetInstance()
	{
		return *(DX11Renderer**)OFFSET_DX11RENDERER;
	}
};//Size=0x0880

class RenderView
{
public:
	char _0x0000[672];
	SM::Matrix m_View; //0x02A0 
	SM::Matrix m_ViewTranspose; //0x02E0 
	SM::Matrix m_ViewInverse; //0x0320 
	SM::Matrix m_Projection; //0x0360 
	SM::Matrix m_ViewAtOrigin; //0x03A0 
	SM::Matrix m_ProjectionTranspose; //0x03E0 
	SM::Matrix m_ProjectionInverse; //0x0420 
	SM::Matrix m_ViewProjection; //0x0460 
	SM::Matrix m_ViewProjectionTranspose; //0x04A0 
	SM::Matrix m_ViewProjectionInverse; //0x04E0 
};//Size=0x0520

class GameRenderer
{
public:
	char _0x0000[64];
	__int64 m_GameRenderSettings; //0x0040 
	char _0x0048[16];
	RenderView* m_RenderView; //0x0058 
	static GameRenderer* GetInstance()
	{
		return *(GameRenderer**)OFFSET_GAMERENDERER;
	}
};//Size=0x0060

template <class T> class EntityIterator
{
public:
	class Element
	{
	public:

		Element* m_pFlink;
		Element* m_pBlink;
		__int32  m_Unk1;
		__int32  m_Unk2;

		T* getObject()
		{
			intptr_t pObject = reinterpret_cast<intptr_t>(this);
			pObject -= 0x40;

			return reinterpret_cast<T*>(pObject);
		}
	};

	Element* m_pFirst;
	Element* m_pCurrent;

	EntityIterator(void* pGameWorld, void* pClassInfo)
	{
		typedef Element* (__thiscall* tGetEntityList)(void* pClassInfo, void* pThis);
		tGetEntityList lpGetEntityList = reinterpret_cast<tGetEntityList>(OFFSET_GETENTITYLIST);

		this->m_pFirst = lpGetEntityList(pClassInfo, pGameWorld);
		this->m_pCurrent = this->m_pFirst;
	}

	bool hasNext()
	{
		if (m_pCurrent && m_pCurrent->m_pFlink)
			return true;

		return false;
	}

	Element* first() { return m_pFirst; }
	Element* front() { return m_pCurrent; }
	Element* next()
	{
		if (!m_pFirst)
			return nullptr;

		m_pCurrent = m_pCurrent->m_pFlink;
		return m_pCurrent;
	}
};







