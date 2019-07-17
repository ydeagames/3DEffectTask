#pragma once
#include "DebugCamera.h"
#include "GridFloor.h"

class GameContext;

class MyGame
{
	// デバッグカメラ
	std::unique_ptr<DebugCamera>			m_pDebugCamera;
	// グリッド床
	std::unique_ptr<GridFloor>				m_pGridFloor;

public:
	// 生成
	void Initialize(GameContext& context);
	// 更新
	void Update(GameContext& context);
	// 描画
	void Render(GameContext& context);
	// 破棄
	void Finalize(GameContext& context);
};

