#pragma once
//#include "../src/Object/GameObject.h"
#include "../src/Object//Player/CameraGun/CameraGun.h"
#include "../src/Object/Player/CharaController/CharaController.h"

//--------------------------------------------------------------------
//�v���C���[
//�T�v:�v���C���[��p�̂���
//�����:�����
//--------------------------------------------------------------------
class Player
{
public:
	Player();
	~Player();

	//���̑傫�ȏ���
	void	Initliaze();	//������
	void	UpDate();		//�X�V
	void	Render();		//�`��

	//�J�����K���̃X�L�����擾����
	void	SetSkillData();

	//InputClass�̎擾����
	void	GetInputClass(K_Input::InputClass* input);

	//�J�����K���𐶐�����
	void	CreateCameraGun();

private:
	GameObject		object;		//�Q�[���I�u�W�F�N�g
	CharaController	controller;	//�R���g���[���[
public:
	CameraGun		cameraGun;	//�J�����K��
	
	K_Input::InputClass*		input;		//InputClass


public:
	K_Physics::BulletPhysics*	physics;	//����BulletPhysics
	K_Physics::CollisionShape*	shape;		//�`�̍쐬
	K_Physics::CollisionData*	collision;	//�R���W����
	K_Physics::CollisionTag*	targetTag;	//�^�[�Q�b�g�̃R���W�����^�O
};