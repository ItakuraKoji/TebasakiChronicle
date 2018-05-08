#pragma once
#include "../../BaseClass/Collision/CollisionManager.h"

//�ꎞ�I�ɐ��������R���W����
//(���Ԍo�߂ŏ�������A�P�Ƃœ������肷��)
class TemporaryCollision
{
private:
	K_Physics::CollisionShape*	cShape;			//�R���W�����̌`��
	CollisionManager			colmanager;		//�R���W�����f�[�^�̊Ǘ���
	GameObject		gameObject;			//�X�e�[�^�X�A�ړ���d�͂̓���A�摜�Ǘ��ASE�Aeasing���������
	int				timeCnt;			//���Ԍv��
	int				deleteTime;			//���ł܂ł̎���
	bool			isHitGround;		//���ꂪtrue���ƒn�`�ɐڐG��������ł���

public:
	//�R���X�g���N�^
	//�R���W�����̌`�����delete����
	TemporaryCollision(K_Physics::CollisionShape*	shape,				//�R���W�����̌`��
						CollisionMask&				mmask,				//�T�u�R���W�����̂Ԃ���Ώ�
						CollisionMask&				gmask,				//�T�u�R���W�������g���w��(�����̏ꍇ��Non)
						K_Math::Vector3&			setpos,				//���W
						K_Math::Vector3&			movevec,			//�ړ���
						Status::Direction&			dir,				//�e�N�X�`���̌���
						int							damage,				//�Ώۂɗ^����_���[�W��
						int							deletetime,			//���g���폜����܂ł̎���
						bool						ishitground,		//�n�`�ɐڐG��������ł���t���O
						bool						doground );			//�x�[�X�R���W������n�`�Ƃ��Ĉ����t���O

	//�R���X�g���N�^
	//�R���W�����̌`�����delete���Ȃ�(�����������L�����Ȃ�)
	TemporaryCollision(	K_Physics::CollisionData*	basedata,		//�x�[�X�R���W�����̃f�[�^
						K_Physics::CollisionData*	subdata,		//�T�u�R���W�����̃f�[�^
						K_Math::Vector3&			setpos,			//���W
						K_Math::Vector3&			moveVec,		//�ړ���
						Status::Direction&			dir,			//�e�N�X�`���̌���
						int							damage,			//�Ώۂɗ^����_���[�W��
						int							deletetime,		//���g���폜����܂ł̎���
						bool						ishitground);	//�n�`�ɐڐG��������ł���t���O

	//�f�X�g���N�^
	~TemporaryCollision();

	//�摜�Ǘ��҂𐶐����A�����ɃL�����`�b�v��ݒ肷��
	void SetImageManagerAndCharaChip(	std::string&			texName,
										K_Graphics::Texture*	texture,
										K_Math::Box2D&			src,
										int						sheet,
										float					spd,
										bool					isroop);

	//�X�V(���ł���ꍇ��true��Ԃ�)
	bool Update();

	//���Ńt���O�𗧂Ă�
	bool Extinction();

	//�`��
	void Render();
};