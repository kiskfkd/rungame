#include "Player.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Engine/Debug.h"
#include "Engine/Image.h"
#include "Engine/SceneManager.h"
//#include "Stage.h"
//#include "Gauge.h"

Player::Player(GameObject* parent)
	:GameObject(parent, "Player"), hModel_(-1)
{
}

Player::~Player()
{
	//後片付け
}

void Player::Initialize()
{
	//モデルデータのロード
	hModel_ = Model::Load("box.fbx");
	assert(hModel_ >= 0);
	transform_.position_ = { 0,0,0 };
}

void Player::Update()
{
	//左右移動
	if (Input::IsKeyDown(DIK_LEFT))
	{
		if (transform_.position_.x >-2.0f) 
			transform_.position_.x -= 2.0f;
	}
	if (Input::IsKeyDown(DIK_RIGHT))
	{
		if(transform_.position_.x <2.0f)
			transform_.position_.x += 2.0f;
		}
}

void Player::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Player::Release()
{
}

void Player::OnCollision(GameObject* pTarget)
{
	if (pTarget->GetObjectName() == "Bullet") {
		this->KillMe();
		pTarget->KillMe();
	}
}
