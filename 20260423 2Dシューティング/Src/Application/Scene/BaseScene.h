#pragma once

// シーンの基底クラス（親クラス）
class BaseScene
{
public:
	BaseScene() {}
	~BaseScene() {}

	// virtual = 仮想関数。継承先で上書きを前提とした前提

	virtual void Init() {}
	virtual void Update() {}
	virtual void DrawSprite() {}
	virtual void Draw() {}
	virtual void Release() {}

private:

};

