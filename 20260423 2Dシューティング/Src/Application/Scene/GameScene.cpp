// GameScene.cpp
#include "GameScene.h"

// ゲーム内使用クラス
#include "../Player.h"
#include "../Bullet/Bullet.h"
#include "../Enemy/Enemy.h"
//#include "../../Effect/Effect.h"

// マネージャー
#include "../Manager/SceneManager.h"

void GameScene::Init()
{

}

void GameScene::Update()
{
	m_player->Action();
	m_player->Update();

	m_enemy->Update();

	if (GetAsyncKeyState('Z') & 0x8000)
	{
		SceneManager::Instance().SetNextScene(SceneManager::SceneType::Title);
	}

}

void GameScene::Draw()
{
	m_color = { 1,1,1,1 };
}

void GameScene::Release()
{

}
