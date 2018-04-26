#pragma once
#include "EnemyType.h"
#include "EnemyController.h"

//�ȉ���include��GameObject�ő�ւ���
#include "../../BaseClass/ImageManager/ImageManager.h"

class Enemy
{
public:
	
	EnemyController*	eController;		//����Ǘ�����
	int					nowMoveOrder;		//���݂̓��쏇��
	int					nowPatternOrder;	//���݂̓���p�^�[���ԍ�
	int					beforeMoveOrder;	//�O�̓��쏇��
	int					beforePatternOrder;	//�O�̓���p�^�[���ԍ�

	//�ȉ��̃����o�ϐ���GameObject��Move�N���X�Ƃ��������Ă���̂��Ǝv��
	int					life;
	K_Math::Vector3		pos;
	K_Math::Vector3		angle;
	K_Math::Vector3		scale;
	K_Math::Vector3		moveVec;
	ImageManager*		imgManager;

	//�R���X�g���N�^
	Enemy(EnemyType* cpyet, const K_Math::Vector3& setPos);
	//�f�X�g���N�^
	~Enemy();

	//�G����ݒ�
	void SetEnemyType(EnemyType* cpyet, const K_Math::Vector3& setPos);

	//�X�V
	void Update();

	//�`��
	void Render();
};