#include "Enemy.h"
#include "Engine/Model.h"
#include "Engine/SphereCollider.h"
#include "Engine/SceneManager.h"  // シーン移動用のクラス


float p[] = { -2.5, 0, 2.5 };

Enemy::Enemy(GameObject* parent)
    : GameObject(parent, "Enemy"), hModel_(-1)
{
}

Enemy::~Enemy()
{
}

void Enemy::Initialize()
{
    hModel_ = Model::Load("stone.fbx");
    assert(hModel_ >= 0);
    transform_.position_ = { p[rand() % 3], 0, 20 };

    // 衝突判定を追加
    BoxCollider* collision = new BoxCollider(XMFLOAT3(0, 0, 0), XMFLOAT3(0.35, 0.35, 0.35));
    AddCollider(collision);
}

void Enemy::Update()
{
    transform_.position_.z -= 0.1f;
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
    // 衝突判定が行われているかをデバッグメッセージで確認
   // Debug::Log("Collision detected!");

    // "stone" に衝突したか確認
    if (pTarget->GetObjectName() == "stone") {
       // Debug::Log("Hit the stone!");

        // "box" オブジェクトを取得し、削除する
        GameObject* box = GetParent()->FindChildObject("box");  // 親からboxを探す
        if (box) {
            box->KillMe();  // box を削除
          //  Debug::Log("Box deleted");
        }

        // シーン移動 (例えば "NextScene" というシーンに移動)
        SceneManager* pSM = (SceneManager*)FindObject("SceneManager");
        pSM->ChangeScene(SCENE_ID_CLEAR);
    }
}



