#pragma once

struct ESPSettings
{
	Color m_EnemyNotVisible;
	Color m_EnemyVisible;
	Color m_FriendlyNotVisible;
	Color m_FriendlyVisible;
	Color m_BulletsColor;
	Color m_VehiclesColor;

	bool m_Enabled;
	bool m_ShowFriendlies;
	bool m_SnapLinesEnabled;
	bool m_SkeletonEnabled;

	ESPSettings()
	{
		m_EnemyNotVisible = Color::Red();
		m_EnemyVisible = Color::Green();
		m_FriendlyNotVisible = Color(.88f, .21f, 1.f); //purple
		m_FriendlyVisible = Color::Blue();
		m_BulletsColor = Color::Black();
		m_VehiclesColor = Color::White();

		m_Enabled = true;
		m_ShowFriendlies = false;
		m_SnapLinesEnabled = true;
		m_SkeletonEnabled = true;
	}
};
struct AimbotSettings
{
	bool m_Enabled;
	UpdatePoseResultData::BONES m_AimBone;
	float m_MinTimeToTarget;
	float m_MaxTimeToTarget;

	AimbotSettings()
	{
		m_Enabled = true;
		m_AimBone = UpdatePoseResultData::BONES::Head;
		m_MinTimeToTarget = .7f;
		m_MaxTimeToTarget = 1.2f;
	}
};
struct ClassInfos
{
	ClassInfo* m_Bullets;
	ClassInfo* m_Vehicles;
	ClassInfo* m_Missiles;
};

#include "Hack Core/BotPlayerManager.h"
class Core
{
public:
	Core();
	void UpdatePresent();
	void ESP(RenderInterface* Renderer);
	void EntityESP(RenderInterface* Renderer);
	ESPSettings& GetESPSettings()
	{
		return m_ESPSettings;
	}
	AimbotSettings& GetAimbotSettings()
	{
		return m_AimbotSettings;
	}
private:
	void DumpBoneIDs();
	ClassInfo* FindClassInfo(const char* ClassName)
	{
		TypeInfo* CurrentTypeInfo = TypeInfo::GetFirst();
		if (!PLH::IsValidPtr(CurrentTypeInfo))
			return nullptr;
		do
		{
			if (_stricmp(CurrentTypeInfo->m_InfoData->m_Name, ClassName) != 0)
				continue;

			if (CurrentTypeInfo->GetTypeCode() != BasicTypesEnum::kTypeCode_Class)
				continue;

			return (ClassInfo*)CurrentTypeInfo;
		} while ((CurrentTypeInfo = CurrentTypeInfo->m_Next) != nullptr);
		return nullptr;
	}

	ClassInfos m_ClassInfos;
	ESPSettings m_ESPSettings;
	AimbotSettings m_AimbotSettings;
	BotPlayerManager m_PresentPlayerManager;
};

Core::Core()
{
	m_ClassInfos.m_Bullets = FindClassInfo("WSClientBulletEntity");
	m_ClassInfos.m_Vehicles = FindClassInfo("ClientVehicleEntity");
	m_ClassInfos.m_Missiles = FindClassInfo("WSClientMissileEntity");
}

void Core::DumpBoneIDs()
{
	Main* pMain = Main::GetInstance();
	if (!PLH::IsValidPtr(pMain))
		return;

	Client* pClient = pMain->m_Client;
	if (!PLH::IsValidPtr(pClient))
		return;

	PlayerManager* pPlayerMngr = pClient->m_PlayerManager;
	if (!PLH::IsValidPtr(pPlayerMngr))
		return;

	ClientPlayer* pLocalPlayer = pPlayerMngr->m_pLocalPlayer;
	if (!PLH::IsValidPtr(pLocalPlayer))
		return;

	ClientSoldierEntity* pSoldier = pLocalPlayer->GetSoldierEntity();
	if (!PLH::IsValidPtr(pSoldier))
		return;

	ClientRagdollComponent* pRagDoll = pSoldier->m_RagdollComponent;
	XTrace("rag %I64X\n", pRagDoll);

	AnimationSkeleton* pSkeleton = pRagDoll->m_AnimationSkeleton;
	if (!PLH::IsValidPtr(pSkeleton))
		return;
	XTrace("skel %I64X\n", pSkeleton);

	for (int i = 0; i < pSkeleton->m_BoneCount; i++)
	{
		char* name = pSkeleton->GetBoneNameAt(i);
		XTrace("%s = %d,\n", name, i);
	}
}

void Core::UpdatePresent()
{
	m_PresentPlayerManager.UpdatePlayers();
}

