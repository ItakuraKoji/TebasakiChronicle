#pragma once
#include "EnemyMovePattern.h"

//EnemyMovePattern���܂Ƃ߂����
class EnemyMoveSet
{
private:
	std::vector<EnemyMovePattern*>		empattern;		//����p�^�[��

public:
	EnemyMoveSet();
	~EnemyMoveSet();

	//����p�^�[���W���̐���
	void CreateMotionPattern(	int* moveIdArr,			//����ԍ�����ꂽ�z��̃A�h���X�l
								int* skillIdArr,		//���쒆�Ɏ擾�\�ȃX�L���ԍ�
								int* durationTimeArr,	//����̌p�����Ԃ���ꂽ�z��̃A�h���X�l
								K_Math::Box2D*	src,	//�A�j���[�V�����摜�̍ŏ��̈ʒu
								int*			sheet,	//�A�j���[�V��������
								float*			spd,	//�A�j���[�V�������x
								bool*			ir,		//���[�v���邩�ۂ�
								int*			transitionIdArr,	//������p�^�[���ւ̑J�ڏ����̔ԍ�
								int				patternNum,			//����p�^�[���̑���
								int				totalMoveNum);		//����̑���

	//�w��p�^�[���ԍ��̃A�j���[�V������Ԃ�
	const std::vector<AnimationCharaChip*> GetNowAnimChip(int nowPatternOrder);

	//���݂̓���p�^�[�������s���A���݃v���C���[���擾�\�ȃX�L���ԍ���Ԃ�
	int EMove(int& nowMoveOrder, int& nowPatternOrder, int& timeCnt, CollisionManager& colmanager, TemporaryCollisionManager& tempmanager, Status& status, Move& move);

	//����p�^�[�����w��ԍ��ɑJ�ڂ�����
	void PatternTransition(int& nowMoveOrder, int& nowPatternOrder, int& timeCnt, int patternNum);
};