#pragma once
#include "Engine/GameObject.h"

class Text;
class TitleScene :
    public GameObject
{
    Text* pText;
    int hPict_;
public:
    TitleScene(GameObject* parent);

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;
};