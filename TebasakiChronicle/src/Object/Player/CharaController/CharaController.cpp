#include "CharaController.h"


//------------------------------------------------------------
//�T�v:�L�����R���g���[���[�̎���
//�����:�����
//------------------------------------------------------------


//-------------------------------------------------
//�R���X�g���N�^
//-------------------------------------------------
CharaController::CharaController()
	: input(nullptr)
{

}
CharaController::CharaController(K_Input::InputGLFW* input)
	: input(input)
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
	//���X�e�B�b�N(�L�[�{�[�h�ł�Arrow�L�[)
	//�����̑傫���ƍ��E(-1.0f�`1.0f)���킩��
	float value = input->GetStickState(K_Input::VpadStick::L);	
	//�~�܂�Ƃ���[value]��[0]�̂Ƃ�
	if (value == 0) { moveVec.x() *= Friction; }

	//�W�����v�{�^��������
	if (input->isPressButton(K_Input::VpadButton::R1))
	{
		move->JumpOperation();	//�W�����v����
	}

	//�B�e�{�^��������(�J�����}�[�J�[��O�ɔ�΂�)
	if (input->isStayButton(K_Input::VpadButton::L1))
	{

	}

	move->GravityOperation();	//�d�͓���

	input->Run();				//���͏����𓮂���
}