#pragma once
#include "K_Math\MyMathFanctions.h"

//-----------------------------------------------------
//Move�N���X
//�T�v:����ʂ����W�ɗ^����
//�����:�����
//-----------------------------------------------------
class Move
{
public:
	Move();
	Move(const K_Math::Vector3& vec,float jumpPow, float fallSpeed, float gravity);
	~Move();

	//�ݒ菈��
	void	SetJumpPow(float jumpPow);
	void	SetFallSpeed(float fallSpeed);
	void	SetGravity(float gravity);

	void	SetMoveDate(
		const K_Math::Vector3& moveVec, const float& jumpPow,
		const float& fallSpeed, const float& gravity);

	//�擾����
	float	GetJumpPow();
	float	GetFallSpeed();
	float	GetGravity();

	//����
	void	GravityOperation();	//�d�͓���
	void	MovingOperation();	//�ړ�����
	void	JumpOperation();	//�W�����v����

private:
	K_Math::Vector3		moveVec;		//1�t���[���œ�����
	float	jumpPower;		//�W�����v��
	float	fallSpeed;		//�������x
	float	gravity;		//�d�͉����x
};