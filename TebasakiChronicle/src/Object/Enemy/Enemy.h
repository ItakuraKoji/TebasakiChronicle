#pragma once
#include "EnemyType.h"
#include "EnemyController.h"

//�ȉ���include��GameObject�ő�ւ���
#include "../../BaseClass/ImageManager/ImageManager.h"

class Enemy
{
	EnemyController*	eController;		//����Ǘ�����
	int					nowMoveOrder;		//���݂̓��쏇��
	int					nowPatternOrder;	//���݂̓���p�^�[���ԍ�
	int					beforeMoveOrder;	//�O�̓��쏇��
	int					beforePatternOrder;	//�O�̓���p�^�[���ԍ�

	//�ȉ��̃����o�ϐ���GameObject��Move�N���X�Ƃ��������Ă���̂��Ǝv��
	int							life;
	K_Math::Vector3				pos;
	K_Math::Vector3				angle;
	K_Math::Vector3				scale;
	K_Math::Vector3				moveVec;
	ImageManager*				imgManager;
	
	K_Physics::CollisionData*	cData;		//�v���C���[�ڐG�p�R���W�������
											//�J�����B�e�p�R���W�������(�`��͐ڐG�p�Ɠ���)
											//�n�`����p�R���W�������(�`��͐ڐG�p�Ɠ���)
											//���㔻��p�R���W�������(�ڐG�p�̐^��)
											//��������p�R���W�������(�ڐG�p�̐^��)
											//���E����p�R���W�������
											//�U������J�ڗp�R���W�������(�A�^�b�N�G���A)

public:
	//�X�L���ԍ��ƌ��݂̃e�N�X�`�����A�L�����`�b�v�ԍ����i�[
	//������J�����󂯗p�R���W�����̃^�O�Ɏw�肷��
	struct SkillAndCharaChip
	{
		int					skillId;
		std::string*		textureName;
		AnimationCharaChip* nowCharaChip;
	};
	SkillAndCharaChip skillAndChip;

	//�R���X�g���N�^
	Enemy(EnemyType* cpyet, const K_Math::Vector3& setPos);
	//�f�X�g���N�^
	~Enemy();

	//�G����ݒ�
	void SetEnemyType(EnemyType* cpyet, const K_Math::Vector3& setPos);

	//�X�L�������i�[
	void SetSkillData();

	//�X�V
	void Update();

	//�`��
	void Draw();
};
