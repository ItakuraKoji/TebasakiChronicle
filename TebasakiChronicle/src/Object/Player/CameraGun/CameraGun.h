#pragma once

#include "../src/Object/GameObject.h"

//----------------------------------------------------------------
//�J�����K��
//�T�v:�B�e�p�̃J�����ŁA�G���B�e���āA�X�L�����擾����
//�����:�����
//----------------------------------------------------------------
class CameraGun
{
public:
	CameraGun();
	~CameraGun();

	//****************************
	//1:�����Ă�������Ɉړ�����̂́AMove�N���X���s��
	//2:�Փ˔���́ACollision�N���X���s��
	//3:�ǔ������͖��Ȃ�
	//****************************
	void	MoveDir(const K_Math::Vector3& moveVec);	//�����Ă�������Ɉړ�
	bool	HitEnemy();									//�G�ƏՓ˂������̔���
	void	Chase(const K_Math::Vector3& targetPos);	//�ǔ�����

	
	//������
	void	Initailize();	//����������
	void	UpDate();		//�X�V����
	void	Render();		//�`��

private:
	GameObject	object;	//�Q�[���I�u�W�F�N�g
	bool		active;
};