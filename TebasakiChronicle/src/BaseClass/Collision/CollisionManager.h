#pragma once
#include "CollisionCreator.h"
#include "../../Object/GameObject.h"

//mask�̐ݒ�ɂ͂�����g�p
enum CollisionMask
{
	Non					= 0,
	Ground				= 1 << 0,
	PlayerCollision		= 1 << 1,
	EnemyCollision		= 1 << 2,
	TakeDamagePlayer	= 1 << 3,
	TakeDamageEnemy		= 1 << 4,
	CameraGan			= 1 << 5,
	EnemyCamCollision	= 1 << 6,
};

class CollisionManager
{
private:
	K_Physics::CollisionData*	baseCollision;	//��ƂȂ�R���W����(�n�`�Ƃ̂߂荞�ݔ���̂ݍs��)
	K_Math::Vector3				basePosition;	//��R���W�����̍��W
	struct Sub	//�T�u�R���W����
	{
		K_Physics::CollisionData*	collision;		//�T�u�ƂȂ�R���W����
		K_Math::Vector3				relativePos;	//�x�[�X�R���W�����Ƃ̑��΍��W

		Sub(K_Physics::CollisionData*	cln,
			K_Math::Vector3&			rp) :
			collision(cln),
			relativePos(rp){}
	};
	std::vector<Sub*> subCollision;

	//�x�[�X�R���W�����̍��W����ɃT�u�R���W�����̈ʒu��ݒ肷��
	void SetSubCollisionPos(int angle);

public:
	CollisionManager();
	~CollisionManager();

	//�x�[�X�R���W�������쐬����
	//��l������false�Œn�`�Ƃ̐ڐG���蓙���s��Ȃ�
	void CreateBaseCollisionData(K_Physics::CollisionShape* cs, const K_Math::Vector3& pos, const K_Math::Vector3& rot, bool isJudge);
	//�x�[�X�R���W������ݒ肷��
	void SetBaseCollisionData(K_Physics::CollisionData* cd, const K_Math::Vector3& pos);

	//�T�u�R���W�������쐬����(�w����W�̓I�u�W�F�N�g���E�������̃x�[�X�R���W�����Ƃ̑��΍��W)
	//���ghost��true
	void CreateSubCollisionData(K_Physics::CollisionShape* cs, int myselfMask, int giveMask, K_Math::Vector3& pos);
	//�T�u�R���W������ݒ肷��
	void SetSubCollisionData(K_Physics::CollisionData* cd);

	//�w�肵���T�u�R���W�����Ƀ^�O(userData)��ݒ肷��
	void SetSubCollisionTug(int subNum, void* tug);

	//�x�[�X�R���W�����𓮂����A�t�����ăT�u�̍��W��ݒ肷��
	//��O������true�Ōy�ʓ���
	void MoveBaseCollision(K_Math::Vector3& moveVec, int direction, bool isLightness);

	//�w�肵���T�u�R���W�����̎󂯎�����^�O�̓��AuserData�݂̂𒊏o���ĕԂ�
	//����(tagIndex������)�ȃR���W�����ƏՓ˂����ꍇ�͏��O����
	std::vector<void*> GetConflictionObjectsUserData(int subNum);

	//�x�[�X�R���W�����̍��W��Ԃ�
	K_Math::Vector3& GetBaseCollisionObjectPosition();
};