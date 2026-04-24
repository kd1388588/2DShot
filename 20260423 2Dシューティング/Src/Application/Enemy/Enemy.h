#pragma once

class Enemy
{
public:
	Enemy() {}
	~Enemy() {}

	void Init();
	void Update();
	void Draw();

	void Action();

	void SetTex(KdTexture* a_tex) { m_tex = a_tex; }

private:

	Math::Vector2 m_pos;        //座標
	Math::Vector2 m_move;        //移動量
	Math::Matrix m_transMat;    //移動行列
	Math::Matrix m_scaleMat;    //拡縮行列
	Math::Matrix m_rotateMat;    //回転行列
	Math::Matrix m_mat;            //合成行列
	Math::Rectangle m_rect;        //画像範囲指定

	KdTexture* m_tex;            //画像用

	float m_radiusX;            //X軸方向の半径
	float m_radiusY;            //Y軸方向の半径
	float m_scaleX;                //X軸方向の拡縮
	float m_scaleY;                //Y軸方向の拡縮
	float m_rotate;                //回転角度
	float m_alpha;                //不透明度
	float m_fadeStep;            //フェード用
	bool m_isActive;            //true 表示　false 非表示

	bool m_isAlive;                //生きているかどうか


	bool m_isShot;                //弾を撃ったかどうか
};