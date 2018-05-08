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
	void CreateMotionPattern(	int* moveNum,		//����ԍ�����ꂽ�z��̃A�h���X�l
								int* skillId,		//���쒆�Ɏ擾�\�ȃX�L���ԍ�
								int* durationTime,	//����̌p�����Ԃ���ꂽ�z��̃A�h���X�l
								K_Math::Box2D*	src,	//�A�j���[�V�����摜�̍ŏ��̈ʒu
								int*			sheet,	//�A�j���[�V��������
								float*			spd,	//�A�j���[�V�������x
								bool*			ir,		//���[�v���邩�ۂ�
								int				totalMoveNum,		//����̑���
								int				transitionNum);		//����p�^�[���̑J�ڏ����̔ԍ�

	//�w��p�^�[���ԍ��̃A�j���[�V������Ԃ�
	const std::vector<AnimationCharaChip*> GetNowAnimChip(int nowPatternOrder);

	//���݂̓���p�^�[�������s���A���݃v���C���[���擾�\�ȃX�L���ԍ���Ԃ�
	int EMove(int& nowMoveOrder, int& nowPatternOrder, int& timeCnt, CollisionManager& colmanager, Status& status, Move& move);

	//����p�^�[�����w��ԍ��ɑJ�ڂ�����
	void PatternTransition(int& nowMoveOrder, int& nowPatternOrder, int& timeCnt, int patternNum);
};