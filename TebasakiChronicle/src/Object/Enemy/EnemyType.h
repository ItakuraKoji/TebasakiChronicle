#pragma once
#include "EnemyMoveSet.h"

//EnemyMoveSet�Ƃ��̑��G�̐����ɕK�v�ƂȂ�G���
class EnemyType
{
public:
	EnemyMoveSet*	emSet;		//����܂Ƃ�

	const std::string			imageName;	//�摜��
	const int					maxLife;	//�̗͏��
	const int					hitDamage;	//�ڐG���A�v���C���[�ɗ^����_���[�W
	K_Graphics::Texture*		texture;	//�e�N�X�`��
	//�ڐG�p�R���W�����̃T�C�Y
	//���E�p�R���W�����̃T�C�Y
	//�U������J�ڗp�R���W�����̃T�C�Y


	//�R���X�g���N�^
	EnemyType(std::string imgName, int ml, int atk);
	//�f�X�g���N�^
	~EnemyType();
};
