#pragma once
#include "TemporaryCollision.h"

//�ꎞ�I�ɐ��������R���W�������Ǘ�����
class TemporaryCollisionManager
{
private:
	K_Physics::CollisionShape*			cShape;			//�R���W�����̌`����(�ꍇ�ɂ���Ă͎g�p���Ȃ�)
	std::vector<TemporaryCollision*>	tempCollision;	//�ꎞ�I�ɐ��������R���W����

public:
	TemporaryCollisionManager();
	TemporaryCollisionManager(K_Physics::CollisionShape* cshape);
	~TemporaryCollisionManager();

	//�R���W�����𐶐�����
	void CreateTemporaryCollision(	K_Physics::CollisionShape*	shape,			//�R���W�����̌`��
									CollisionMask&				mmask,			//�Ԃ���Ώ�
									CollisionMask&				gmask,			//�T�u�R���W�������g���w��(�����̏ꍇ��Non)
									K_Math::Vector3&			setpos,			//���W
									K_Math::Vector3&			movevec,		//�ړ���
									Status::Direction&			dir,			//�e�N�X�`���̌���
									int							damage,			//�Ώۂɗ^����_���[�W��
									int							deletetime,		//���g���폜����܂ł̎���
									bool						ishitground,	//�n�`�ɐڐG��������ł���t���O
									bool						doground);		//�x�[�X�R���W������n�`�Ƃ��Ĉ����t���O

	//�}�l�[�W���ۗ̕L����R���W�����`���񂩂�R���W�����𐶐�����
	void CreateTempCollisionUseSelfShape(	CollisionMask&				mmask,			//�Ԃ���Ώ�
											CollisionMask&				gmask,			//�T�u�R���W�������g���w��(�����̏ꍇ��Non)
											K_Math::Vector3&			setpos,			//���W
											K_Math::Vector3&			movevec,		//�ړ���
											Status::Direction&			dir,			//�e�N�X�`���̌���
											int							damage,			//�Ώۂɗ^����_���[�W��
											int							deletetime,		//���g���폜����܂ł̎���
											bool						ishitground,	//�n�`�ɐڐG��������ł���t���O
											bool						doground);		//�x�[�X�R���W������n�`�Ƃ��Ĉ����t���O

	//���������R���W�����Ƀe�N�X�`����ݒ肷��
	void SetAnimationCharaChip(	std::string&			texName,
								K_Graphics::Texture*	texture,
								K_Math::Box2D&			src,
								int						sheet,
								float					spd,
								bool					isroop);

	//�R���W�����̍X�V���s��
	//�R���W����������ŗv�����������ꍇ���ł�����
	void Update();

	//�R���W�����̕`����s��
	void Render();
};