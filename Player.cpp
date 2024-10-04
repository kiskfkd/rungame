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
	//後片付け
}

void Player::Initialize()
{
	hModel_ = Model::Load("box.fbx");
	assert(hModel_ >= 0);
	transform_.position_ = { 0, 0, 0 };

	// 衝突判定のためのコライダーを追加（SphereCollider）
	BoxCollider* collision = new BoxCollider(XMFLOAT3(0, 0, 0), XMFLOAT3(0.6, 0.6, 0.6));
	AddCollider(collision);
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

void Player::OnCollision(GameObject* pTarget)
{
	//std::this_thread::sleep_for(std::chrono::seconds(1));  // 1秒待ち

SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
pSceneManager->ChangeScene(SCENE_ID_CLEAR);
		
	
}
