// Scene.h
#pragma once

class Player;
class Enemy;


class Scene
{
private:

	Player* m_player = nullptr;
	Enemy* m_enemy = nullptr;
	

	// テクスチャ ・・・ 画像データ
	KdTexture m_playerTex;
	KdTexture m_enemyTex;


	// 行列 ・・・ 座標などの情報
	Math::Matrix matrix;

public:

	// 初期設定
	void Init();

	// 解放
	void Release();

	// 更新処理
	void Update();

	// 描画処理
	void Draw2D();

	// GUI処理
	void ImGuiUpdate();

private:

	Scene();

public:
	static Scene& GetInstance()
	{
		static Scene instance;
		return instance;
	}
};

#define SCENE Scene::GetInstance()
