#pragma once
#include "../src/BaseClass/Move.h"
#include "InputGLFW.h"

//--------------------------------------------------------------
//�L�����N�^�[�R���g���[���[
//�T�v:�L�����𑀍삷��
//�����:�����
//--------------------------------------------------------------
class CharaController
{
public:
	CharaController();
	CharaController(K_Input::InputGLFW* input);
	~CharaController();

	void	UpDate();		//�X�V

private:
	//�萔-------------------
	const float Friction = 0.9f;

	//�ϐ�-------------------
	Move*	move;					//�ړ�
	K_Input::InputGLFW*	input;		//���̓{�^��
	K_Math::Vector3 moveVec;		//�ړ���
};


