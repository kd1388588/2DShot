#pragma once

// 継承の場合のみヘッダー内インクルード許可！
#include "BaseScene.h"

class TitleScene : public BaseScene
{
public:
	TitleScene() { Init(); }
	~TitleScene() {}

	void Init() override;
	void Update() override;
	void Draw() override;
	void Release() override {}

private:

	float alpha;
	float m_alphaSpd = -0.01f;

	KdTexture m_backTex;
	KdTexture m_startTex;
};
