#include "Enemy.h"
#include "Engine/Model.h"
#include "Engine/SphereCollider.h"
#include "Engine/SceneManager.h"  // �V�[���ړ��p�̃N���X


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

    // �Փ˔����ǉ�
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
    // �Փ˔��肪�s���Ă��邩���f�o�b�O���b�Z�[�W�Ŋm�F
   // Debug::Log("Collision detected!");

    // "stone" �ɏՓ˂������m�F
    if (pTarget->GetObjectName() == "stone") {
       // Debug::Log("Hit the stone!");

        // "box" �I�u�W�F�N�g���擾���A�폜����
        GameObject* box = GetParent()->FindChildObject("box");  // �e����box��T��
        if (box) {
            box->KillMe();  // box ���폜
          //  Debug::Log("Box deleted");
        }

        // �V�[���ړ� (�Ⴆ�� "NextScene" �Ƃ����V�[���Ɉړ�)
        SceneManager* pSM = (SceneManager*)FindObject("SceneManager");
        pSM->ChangeScene(SCENE_ID_CLEAR);
    }
}



