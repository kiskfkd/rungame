#include "PlayScene.h"
//#include "Stage.h"
#include "Player.h"
#include"Enemy.h"
//#include "Gauge.h"
#include "Engine/Camera.h"
PlayScene::PlayScene(GameObject* parent)
	:GameObject(parent, "PlayScene")
{
}
PlayScene::~PlayScene() {};
void PlayScene::Initialize()
{
//	Instantiate<Stage>(this);
Instantiate<Player>(this);
Instantiate<Enemy>(this);
//	Instantiate<Gauge>(this);

}

void PlayScene::Update()
{

}

void PlayScene::Draw()
{
}

void PlayScene::Release()
{
}