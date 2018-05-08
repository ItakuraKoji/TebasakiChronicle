#pragma once
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


	//�J�����K���𐶐�����
	void	CreateCameraGun();

private:
	void	ChangeDir();		//���͂ɉ����Č�����ς���
	void	ShotCameraGun();	//�J�����K�����΂�
	void	ReverseCameraGun();	//�J�����K����߂�
	void	Jump();				//�W�����v

private:
	GameObject		object;		//�Q�[���I�u�W�F�N�g
	CharaController	controller;	//�R���g���[���[
public:
	CameraGun		cameraGun;	//�J�����K��

public:
	K_Physics::CollisionShape*	shape;		//�`�̍쐬
	CollisionManager			cManager;	//�R���W�����̊Ǘ���
};