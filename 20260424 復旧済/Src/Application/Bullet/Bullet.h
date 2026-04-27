// Bullet.h
#pragma once

class Player; // 前方宣言

class Bullet
{
public:
	Bullet() : m_tex(nullptr), m_player(nullptr), m_isActive(false) {}
	~Bullet() {}

	void Init();
	void Update();
	void Draw();

	// プレイヤーとテクスチャをセットする
	void SetTarget(Player* a_player) { m_player = a_player; }
	void SetTex(KdTexture* a_tex) { m_tex = a_tex; }

private:
	Player* m_player;	// プレイヤーへの参照
	KdTexture* m_tex;		// 画像
	Math::Vector2	m_pos;		// 座標
	Math::Matrix	m_mat;		// 行列
	Math::Rectangle m_rect;		// 描画範囲
	bool			m_isActive;	// 生存フラグ
};