#pragma once
#include "Engine/GameObject.h"
#include "Engine/Text.h"
#include "PlayScene.h"
class Player :
    public GameObject
{
    int hModel_; //モデル番号
    PlayScene* playscene_;
public:
    //コンストラクタ
    Player(GameObject* parent);

    //デストラクタ
    ~Player();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;

   void OnCollision(GameObject* pTarget) override;
};