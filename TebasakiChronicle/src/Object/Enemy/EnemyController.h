#pragma once
#include "EnemyMoveSet.h"

//�G�̎�ޕʂɐݒ肳�ꂽ����A�h���X�����L���A
//���쏈�����Ăяo���N���X
class EnemyController
{
private:
	EnemyMoveSet* ems;	//����(delete�֎~)

	int skillId;		//���݂̓G����ǂݎ���X�L���ԍ�
	int timeCnt;		//���Ԍv��

public:

	//�R���X�g���N�^
	EnemyController(EnemyMoveSet* cpyems);
	//�f�X�g���N�^
	~EnemyController();

	//�X�L���ԍ����擾
	int GetSkillId();

	//����̎��s
	void Move(int& nowMoveOrder, int& nowPatternOrder, K_Math::Vector3& moveVec);

	//EnemyMoveSet����L�����`�b�v���擾
	const std::vector<AnimationCharaChip*> GetNowCharaChip(int nowPatternOrder);
};