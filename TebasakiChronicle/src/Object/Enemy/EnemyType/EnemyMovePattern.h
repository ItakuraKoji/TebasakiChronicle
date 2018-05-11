#pragma once
#include "EnemyMove.h"
#include "EnemyMoveTransition.h"
#include "../../../BaseClass/ImageManager/AnimationCharaChip.h"

//�G����̃p�^�[�����쐬�����I
class EnemyMovePattern
{
public:

	struct MovePattern		//����̎�ށA���Ԃ��������
	{
		EnemyMove*	em;		//����������ōs��
		int skillId;		//���쒆�Ɏ擾�\�ȃX�L���ԍ�
		int moveTimeMax;	//����I���܂ł̎���

		MovePattern(int sklid, int mtime) :
			em(nullptr),
			skillId(sklid),
			moveTimeMax(mtime){}
	};
	std::vector<MovePattern*> mp;
	std::vector<AnimationCharaChip*> animChip;
	std::vector<EnemyMoveTransition*> emt;

	//�R���X�g���N�^
	EnemyMovePattern(	int* moveIdArr,			//����ԍ�����ꂽ�z��̃A�h���X�l
						int* skillIdArr,		//���쒆�Ɏ擾�\�ȃX�L���ԍ�
						int* durationTimeArr,	//����̌p�����Ԃ���ꂽ�z��̃A�h���X�l
						K_Math::Box2D*	src,	//�A�j���[�V�����摜�̍ŏ��̈ʒu
						int*			sheet,	//�A�j���[�V��������
						float*			spd,	//�A�j���[�V�������x
						bool*			ir,		//���[�v���邩�ۂ�
						int*			transitionIdArr,	//������p�^�[���ւ̑J�ڏ����̔ԍ�
						int				patternNum,			//����p�^�[���̑���
						int				totalMoveNum);		//����̑���

	//�f�X�g���N�^
	~EnemyMovePattern();

	//������s���A���ݎ擾�\�ȃX�L���̔ԍ���Ԃ�
	int EMove(int& nowMoveOrder, int& timeCnt, CollisionManager& colmanager, TemporaryCollisionManager& tempmanager, Status& status, Move& move, bool& endMovePattern);

	//���쏇�����Z�b�g����
	void MoveReset(int& nowMoveOrder);

	//�����ݒ肷��
	void SetMoveAndTime(int moveNum, int skillId, int durationTime);

	//����p�^�[���J�ڏ�����ݒ肷��
	void SetTransition(int transitionNum);
};