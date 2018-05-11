#include "EnemyMovePattern.h"

//�R���X�g���N�^
EnemyMovePattern::EnemyMovePattern(	int* moveIdArr,			//����ԍ�����ꂽ�z��̃A�h���X�l
									int* skillIdArr,		//���쒆�Ɏ擾�\�ȃX�L���ԍ�
									int* durationTimeArr,	//����̌p�����Ԃ���ꂽ�z��̃A�h���X�l
									K_Math::Box2D*	src,	//�A�j���[�V�����摜�̍ŏ��̈ʒu
									int*			sheet,	//�A�j���[�V��������
									float*			spd,	//�A�j���[�V�������x
									bool*			ir,		//���[�v���邩�ۂ�
									int*			transitionIdArr,	//������p�^�[���ւ̑J�ڏ����̔ԍ�
									int				patternNum,			//����p�^�[���̑���
									int				totalMoveNum)		//����̑���
{
	for (int i = 0; i < totalMoveNum; ++i)
	{
		SetMoveAndTime(*(moveIdArr + i), *(skillIdArr + i), *(durationTimeArr + i));
		animChip.emplace_back(new AnimationCharaChip(*(src + i), *(sheet + i), *(spd + i), *(ir + i)));
	}
	for (int i = 0; i < patternNum; ++i)
	{
		SetTransition(*(transitionIdArr + i));
	}
}

//�f�X�g���N�^
EnemyMovePattern::~EnemyMovePattern()
{ 
	for (auto it : mp)
	{
		delete it->em;
		delete it;
	}

	for (auto it : animChip)
	{
		delete it;
	}

	for (auto it : emt)
	{
		delete it;
	}
}

//-----------------------------------------------------------------------------
//������s���A���ݎ擾�\�ȃX�L���̔ԍ���Ԃ�
int EnemyMovePattern::EMove(int& nowMoveOrder, int& timeCnt, CollisionManager& colmanager, TemporaryCollisionManager& tempmanager, Status& status, Move& move, bool& endMovePattern)
{
	endMovePattern = false;
	//timeCnt��moveTimeMax�𒴂�����A���̓���Ɉڍs����
	if (timeCnt >= mp[nowMoveOrder]->moveTimeMax)
	{
		timeCnt = 0;

		++nowMoveOrder;
		if (nowMoveOrder >= (int)mp.size())
		{
			nowMoveOrder = 0;
			endMovePattern = true;
		}
	}

	if (timeCnt == 0)	//�ŏ��ɍs������
	{
		mp[nowMoveOrder]->em->FirstMove(colmanager, tempmanager, status, move);
	}
	else				//�ʏ�̓���
	{
		mp[nowMoveOrder]->em->EMove(colmanager, tempmanager, status, move);
	}

	++timeCnt;
	return mp[nowMoveOrder]->skillId;
}

//-----------------------------------------------------------------------------
//���쏇�����Z�b�g����
void EnemyMovePattern::MoveReset(int& nowMoveOrder)
{
	nowMoveOrder = 0;
}

//-----------------------------------------------------------------------------
//�����ݒ肷��
void EnemyMovePattern::SetMoveAndTime(int moveNum, int skillId, int durationTime)
{
	mp.emplace_back(new MovePattern(skillId, durationTime));
	switch (moveNum)
	{
	case 0:		//�������Ȃ�
		mp.back()->em = new EMove_NoMotion();
		break;

	case 1:		//�����Ă�������Ɉړ�����
		mp.back()->em = new EMove_Movement();
		break;

	case 2:		//�W�����v����
		mp.back()->em = new EMove_Jump();
		break;

	case 3:		//�O���ɍU������
		mp.back()->em = new EMove_FrontAttack();
		break;
	}
}

//-----------------------------------------------------------------------------
//����p�^�[���J�ڏ�����ݒ肷��
void EnemyMovePattern::SetTransition(int transitionNum)
{
	emt.emplace_back();
	switch (transitionNum)
	{
	case 0:	//�J�ڂ��Ȃ�
		emt.back() = new ETransition_NotTrans();
		break;

	case 1: //���E���Ƀv���C���[�������Ă���Ƃ�
		emt.back() = new ETransition_PIntoView();
		break;

	case 2: //���E���ɓ����Ă���v���C���[�����g�̔��Ε����Ɉړ������Ƃ�
		emt.back() = new ETransition_PMoveOtherSide();
		break;
	}
}