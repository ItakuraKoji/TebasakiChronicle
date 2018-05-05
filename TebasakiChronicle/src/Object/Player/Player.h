#pragma once
#include "../src/Object/GameObject.h"
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

private:
	GameObject		object;		//�Q�[���I�u�W�F�N�g
	CharaController	controller;	//�R���g���[���[
	CameraGun		cameraGun;	//�J�����K��
};