#pragma once
#include "K_Input/InputClass.h"
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
	CharaController(K_Input::InputClass* input);
	~CharaController();

	//InputClass�̐ݒ�
	void	SetInput(K_Input::InputClass* input);

	//1:�Q�Ƃ����ړ��x�N�g���𗘗p���āA���͑�����s��
	void	UpDate(K_Math::Vector3& vec);

	//1:�ŏ��ɓ������x�N�g����ݒ肵�Ă��炤
	//2:���̂��Ƃ�UpDate()�Őݒ肵���x�N�g���𓮂���
	void	SetMoveVec(K_Math::Vector3* vec);
	void	UpDate();

private:
	//�萔-------------------
	const float Friction = 0.9f;

	//�ϐ�-------------------
	Move*					move;		//�ړ�
	K_Input::InputClass*	input;		//���̓{�^��
	K_Math::Vector3*		moveVec;	//�ړ���
};


