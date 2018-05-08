#include "CharaController.h"


//------------------------------------------------------------
//�T�v:�L�����R���g���[���[�̎���
//�����:�����
//------------------------------------------------------------


//-------------------------------------------------
//�R���X�g���N�^
//-------------------------------------------------
CharaController::CharaController()
	
{

}

//-------------------------------------------------
//�f�X�g���N�^
//-------------------------------------------------
CharaController::~CharaController()
{

}


//-------------------------------------------------
//�X�V����
//-------------------------------------------------
void	CharaController::UpDate()
{
	//���X�e�B�b�N�̓|��Ă���[��
	float stickDepth = INPUT::GetStickPower(VpadIndex::Pad0,K_Input::VpadStick::L);
	//�E������0�x�Ƃ�����]�x
	float stickAngle = INPUT::GetStickRotation(VpadIndex::Pad0,K_Input::VpadStick::L);

	moveVec->x() += cosf(stickAngle) * stickDepth;	//�X�e�B�b�N�̊p�x�����ɓ|�����������i��
	moveVec->y() += sinf(stickAngle) * stickDepth;

	//�X�����Ȃ��ꍇ�́A�����Ȃ�(���C�ł������~�܂�悤�ɂ���)
	if (stickDepth == 0)
	{
		moveVec->x() *= Friction;
		moveVec->y() *= Friction;
	}
	//INPUT::Run(VpadIndex::Pad0);				//���͏����𓮂���
}




//�ړ��x�N�g�����Z�b�g����
void	CharaController::SetMoveVec(K_Math::Vector3* vec)
{
	this->moveVec = vec;
}

//�ړ��x�N�g�������炢�A���삷��
void	CharaController::UpDate(K_Math::Vector3& vec)
{
	//���X�e�B�b�N�̓|��Ă���[��
	float stickDepth = INPUT::GetStickPower(VpadIndex::Pad0,K_Input::VpadStick::L);
	//�E������0�x�Ƃ�����]�x
	float stickAngle = INPUT::GetStickRotation(VpadIndex::Pad0,K_Input::VpadStick::L);

	//�������݂̂̈ړ�
	if (stickDepth != 0)
	{
		//�X�e�B�b�N�̊p�x�����ɓ|�����������i��
		vec.x() = cosf(stickAngle) * stickDepth * 0.5f;
	}
	else
	//�X�����Ȃ��ꍇ�́A�����Ȃ�(���C�ł������~�܂�悤�ɂ���)
	{
		vec.x() *= Friction;
		vec.x() = 0.0f;
	}
	vec.y() = 0;
	INPUT::Run(VpadIndex::Pad0);				//���͏����𓮂���
}