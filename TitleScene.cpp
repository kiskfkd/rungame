#include "TitleScene.h"
#include "Engine/Text.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"
#include "Engine/Image.h"
TitleScene::TitleScene(GameObject* parent)
	:GameObject(parent, "TitleScene"), pText(nullptr),hPict_(-1)
{
}

void TitleScene::Initialize()
{
	pText = new Text;
	pText->Initialize();
}

void TitleScene::Update()
{
	if (Input::IsKeyDown(DIK_SPACE))
	{
		SceneManager* pSM = (SceneManager*)FindObject("SceneManager");
		pSM->ChangeScene(SCENE_ID_PLAY);
	}
}

void TitleScene::Draw()
{
	pText->Draw(600, 250, "TITLE");
	pText->Draw(550, 600, "PUSH TO SPACE");

	Image::SetTransform(hPict_, transform_);
	Image::Draw(hPict_);
}

void TitleScene::Release()
{
}