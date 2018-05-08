#pragma once
#include "EnemyType/EnemyType.h"
#include "EnemyController.h"
#include "../../BaseClass/Collision/CollisionManager.h"

//�ȉ���include��GameObject�ő�ւ���
#include "../GameObject.h"

class Enemy
{
	EnemyController*	eController;		//����Ǘ�
	int					nowMoveOrder;		//���݂̓��쏇��
	int					nowPatternOrder;	//���݂̓���p�^�[���ԍ�
	int					beforeMoveOrder;	//�O�̓��쏇��
	int					beforePatternOrder;	//�O�̓���p�^�[���ԍ�

	CollisionManager	collisionManager;	//�R���W�����̊Ǘ�
	GameObject			gameObject;			//�Q�[���I�u�W�F�N�g

public:
	//�X�L���ԍ��ƌ��݂̃e�N�X�`�����A�L�����`�b�v�ԍ����i�[
	//������J�����󂯗p�R���W�����̃^�O�Ɏw�肷��
	struct SkillAndCharaChip
	{
		K_Math::Vector3*	pos;
		std::string*		textureName;
		int*				skillId;
		AnimationCharaChip* nowCharaChip;
	};
	SkillAndCharaChip skillAndChip;

	//�R���X�g���N�^
	Enemy(EnemyType* cpyet, const K_Math::Vector3& setPos, const Status::Direction& direction);
	//�f�X�g���N�^
	~Enemy();

	//�G����ݒ�
	void SetEnemyType(EnemyType* cpyet, const K_Math::Vector3& setPos, const Status::Direction& direction);

	//�X�V(���S�������ۂ���Ԃ�)
	bool Update();

	//�X�L�������i�[
	void SetTugData();

	//�`��A�A�j���[�V�����̍X�V
	void AnimationUpdate();
	
	//�`��
	void Draw();
};
