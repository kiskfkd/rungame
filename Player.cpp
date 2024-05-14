#include "Player.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Engine/Debug.h"
#include "Engine/Image.h"
#include "Engine/SceneManager.h"
#include "Engine/SphereCollider.h"
//#include "Stage.h"
//#include "Gauge.h"

Player::Player(GameObject* parent)
	:GameObject(parent, "Player"), hModel_(-1)
{
}

Player::~Player()
{
	//Œã•Ð•t‚¯
}

void Player::Initialize()
{
	hModel_ = Model::Load("eisei.fbx");
	assert(hModel_ >= 0);
	transform_.position_ = { 0,0,0 };
	
}

void Player::Update()

{
	if (Input::IsKeyDown(DIK_LEFT))
	{
		if (transform_.position_.x >-2.5f) 
			transform_.position_.x -= 2.5f;
	}
	if (Input::IsKeyDown(DIK_RIGHT))
	{
		if(transform_.position_.x <2.5f)
			transform_.position_.x += 2.5f;
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

//void Player::OnCollision(GameObject* pTarget)
//{
//	if (pTarget->GetObjectName() == "stone") {
//		this->KillMe();
//		pTarget->KillMe();
//		
//	}
//}
