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
	//���[�V����
	enum Motion
	{
		Non = -1,	//�Ȃ�
		Idle = 0,	//�ҋ@
		Walk,		//����
		Run,		//����
		Jump,		//�㏸��
		Fall,		//������
		TakeOff,	//��ԑO
		Landing,	//���n
		SkillUse,	//�X�L���g�p��
	};

	//�R���W�����̎��
	enum CollisionKind
	{
		Base = 0,	//��
		Foot,		//����
		Head,		//����
	};

public:
	Player();
	~Player();

	//���̑傫�ȏ���
	void	Initliaze();	//������
	void	UpDate();		//�X�V
	void	Render();		//�`��

private:
	void	ChangeDir();			//���͂ɉ����Č�����ς���
	void	ShotCameraGun();		//�J�����K�����΂�
	void	ReverseCameraGun();		//�J�����K����߂�
	void	JumpMove();				//�W�����v
	void	SetSkillData();			//�J�����K������X�L�����擾

	void	Think();	//�v�l����(���[�V��������)
	void	Move();		//���[�V�����ɑΉ���������
	//���[�V�����̍X�V
	bool	UpDateMotion(const Motion& nowMotion);


private:
	Motion			motion;		//���[�V����
	int				motionCnt;	//���[�V�����̃J�E���g
	GameObject		object;		//�Q�[���I�u�W�F�N�g
	CharaController	controller;	//�R���g���[���[
	CameraGun		cameraGun;	//�J�����K��
	int				maxFrame;	//�ő�̃t���[����

public:
	K_Physics::CollisionShape*	shape;		//�x�[�X�R���W�����̌`��
	K_Physics::CollisionShape*	shape2;		//�����Ɠ���p�R���W�����̌`��
	CollisionManager			cManager;	//�R���W�����̊Ǘ���
};