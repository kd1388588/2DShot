// Player.cpp

#include "Player.h"

void Player::Init()
{
	m_pos = { 0,-200 };
	m_move = { 0,0 };
	m_rect = { 0,0,64,64 };
	m_radiusX = 32.0f;
	m_radiusY = 32.0f;
	m_scaleX = 1.0f;
	m_scaleY = 1.0f;
	m_rotate = 0.0f;
	m_alpha = 1.0f;
	m_fadeStep = 0.03f;
	m_isActive = true;
}

void Player::Update()
{
	if (m_pos.x > 640 - 32)		m_pos.x = 640 - 32;
	if (m_pos.x < -640 + 32)	m_pos.x = -640 + 32;
	if (m_pos.y > 360 - 32)		m_pos.y = 360 - 32;
	if (m_pos.y < -360 + 32)	m_pos.y = -360 + 32;

	m_transMat = Math::Matrix::CreateTranslation(m_pos.x, m_pos.y, 0);
	m_scaleMat = Math::Matrix::CreateScale(m_scaleX, m_scaleY, 1.0f);

	m_mat = m_scaleMat * m_transMat;
}

void Player::Draw()
{
	SHADER.m_spriteShader.SetMatrix(m_mat);
	SHADER.m_spriteShader.DrawTex(m_tex, m_rect, m_alpha);
}

void Player::Action()
{
	m_pos = m_move;

	if (GetAsyncKeyState('A') & 0x8000) m_move.x -= 10;
	if (GetAsyncKeyState('D') & 0x8000) m_move.x += 10;
	if (GetAsyncKeyState('W') & 0x8000) m_move.y += 10;
	if (GetAsyncKeyState('S') & 0x8000) m_move.y -= 10;

	if (GetAsyncKeyState(VK_SPACE) & 0x8000) m_isShot = true;
}
