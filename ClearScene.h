#pragma once
#include "Engine/GameObject.h"
class Text;

class ClearScene :
	public GameObject
{
	Text* pText;
	int hPict_;
public:
	//�R���X�g���N�^
	ClearScene(GameObject* parent);

	//�f�X�g���N�^
	~ClearScene();

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};