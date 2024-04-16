#include "Enemy.h"
#include "Engine/Model.h"
#include"Engine/Collider.h"
float p[] = { -2,0,2 };
Enemy::Enemy(GameObject* parent)
	:GameObject(parent, "Enemy"), hModel_(-1)
{

}

Enemy::~Enemy()
{
}

void Enemy::Initialize()
{
	hModel_ = Model::Load("Bullet.fbx");
	assert(hModel_ >= 0);
	transform_.position_ = {p[rand() % 3], 0, 20};
	SphereCollider* collision = new SphereCollider({ 0, 0, 0 }, 1.0f);
	AddCollider(collision);
}

void Enemy::Update()
{
	transform_.position_.z -= 0.1;
	if (transform_.position_.z <= -4.0f)
	{
		KillMe();
	}
}

void Enemy::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Enemy::Release()
{
}

void Enemy::OnCollision(GameObject* pTarget)
{
	if (pTarget->GetObjectName() == "Player") {
		this->KillMe();
		pTarget->KillMe();
	}
}
