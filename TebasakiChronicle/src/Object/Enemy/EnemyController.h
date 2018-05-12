#pragma once
#include "EnemyType/EnemyMoveSet.h"

//�G�̎�ޕʂɐݒ肳�ꂽ����A�h���X�����L���A
//���쏈�����Ăяo���N���X
class EnemyController
{
private:
	EnemyMoveSet* ems;	//����(delete�֎~)

	int timeCnt;		//���Ԍv��
	int skillId;		//���݂̓G����ǂݎ���X�L���ԍ�

public:

	//�R���X�g���N�^
	EnemyController(EnemyMoveSet* cpyems);
	//�f�X�g���N�^
	~EnemyController();

	//�X�L���ԍ����擾
	int& GetSkillId();

	//����̎��s
	void EMove(int& nowMoveOrder, int& nowPatternOrder, CollisionManager& cm, TemporaryCollisionManager& tempmanager, Status& status, Move& move);

	//EnemyMoveSet����L�����`�b�v���擾
	const std::vector<AnimationCharaChip*> GetNowCharaChip(int nowPatternOrder);
};