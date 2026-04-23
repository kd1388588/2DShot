#include "main.h"
#include "Scene.h"
#include "Player.h"

void Scene::Draw2D()
{
	m_player->Draw();
}

void Scene::Update()
{
	m_player->Action();
	m_player->Update();
}

void Scene::Init()
{
	m_player->Init();
	m_playerTex.Load("Texture/Player/Player.png");
	m_player->SetTex(&m_playerTex);	
}

void Scene::Release()
{
	
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
}
