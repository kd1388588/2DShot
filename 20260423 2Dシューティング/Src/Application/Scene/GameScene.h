#pragma once

class Player;
class Enemy;
class Bullet;

// 継承の場合のみヘッダー内インクルード許可！
#include "BaseScene.h"

class GameScene : public BaseScene
{
public:
	GameScene() { Init(); }
	~GameScene() {}

	Player* m_player = nullptr;
	Bullet* m_bullet = nullptr;
	Enemy* m_enemy = nullptr;

	void Init() override;
	void Update() override;
	void Draw() override;
	void Release() override;

private:

	Math::Color m_color;
	float alpha;
	float m_alphaSpd = -0.01f;

	KdTexture m_backTex;
	KdTexture m_startTex;
};

