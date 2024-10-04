#pragma once
#include "Engine/GameObject.h"
#include "Engine/Text.h"
#include "PlayScene.h"
class Player :
    public GameObject
{
    int hModel_; //���f���ԍ�
    PlayScene* playscene_;
public:
    //�R���X�g���N�^
    Player(GameObject* parent);

    //�f�X�g���N�^
    ~Player();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;

   void OnCollision(GameObject* pTarget) override;
};