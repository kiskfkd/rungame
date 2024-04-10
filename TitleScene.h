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

    //‰Šú‰»
    void Initialize() override;

    //XV
    void Update() override;

    //•`‰æ
    void Draw() override;

    //ŠJ•ú
    void Release() override;
};