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

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;
};