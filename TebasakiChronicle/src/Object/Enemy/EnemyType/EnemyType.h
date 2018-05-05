#pragma once
#include "EnemyMoveSet.h"
#include "../../../BaseClass/Collision/CollisionManager.h"

//EnemyMoveSet�Ƃ��̑��G�̐����ɕK�v�ƂȂ�G���
class EnemyType
{
private:
	EnemyMoveSet* emSet;		//����܂Ƃ�

	const std::string			textureName;	//�摜��
	K_Graphics::Texture*		texture;		//�e�N�X�`��
	const int					maxLife;		//�̗͏��
	const int					hitDamage;		//�ڐG���A�v���C���[�ɗ^����_���[�W

	K_Physics::CollisionShape*	baseShape;			//�n�`�p�R���W�����̌`��
	K_Physics::CollisionShape*	receiveShape;		//��_���A�J�����K���p�R���W�����̌`��
	K_Physics::CollisionShape*	fovShape;			//���E�p�R���W�����̌`��
	K_Physics::CollisionShape*	attackAreaShape;	//�U������J�ڗp�R���W�����̌`��
	K_Physics::CollisionShape*	checkShape;			//�����A���㔻��p�R���W�����̌`��

	K_Math::Vector3		receivePos;		//��_���A�J�����K���p�R���W�����̈ʒu
	K_Math::Vector3		fovPos;			//���E�p�R���W�����̈ʒu
	K_Math::Vector3		attackAreaPos;	//�U������J�ڗp�R���W�����̈ʒu
	K_Math::Vector3		checkFootPos;	//��������R���W�����̈ʒu
	K_Math::Vector3		checkHeadPos;	//���㔻��R���W�����̈ʒu

public:
	//�R���X�g���N�^
	EnemyType(	std::string texName,
				int maxlife,
				int hitdamage,
				K_Physics::CollisionShape* sBase,
				K_Physics::CollisionShape* sReceive,
				K_Physics::CollisionShape* sFieldofview,
				K_Physics::CollisionShape* sAttackArea,
				K_Physics::CollisionShape* sCheck,
				K_Math::Vector3& pRecieve,
				K_Math::Vector3& pFieldofview,
				K_Math::Vector3& pAttackArea,
				K_Math::Vector3& pCheckFoot,
				K_Math::Vector3& pCheckHead);
	//�f�X�g���N�^
	~EnemyType();

	//EnemyMoveSet���擾
	EnemyMoveSet* GetEnemyMoveSet();
	//�摜�����擾
	const std::string& GetTextureName();
	//�̗͏�����擾
	const int GetMaxLife();
	//�v���C���[�ɗ^����_���[�W�ʂ��擾
	const int GetHitDamage();
	//�e�N�X�`�����擾
	K_Graphics::Texture* GetTexture();

	//�n�`�p�R���W�����f�[�^�̐����Ǝ擾
	K_Physics::CollisionData* GetBaseCollisionData();
	//��_���p�R���W�����f�[�^�̐����Ǝ擾
	K_Physics::CollisionData* GetRecieveDamageCollisionData();
	//��J�����K���p�R���W�����f�[�^�̐����Ǝ擾
	K_Physics::CollisionData* GetRecieveCameraCollisionData();
	//���E�p�R���W�����f�[�^�̐����Ǝ擾
	K_Physics::CollisionData* GetFieldofviewCollisionData();
	//�U������J�ڗp�R���W�����̐����Ǝ擾
	K_Physics::CollisionData* GetAttackAreaCollisionData();
	//�����p�R���W�����̐����Ǝ擾
	K_Physics::CollisionData* GetCheckFootCollisionData();
	//����p�R���W�����̐����Ǝ擾
	K_Physics::CollisionData* GetCheckHeadCollisionData();
};
