#pragma once
#include "../src/BaseClass/Move.h"
#include "K_Input/InputClass.h"

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

	void	SetInput();		//InputClass�̐ݒ�
	void	UpDate();		//�X�V

private:
	//�萔-------------------
	//const float Friction = 0.9f;

	//�ϐ�-------------------
	Move*	move;					//�ړ�
	K_Input::InputClass*	input;	//���̓{�^��
};


