#pragma once
#include "../src/BaseClass/Input/Input.h"
#include "../src/BaseClass/Move.h"

//--------------------------------------------------------------
//�L�����N�^�[�R���g���[���[
//�T�v:�L�����𑀍삷��
//�����:�����
//--------------------------------------------------------------
class CharaController
{
public:
	CharaController();
	~CharaController();



	//1:�Q�Ƃ����ړ��x�N�g���𗘗p���āA���͑�����s��
	void	UpDate(K_Math::Vector3& vec);

	//1:�ŏ��ɓ������x�N�g����ݒ肵�Ă��炤
	//2:���̂��Ƃ�UpDate()�Őݒ肵���x�N�g���𓮂���
	void	SetMoveVec(K_Math::Vector3* vec);
	void	UpDate();

private:
	//�萔-------------------
	float Friction = 0.f;

	//�ϐ�-------------------
	Move*					move;		//�ړ�
	K_Math::Vector3*		moveVec;	//�ړ���
};


