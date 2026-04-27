// Scene.cpp
#include "main.h"
#include "Scene.h"
#include "Player.h"
#include "Enemy/Enemy.h"
//#include "Bullet/Bullet.h" // コメントアウトを解除

void Scene::Init()
{
	// プレイヤー初期化
	m_player->Init();
	m_playerTex.Load("Texture/Bubble/Player.png");
	m_player->SetTex(&m_playerTex);

	// 弾の初期設定
	//m_bullet->Init();
	//m_bullet->SetTex(&m_playerTex); // Playerのテクスチャを流用

	m_enemy->Init();
	m_enemyTex.Load("Texture/Bubble/Enemy.png");
	m_enemy->SetTex(&m_enemyTex);
}

void Scene::Update()
{
	m_player->Update();
	m_player->Action();

	// 弾自身のUpdateで発射ロジックが動く
	//m_bullet->Update();

	m_enemy->Update();
}

void Scene::Draw2D()
{
	//m_bullet->Draw(); // 弾を描画
	m_enemy->Draw();
	m_player->Draw();
}

void Scene::Release()
{
	if (m_player) delete m_player;
	if (m_enemy) delete m_enemy;
	//if (m_bullet) delete m_bullet;
}