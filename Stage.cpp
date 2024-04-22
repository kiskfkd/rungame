#include "Stage.h"
#include"Engine/Image.h"
Stage::Stage(GameObject* parent)
	:GameObject(parent, "PlayScene"),  hTitle_(-1)
{
}

void Stage::Initialize()
{
	hTitle_ = Image::Load("utyuu.png");
	assert(hTitle_ >= 0);
}

void Stage::Update()
{

}

void Stage::Draw()
{
	Image::SetTransform(hTitle_, transform_);
	Image::Draw(hTitle_);
}

void Stage::Release()
{
}
