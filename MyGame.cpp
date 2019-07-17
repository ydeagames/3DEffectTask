#include "pch.h"
#include "MyGame.h"
#include "GameCamera.h"
#include "GameContext.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;

void MyGame::Initialize(GameContext& context)
{
	// �f�o�b�O�J�����쐬
	m_pDebugCamera = std::make_unique<DebugCamera>();
	// �O���b�h���쐬
	m_pGridFloor = std::make_unique<GridFloor>(context.GetDR().GetD3DDevice(), context.GetDR().GetD3DDeviceContext(), &context.GetStates(), 10.0f, 10);
}

void MyGame::Update(GameContext& context)
{
	// �f�o�b�O�J�����X�V
	m_pDebugCamera->update();
	context.GetCamera().view = m_pDebugCamera->getViewMatrix();
}

void MyGame::Render(GameContext& context)
{
	// �O���b�h���`��
	m_pGridFloor->draw(context.GetDR().GetD3DDeviceContext(), context.GetCamera().view, context.GetCamera().projection);
}

void MyGame::Finalize(GameContext& context)
{

}
