#pragma once

#include "../src/Object/GameObject.h"
#include "K_Physics\BulletPhysics.h"

//----------------------------------------------------------------
//�J�����K��
//�T�v:�B�e�p�̃J�����ŁA�G���B�e���āA�X�L�����擾����
//�����:�����
//----------------------------------------------------------------
class CameraGun
{
public:
	CameraGun();
	CameraGun(const K_Math::Vector3& moveVec);
	~CameraGun();

	//****************************
	//1:�����Ă�������Ɉړ�����̂́AMove�N���X���s��
	//2:�Փ˔���́ACollision�N���X���s��
	//3:�ǔ������͖��Ȃ�
	//****************************
	void	MoveDir(const K_Math::Vector3& moveVec);	//�����Ă�������Ɉړ�
	void	Chase(const K_Math::Vector3& targetPos);	//�ǔ�����
	bool	HitCheck(const std::string& name);
	
	//������
	void	Initailize();	//����������
	void	UpDate();		//�X�V����
	void	Render();		//�`��

public:
	GameObject	object;	//�Q�[���I�u�W�F�N�g
	bool		active;
private:

public:
	K_Math::Vector3	moveVec;
	K_Physics::BulletPhysics*	physics;	//����BulletPhysics
	K_Physics::CollisionShape*	shape;		//�`�̍쐬
	K_Physics::CollisionData*	collision;	//�R���W����
	K_Physics::CollisionTag*	targetTag;	//�^�[�Q�b�g�̃R���W�����^�O

};