void Core::ESP(RenderInterface* Renderer)
{
	if (!m_ESPSettings.m_Enabled)
		return;

	ClientPlayer* pLocalPlayer = m_PresentPlayerManager.GetLocalPlayer();
	if (!PLH::IsValidPtr(pLocalPlayer))
		return;

	for (ClientPlayer* pEnemyPlayer : m_PresentPlayerManager.GetPlayerList())
	{
		if(!PLH::IsValidPtr(pEnemyPlayer))
			continue;

		ClientSoldierEntity* pEnemySoldier = pEnemyPlayer->GetSoldierEntity();
		if(!PLH::IsValidPtr(pEnemySoldier))
			continue;

		bool IsFriendly = pEnemyPlayer->m_TeamId == pLocalPlayer->m_TeamId;
		if(!m_ESPSettings.m_ShowFriendlies && IsFriendly)
			continue;

		Color ESPColor;
		if (IsFriendly)
		{
			ESPColor = pEnemySoldier->m_Occluded ?
				m_ESPSettings.m_FriendlyNotVisible : m_ESPSettings.m_FriendlyVisible;
		}
		else {
			ESPColor = pEnemySoldier->m_Occluded ?
				m_ESPSettings.m_EnemyNotVisible : m_ESPSettings.m_EnemyVisible;
		}

		if (m_ESPSettings.m_SnapLinesEnabled)
		{
			SM::Vector2 ScreenSz = GetScreenSize();
			if (ScreenSz.x < 1.0f || ScreenSz.y < 1.0f)
				continue;

			float StartX = ScreenSz.x * .5f;
			float StartY = ScreenSz.y - (ScreenSz.y *.05f);

			SM::Matrix Mat;
			pEnemySoldier->GetTransform(&Mat);
			SM::Vector3 Trans = SM::Vector3(Mat._41, Mat._42, Mat._43);
			if (!WorldToScreen(Trans))
				continue;

			Renderer->BeginLine();
			Renderer->DrawLine(Vector2f(StartX, StartY), Vector2f(Trans.x, Trans.y), ESPColor);
			Renderer->EndLine();
		}

		if (m_ESPSettings.m_SkeletonEnabled)
		{
			ClientRagdollComponent* pEnemyRag = pEnemySoldier->m_RagdollComponent;
			if (!PLH::IsValidPtr(pEnemyRag))
				continue;

			Renderer->BeginLine();
			ConnectBones(Renderer, ESPColor, pEnemyRag, "Head", "Neck");
			ConnectBones(Renderer, ESPColor, pEnemyRag, "Neck", "Spine2");
			ConnectBones(Renderer, ESPColor, pEnemyRag, "Spine2", "Spine1");
			ConnectBones(Renderer, ESPColor, pEnemyRag, "Spine1", "Spine");
			ConnectBones(Renderer, ESPColor, pEnemyRag, "Neck", "LeftShoulder");
			ConnectBones(Renderer, ESPColor, pEnemyRag, "LeftShoulder", "LeftElbowRoll");
			ConnectBones(Renderer, ESPColor, pEnemyRag, "RightShoulder", "RightElbowRoll");
			ConnectBones(Renderer, ESPColor, pEnemyRag, "LeftElbowRoll", "LeftHand");
			ConnectBones(Renderer, ESPColor, pEnemyRag, "RightElbowRoll", "RightHand");
			ConnectBones(Renderer, ESPColor, pEnemyRag, "Spine", "RightKneeRoll");
			ConnectBones(Renderer, ESPColor, pEnemyRag, "Spine", "LeftKneeRoll");
			ConnectBones(Renderer, ESPColor, pEnemyRag, "RightKneeRoll", "RightFoot");
			ConnectBones(Renderer, ESPColor, pEnemyRag, "LeftKneeRoll", "LeftFoot");
			Renderer->EndLine();
		}
		TransformDrawAABB(pEnemySoldier, Renderer, ESPColor);
	}
}

void Core::EntityESP(RenderInterface* Renderer)
{
	Main* pMain = Main::GetInstance();
	if (!PLH::IsValidPtr(pMain))
		return;

	EntityIterator<ClientControllableEntity> Bullets((void*)pMain->m_Client->m_GameContext->m_pLevel->m_pGameWorld, m_ClassInfos.m_Bullets);
	if (Bullets.front())
	{
		do
		{
			ClientControllableEntity* pEnt = Bullets.front()->getObject();
			if (!PLH::IsValidPtr(pEnt))
				continue;

			TransformDrawAABB(pEnt, Renderer, m_ESPSettings.m_BulletsColor);
		} while (Bullets.next());
	}

	EntityIterator<ClientControllableEntity> Vehicles((void*)pMain->m_Client->m_GameContext->m_pLevel->m_pGameWorld, m_ClassInfos.m_Vehicles);
	if (Vehicles.front())
	{
		do
		{
			ClientControllableEntity* pEnt = Vehicles.front()->getObject();
			if (!PLH::IsValidPtr(pEnt))
				continue;

			TransformDrawAABB(pEnt, Renderer, m_ESPSettings.m_VehiclesColor);
		} while (Vehicles.next());
	}

	EntityIterator<ClientControllableEntity> Missiles((void*)pMain->m_Client->m_GameContext->m_pLevel->m_pGameWorld, m_ClassInfos.m_Missiles);
	if (Missiles.front())
	{
		do
		{
			ClientControllableEntity* pEnt = Missiles.front()->getObject();
			if(!PLH::IsValidPtr(pEnt))
				continue;

			TransformDrawAABB(pEnt, Renderer, m_ESPSettings.m_BulletsColor);
		} while (Missiles.next());
	}
}