#include "PlayScene.h"
#include "Stage.h"
#include "Player.h"
#include"Enemy.h"
//#include "Gauge.h"
#include "Engine/Camera.h"
int count = 0;

PlayScene::PlayScene(GameObject* parent)
	:GameObject(parent, "PlayScene")
{
}
PlayScene::~PlayScene() {};
void PlayScene::Initialize()
{
Instantiate<Stage>(this);
Instantiate<Player>(this);
//Instantiate<Enemy>(this);
//Instantiate<Enemy>(this);
//	Instantiate<Gauge>(this);

}

void PlayScene::Update()
{
if (count % 200 == 0){
	Instantiate<Enemy>(this);
	Instantiate<Enemy>(this);
}
	count++;
}

void PlayScene::Draw()
{
}

void PlayScene::Release()
{
}