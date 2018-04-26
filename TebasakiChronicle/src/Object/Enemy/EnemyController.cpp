#include "EnemyController.h"

//�R���X�g���N�^
EnemyController::EnemyController(EnemyMoveSet* cpyems) :
	ems(cpyems),
	skillId(0),
	timeCnt(0) {}

//�f�X�g���N�^
EnemyController::~EnemyController(){}

//-----------------------------------------------------------------------------
//����̎��s
void EnemyController::Move(int& nowMoveOrder, int& nowPatternOrder, K_Math::Vector3& moveVec)
{
	ems->Move(nowMoveOrder, nowPatternOrder, timeCnt, moveVec);
}

//-----------------------------------------------------------------------------
//EnemyMoveSet����L�����`�b�v���擾
const std::vector<AnimationCharaChip*> EnemyController::GetNowCharaChip(int nowPatternOrder)
{
	return ems->empattern[nowPatternOrder]->animChip;
}