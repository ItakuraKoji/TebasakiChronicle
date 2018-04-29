#pragma once
#include "K_Math/MyMathFanctions.h"

//---------------------------------------------------------------------
//�X�e�[�^�X�N���X
//�T�v:�X�e�[�^�X��ێ����Ă���
//�����:�����
//---------------------------------------------------------------------
class Status
{
public:
	Status();
	~Status();

public:
	//����
	enum Direction
	{
		Left = 90,
		Right = 180,
	};

	//���
	enum State
	{
		Walk,
		Run,
		Jump
	};

public:
	//�ݒ菈��
	void	SetStatusData(
		const State& state,const K_Math::Vector3& pos,
		const K_Math::Vector3& angle,const K_Math::Vector3& scale,
		const Direction& dir,const float& attackPoint
	);


	//�擾����
	State&				GetState();
	K_Math::Vector3&	GetPos();
	K_Math::Vector3&	GetAngle();
	K_Math::Vector3&	GetScale();
	Direction&			GetDirection();
	float&				GetAttackPoint();

private:
	State				state;		//���
	K_Math::Vector3		pos;		//���W
	K_Math::Vector3		angle;		//�X��
	K_Math::Vector3		scale;		//�g��k��
	Direction			direction;	//����
	float				attackPoint;//�U����
};