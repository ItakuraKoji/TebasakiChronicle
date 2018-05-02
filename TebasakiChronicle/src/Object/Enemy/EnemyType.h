#pragma once
#include "EnemyMoveSet.h"
#include "../../BaseClass/Collision/CollisionCreator.h"

//EnemyMoveSet�Ƃ��̑��G�̐����ɕK�v�ƂȂ�G���
class EnemyType
{
public:
	EnemyMoveSet * emSet;		//����܂Ƃ�

	const std::string			textureName;	//�摜��
	const int					maxLife;		//�̗͏��
	const int					hitDamage;		//�ڐG���A�v���C���[�ɗ^����_���[�W
	K_Graphics::Texture*		texture;		//�e�N�X�`��
	K_Physics::CollisionShape*	cShape;			//�ڐG�p�R���W�����̌`��
												//���E�p�R���W�����̌`��
												//�U������J�ڗp�R���W�����̌`��

	//�R���X�g���N�^
	EnemyType(std::string imgName, K_Physics::CollisionShape* cs, int ml, int atk);
	//�f�X�g���N�^
	~EnemyType();
};
