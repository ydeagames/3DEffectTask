#include "pch.h"
#include "MyGame.h"
#include "GameCamera.h"
#include "GameContext.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;

void MyGame::Initialize(GameContext& context)
{
	// デバッグカメラ作成
	m_pDebugCamera = std::make_unique<DebugCamera>();
	// グリッド床作成
	m_pGridFloor = std::make_unique<GridFloor>(context.GetDR().GetD3DDevice(), context.GetDR().GetD3DDeviceContext(), &context.GetStates(), 10.0f, 10);
}

void MyGame::Update(GameContext& context)
{
	// デバッグカメラ更新
	m_pDebugCamera->update();
	context.GetCamera().view = m_pDebugCamera->getViewMatrix();
}

void MyGame::Render(GameContext& context)
{
	// グリッド床描画
	m_pGridFloor->draw(context.GetDR().GetD3DDeviceContext(), context.GetCamera().view, context.GetCamera().projection);
}

void MyGame::Finalize(GameContext& context)
{

}
