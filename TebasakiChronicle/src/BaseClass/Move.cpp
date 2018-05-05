#include "Move.h"

//------------------------------------------------------
//�T�v:Move�N���X�̏������e
//�����:�����
//------------------------------------------------------


//------------------------------------------------------
//�R���X�g���N�^
//------------------------------------------------------
Move::Move() : moveVec(K_Math::Vector3(0,0,0)),jumpPower(0.0f), 
	fallSpeed(1.0f), gravity(-9.8f)
{

}
Move::Move(const K_Math::Vector3& vec,float jumpPow, float fallSpeed, float gravity)
	: moveVec(vec),jumpPower(jumpPow),fallSpeed(fallSpeed),gravity(gravity)
{

}

//------------------------------------------------------
//�f�X�g���N�^
//------------------------------------------------------
Move::~Move()
{

}


//------------------------------------------------------
//�ݒ菈��
//------------------------------------------------------
//�W�����v�͂̐ݒ�
void	Move::SetJumpPow(float jumpPow)
{
	this->jumpPower = jumpPow;
}

//�������x�̐ݒ�
void	Move::SetFallSpeed(float fallSpeed)
{
	this->fallSpeed = fallSpeed;
}

//�d�͉����x�̐ݒ�
void	Move::SetGravity(float gravity)
{
	this->gravity = gravity;
}

//�f�[�^�̐ݒ�
void	Move::SetMoveDate(const K_Math::Vector3& moveVec, const float& jumpPow,
	const float& fallSpeed, const float& gravity)
{
	this->moveVec = moveVec;
	this->jumpPower = jumpPow;
	this->fallSpeed = fallSpeed;
	this->gravity = gravity;
}


//------------------------------------------------------
//�擾����
//------------------------------------------------------
//�W�����v�͂̎擾
float	Move::GetJumpPow()
{
	return jumpPower;
}

//�������x�̎擾
float	Move::GetFallSpeed()
{
	return fallSpeed;
}

//�d�͉����x�̐ݒ�
float	Move::GetGravity()
{
	return gravity;
}


//------------------------------------------------------
//����
//------------------------------------------------------
//�d�͓���
void	Move::GravityOperation()
{
	moveVec.y() += fallSpeed;
	fallSpeed += gravity;
}

//�ړ�����
void	Move::MovingOperation()
{
	K_Math::Vector3	vectorArg;	//�����Ŏ󂯂��Ƃ����ϐ�

	//1�t���[���œ����ʂ��v���X���Ă���
	moveVec += vectorArg;
}

//�W�����v����
void	Move::JumpOperation()
{
	fallSpeed = jumpPower;
}