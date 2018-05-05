#include "Status.h"

//-----------------------------------------------------------------
//�X�e�[�^�X�̎���
//�����:�����
//-----------------------------------------------------------------

//---------------------------------------------------
//�R���X�g���N�^
//---------------------------------------------------
Status::Status()
{

}

//---------------------------------------------------
//�f�X�g���N�^
//---------------------------------------------------
Status::~Status()
{

}


//---------------------------------------------------
//�ݒ菈��
//---------------------------------------------------
void	Status::SetStatusData(const State& state, const K_Math::Vector3& pos,
	const K_Math::Vector3& angle, const K_Math::Vector3& scale,
	const Direction& dir, const float& attackPoint,const int& life)
{
	this->state = state;
	this->pos = pos;
	this->angle = angle;
	this->scale = scale;
	this->direction = dir;
	this->attackPoint = attackPoint;
	this->life = life;
}

//---------------------------------------------------
//�擾����
//---------------------------------------------------
//��Ԃ̎擾
Status::State&	Status::GetState()
{
	return state;
}

//�ʒu�̎擾
K_Math::Vector3&	Status::GetPos()
{
	return pos;
}

//�X���̎擾
K_Math::Vector3&	Status::GetAngle()
{
	return angle;
}

//�g��k���̎擾
K_Math::Vector3&	Status::GetScale()
{
	return scale;
}

//�ړ��ʂ̎擾
K_Math::Vector3&	Status::GetMoveVec()
{
	return moveVec;
}

//�����̎擾
Status::Direction&	Status::GetDirection()
{
	return direction;
}

//�U���͂̎擾
float&				Status::GetAttackPoint()
{
	return attackPoint;
}

//�̗͂̎擾
int&				Status::GetLife()
{
	return life;
}