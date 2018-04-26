#pragma once
#include "EnemyMoveSet.h"

//�G�̎�ޕʂɐݒ肳�ꂽ����A�h���X�����L���A
//���쏈�����Ăяo���N���X
class EnemyController
{
public:
	EnemyMoveSet* ems;		//����(delete�֎~)

	int skillId;			//���݂̓G����ǂݎ���X�L���ԍ�
	int timeCnt;			//���Ԍv��

	//�R���X�g���N�^
	EnemyController(EnemyMoveSet* cpyems);
	//�f�X�g���N�^
	~EnemyController();

	//����̎��s
	void Move(int& nowMoveOrder, int& nowPatternOrder, K_Math::Vector3& moveVec);

	//EnemyMoveSet����L�����`�b�v���擾
	const std::vector<AnimationCharaChip*> GetNowCharaChip(int nowPatternOrder);
};