#pragma once
#include "DebugCamera.h"
#include "GridFloor.h"

class GameContext;

class MyGame
{
	// �f�o�b�O�J����
	std::unique_ptr<DebugCamera>			m_pDebugCamera;
	// �O���b�h��
	std::unique_ptr<GridFloor>				m_pGridFloor;

public:
	// ����
	void Initialize(GameContext& context);
	// �X�V
	void Update(GameContext& context);
	// �`��
	void Render(GameContext& context);
	// �j��
	void Finalize(GameContext& context);
};

