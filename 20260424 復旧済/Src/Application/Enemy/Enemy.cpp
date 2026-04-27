// Enemy.cpp
#include "Enemy.h"

void Enemy::Init()
{
	m_pos = { 0,250 };
	m_move = { 0,0 };
	m_rect = { 0,0,64,64 };
	m_radiusX = 32.0f;
	m_radiusY = 32.0f;
	m_scaleX = 0.5f;
	m_scaleY = 0.5f;
	m_rotate = 0.0f;
	m_alpha = 1.0f;
	m_fadeStep = 0.03f;
	m_isActive = true;
}

void Enemy::Update()
{
	m_pos = m_move;

	m_move.y += -3.0f;

	m_transMat = Math::Matrix::CreateTranslation(m_pos.x, m_pos.y, 0);
	m_scaleMat = Math::Matrix::CreateScale(m_scaleX, m_scaleY, 1.0f);

	m_mat = m_scaleMat * m_transMat;
}

void Enemy::Draw()
{
	SHADER.m_spriteShader.SetMatrix(m_mat);
	SHADER.m_spriteShader.DrawTex(m_tex, m_rect, m_alpha);
}
