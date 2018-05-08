#include "CameraGun.h"

//---------------------------------------------------------------
//�T�v:�J�����K���̎���
//�����:�����
//---------------------------------------------------------------

//-------------------------------------------------
//�R���X�g���N�^
//-------------------------------------------------
CameraGun::CameraGun()
{

}

//-------------------------------------------------
//�f�X�g���N�^
//-------------------------------------------------
CameraGun::~CameraGun()
{

}


//�X�V����
void	CameraGun::UpDate()
{
	//�J�������L�����ǂ���
	if (!active) { return; }

	//�G�ƏՓ˂����ꍇ
	if (HitEnemy())
	{
		K_Math::Vector3 tarPos;	//�Փ˂����G�̈ʒu
		Chase(tarPos);			//�ǔ�
	}
	else //�Փ˂��Ȃ��ꍇ
	{
		K_Math::Vector3 moveVec;	//�ړ���
		K_Math::Vector3	dir;		//����
		K_Math::Vector3 myPos;		//�����̈ʒu

		//---Vector3�Ȃǂ́A*���Z�q�Ōv�Z���ł��Ȃ�---
		//myPos += moveVec * dir;		//���̌����Ɉړ��ʕ��A�ʒu���X�V
	}
}



//�ǔ�����
void	CameraGun::Chase(const K_Math::Vector3& targetPos)
{
	//���g�̈ʒu
	K_Math::Vector3 pos = { 0,0,0 };

	//�G�ƃJ�����K���Ƃ̋���
	K_Math::Vector3 targetVec = targetPos - pos;

	//�`�F�b�N����
	if (targetVec.x() == 0 && targetVec.y() == 0)
	{
		//�G�Ƃ̍��W�͂��łɂ����Ă���
		return;
	}

	//�ǔ�
	float angle = atan2f(targetVec.y(), targetVec.x());	//�p�x
	float speed = 3.0f;		//�X�s�[�h
	pos.x() += cos(K_Math::DegToRad(angle)) * speed;
	pos.y() += sin(K_Math::DegToRad(angle)) * speed;
}




//-------------
//������
//-------------
void	CameraGun::Initailize()
{
	//�X�e�[�^�X�̐ݒ�
	object.GetStatus().SetStatusData(
		Status::State::Non,
		K_Math::Vector3(0, 0, 0),
		K_Math::Vector3(0, 0, 0),
		K_Math::Vector3(1, 1, 1),
		Status::Direction::Right,
		1,
		0);
	
	//�����̏�����
	//�����̓f�t�H���g�Ő���������

	//�摜�̐ݒ�
	//�g�����͍��͕s��
	//object.GetImage()->

	//Easing�͏������̕K�v�͂Ȃ�
}

void	CameraGun::Render()
{

}

bool	CameraGun::HitEnemy()
{
	return true;
}