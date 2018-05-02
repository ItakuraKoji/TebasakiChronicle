#pragma once
#include "CollisionCreator.h"

class CollisionManager
{
private:
	K_Physics::CollisionData*	baseCollision;	//��ƂȂ�R���W����(�n�`�Ƃ̂߂荞�ݔ���̂ݍs��)

	struct Sub	//�T�u�R���W����
	{
		K_Physics::CollisionData*	collision;		//�T�u�ƂȂ�R���W����
		K_Math::Vector3*			relativePos;	//�x�[�X�R���W�����Ƃ̑��΍��W

		Sub(K_Physics::CollisionData*	cln,
			K_Math::Vector3*			rp) :
			collision(cln),
			relativePos(rp){}
	};
	std::vector<Sub*> subCollision;

	//�x�[�X�R���W�����̍��W����ɃT�u�R���W�����̈ʒu��ݒ肷��
	void SetSubCollisionPos(int angle);

public:
	CollisionManager();
	~CollisionManager();

	//�x�[�X�R���W������ݒ肷��
	//��l������false�Œn�`�Ƃ̐ڐG���蓙���s��Ȃ�
	void CreateBaseCollisionData(K_Physics::CollisionShape* cs, const K_Math::Vector3& pos, const K_Math::Vector3& rot, bool isJudge);

	//�T�u�R���W������ݒ肷��(�w����W�́A�I�u�W�F�N�g���E�������̃x�[�X�R���W�����Ƃ̑��΍��W)
	//���ghost��true
	void CreateSubCollisionData(K_Physics::CollisionShape* cs, int mask, const K_Math::Vector3& pos, const K_Math::Vector3& rot);

	//�w�肵���T�u�R���W�����Ƀ^�O(userData)��ݒ肷��
	void SetSubCollisionTug(int subNum, void* tug);

	//�x�[�X�R���W�����𓮂����A�t�����ăT�u�̍��W��ݒ肷��
	//��O������true�Ōy�ʓ���
	void MoveBaseCollision(K_Math::Vector3 moveVec, int angle, bool isLightness);

	//�w�肵���T�u�R���W�����̎󂯎�����^�O�̓��AuserData�݂̂𒊏o���ĕԂ�
	//����(tagIndex������)�ȃR���W�����ƏՓ˂����ꍇ�͏��O����
	std::vector<void*> GetConflictionObjectsUserData(int subNum);
};