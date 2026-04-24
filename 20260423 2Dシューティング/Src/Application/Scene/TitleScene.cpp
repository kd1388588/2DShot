//  TitleScene.cpp
#include"TitleScene.h"
#include"../Manager/SceneManager.h"


void TitleScene::Init()
{
	m_backTex.Load("Texture/Scene/title.png");

	alpha = 1.0f;
}

void TitleScene::Update()
{
	alpha += m_alphaSpd;
	if (alpha > 1.0f)
	{
		alpha = 1.0f;
		m_alphaSpd *= -1.0f;
	}

	else if (alpha < 0.3f)
	{
		alpha = 0.3f;
		m_alphaSpd *= -1.0f;
	}

	if (GetAsyncKeyState(VK_RETURN) & 0x8000)
	{
		SceneManager::Instance().SetNextScene(SceneManager::SceneType::Game);
	}
}

void TitleScene::Draw()
{
	SHADER.m_spriteShader.DrawTex(&m_backTex, 0, 0);

	Math::Color color = { 1.0f, 1.0f, 1.0f, alpha };
	SHADER.m_spriteShader.DrawTex(&m_startTex, 0, 0, nullptr, &color);
}
