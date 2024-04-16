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
	int e = 0;
	if (e % 60 == 0)
	{
		int k = rand() % 180;
		if (k == 0)
		{
			Instantiate<Enemy>(this);
		}
		else if (k == 1)
		{
			Instantiate<Enemy>(this);
			Instantiate<Enemy>(this);
		}
		e = 0;
	}
	else {
		e++;
	}
}

void PlayScene::Draw()
{
}

void PlayScene::Release()
{
}