#include "main.h"
#include "Scene.h"
#include "Player.h"
#include"Enemy/Enemy.h"
#include"Bullet/Bullet.h"

void Scene::Draw2D()
{
	m_player->Draw();
	m_enemy->Draw();
}

void Scene::Update()
{

}

void Scene::Init()
{
	m_player->Init();
	m_playerTex.Load("Texture/Player/Player.png");
	m_player->SetTex(&m_playerTex);	

	m_enemy->Init();
	m_enemyTex.Load("Texture/Player/Player.png");
	m_enemy->SetTex(&m_enemyTex);	
}

void Scene::Release()
{
	m_playerTex.Release();
}

void Scene::ImGuiUpdate()
{
	return;

	ImGui::SetNextWindowPos(ImVec2(20, 20), ImGuiSetCond_Once);
	ImGui::SetNextWindowSize(ImVec2(200, 100), ImGuiSetCond_Once);

	// デバッグウィンドウ
	if (ImGui::Begin("Debug Window"))
	{
		ImGui::Text("FPS : %d", APP.m_fps);
	}
	ImGui::End();
}

Scene::Scene()
{
	m_player = new Player();
	m_enemy = new Enemy();
	m_bullet = new Bullet();
}
