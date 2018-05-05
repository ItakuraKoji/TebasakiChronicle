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
CharaController::CharaController(K_Input::InputClass* input)
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
	//���X�e�B�b�N�̓|��Ă���[��
	float stickDepth = input->GetPad(K_Input::VpadIndex::Pad0)->GetStickPower(K_Input::VpadStick::L);
	//�E������0�x�Ƃ�����]�x
	float stickAngle = input->GetPad(K_Input::VpadIndex::Pad0)->GetStickRotation(K_Input::VpadStick::L);

	moveVec->x() += cosf(stickAngle) * stickDepth;	//�X�e�B�b�N�̊p�x�����ɓ|�����������i��
	moveVec->y() += sinf(stickAngle) * stickDepth;

	//�X�����Ȃ��ꍇ�́A�����Ȃ�(���C�ł������~�܂�悤�ɂ���)
	if (stickDepth == 0)
	{
		moveVec->x() *= Friction;
		moveVec->y() *= Friction;
	}
	input->Run();				//���͏����𓮂���
}



//InputClass�̐ݒ�
//�{���́AInput�̓Q�[���ݒ�ōs��
void	CharaController::SetInput(K_Input::InputClass* in)
{
	input = in;	//�擾

	//�R���g���[���[���쐬
	input->AddGamePad(K_Input::VpadIndex::Pad0);

	//�L�[�R���t�B�O�����邱�Ƃœ��͂��󂯎��
	//�X�e�B�b�N��[A,B,X,Y,L1,R1]��[Z,X,C,V,A,S]�ƘA��������
	input->GetPad(K_Input::VpadIndex::Pad0)->SetButtonConfig(K_Input::VpadButton::A, K_Input::JoyButton::Button0, K_Input::Key::Z);
	input->GetPad(K_Input::VpadIndex::Pad0)->SetButtonConfig(K_Input::VpadButton::B, K_Input::JoyButton::Button1, K_Input::Key::X);
	input->GetPad(K_Input::VpadIndex::Pad0)->SetButtonConfig(K_Input::VpadButton::X, K_Input::JoyButton::Button2, K_Input::Key::C);
	input->GetPad(K_Input::VpadIndex::Pad0)->SetButtonConfig(K_Input::VpadButton::Y, K_Input::JoyButton::Button3, K_Input::Key::V);
	input->GetPad(K_Input::VpadIndex::Pad0)->SetButtonConfig(K_Input::VpadButton::L1, K_Input::JoyButton::Button4, K_Input::Key::A);
	input->GetPad(K_Input::VpadIndex::Pad0)->SetButtonConfig(K_Input::VpadButton::R1, K_Input::JoyButton::Button5, K_Input::Key::S);

	//���X�e�B�b�N��Arrow�L�[��A��������
	input->GetPad(K_Input::VpadIndex::Pad0)->SetAxisConfig(K_Input::VpadAxis::Axis0, K_Input::JoyAxis::Axis0, K_Input::Key::ArrowRight, K_Input::Key::ArrowLeft);
	input->GetPad(K_Input::VpadIndex::Pad0)->SetAxisConfig(K_Input::VpadAxis::Axis1, K_Input::JoyAxis::Axis1, K_Input::Key::ArrowUp, K_Input::Key::ArrowDown);

	//���z�Q�[���p�b�h�̎��Ɋ��蓖�ăX�e�B�b�N���쐬
	input->GetPad(K_Input::VpadIndex::Pad0)->SetStickConfig(K_Input::VpadStick::L, K_Input::VpadAxis::Axis0, K_Input::VpadAxis::Axis1);
}



//�ړ��x�N�g�����Z�b�g����
void	CharaController::SetMoveVec(K_Math::Vector3* vec)
{
	this->moveVec = vec;
}

void	CharaController::UpDate(K_Math::Vector3& vec)
{
	//���X�e�B�b�N�̓|��Ă���[��
	float stickDepth = input->GetPad(K_Input::VpadIndex::Pad0)->GetStickPower(K_Input::VpadStick::L);
	//�E������0�x�Ƃ�����]�x
	float stickAngle = input->GetPad(K_Input::VpadIndex::Pad0)->GetStickRotation(K_Input::VpadStick::L);

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
		vec.y() *= Friction;

		vec.x() = 0;
		vec.y() = 0;
	}

	input->Run();				//���͏����𓮂���
}