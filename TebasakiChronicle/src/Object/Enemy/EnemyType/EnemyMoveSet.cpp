#include "EnemyMoveSet.h"

//�R���X�g���N�^
EnemyMoveSet::EnemyMoveSet() {}

//�f�X�g���N�^
EnemyMoveSet::~EnemyMoveSet()
{
	for (auto it : empattern)
		delete it;
}

//-----------------------------------------------------------------------------
//����p�^�[���W���̐���
void EnemyMoveSet::CreateMotionPattern(	int* moveNum,		//����ԍ�����ꂽ�z��̃A�h���X�l
										int* skillId,		//���쒆�Ɏ擾�\�ȃX�L���ԍ�
										int* durationTime,	//����̌p�����Ԃ���ꂽ�z��̃A�h���X�l
										K_Math::Box2D*	src,	//�A�j���[�V�����摜�̍ŏ��̈ʒu
										int*			sheet,	//�A�j���[�V��������
										float*			spd,	//�A�j���[�V�������x
										bool*			ir,		//���[�v���邩�ۂ�
										int				totalMoveNum,		//����̑���
										int				transitionNum)		//����p�^�[���̑J�ڏ����̔ԍ�
{
	empattern.emplace_back(new EnemyMovePattern(moveNum, skillId, durationTime, src, sheet, spd, ir, totalMoveNum, transitionNum));
}

//-----------------------------------------------------------------------------
//�w��p�^�[���ԍ��̃A�j���[�V������Ԃ�
const std::vector<AnimationCharaChip*> EnemyMoveSet::GetNowAnimChip(int nowPatternOrder)
{
	return empattern[nowPatternOrder]->animChip;
}

//-----------------------------------------------------------------------------
//���݂̓���p�^�[�������s���A���݃v���C���[���擾�\�ȃX�L���ԍ���Ԃ�
int EnemyMoveSet::EMove(int& nowMoveOrder, int& nowPatternOrder, int& timeCnt, CollisionManager& colmanager, Status& status, Move& move)
{
	bool endMovePattern = false;	//����p�^�[�����ꏄ������(�Ō�܂ł�������)�ǂ������i�[
	int idNum = empattern[nowPatternOrder]->EMove(nowMoveOrder, timeCnt, status, move, endMovePattern);

	//����p�^�[�����ꏄ������A�p�^�[���ύX�̂��߂̏������s��
	if (endMovePattern == true)
	{
		//�p�^�[���̑J�ڏ����𖞂����Ă�����p�^�[���ύX
		for (int i = 0; i < (int)empattern.size(); ++i)
		{
			if (nowPatternOrder != i &&
				empattern[i]->emt->Transition(colmanager, status))
			{
				PatternTransition(nowMoveOrder, nowPatternOrder, timeCnt, i);
				break;
			}
		}
	}

	return idNum;
}

//-----------------------------------------------------------------------------
//����p�^�[�����w��ԍ��ɑJ�ڂ�����
void EnemyMoveSet::PatternTransition(int& nowMoveOrder, int& nowPatternOrder, int& timeCnt, int patternNum)
{
	if (patternNum >= (int)empattern.size())
		return;

	empattern[nowPatternOrder]->MoveReset(nowMoveOrder);
	nowPatternOrder = patternNum;
	timeCnt = 0;
}