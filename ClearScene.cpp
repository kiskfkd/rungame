#include "ClearScene.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"
#include "Engine/Image.h"
#include "Engine/Text.h"

ClearScene::ClearScene(GameObject* parent)
	:GameObject(parent, "ClearScene"), hPict_(-1)
{
}

ClearScene::~ClearScene()
{
}

void ClearScene::Initialize()
{
	pText = new Text;
	pText->Initialize();
}

void ClearScene::Update()
{
	if (Input::IsKeyDown(DIK_SPACE))
	{
		SceneManager* pSceneManager
			= (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_TITLE);
	}
}

void ClearScene::Draw()
{
	pText->Draw(600, 250, "GAMEOVER");
	pText->Draw(550, 600, "PUSH TO SPACE");

	Image::SetTransform(hPict_, transform_);
	Image::Draw(hPict_);
}

void ClearScene::Release()
{
}