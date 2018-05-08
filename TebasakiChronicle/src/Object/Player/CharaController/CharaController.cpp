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
	//�R���g���[���[�����
	input->AddGamePad(K_Input::VpadIndex::Pad0);

	//���X�e�B�b�N�̓|��Ă���[��
	float stickDepth = input->GetPad(K_Input::VpadIndex::Pad0)->GetStickPower(K_Input::VpadStick::L);
	//�E������0�x�Ƃ�����]�x
	float stickAngle = input->GetPad(K_Input::VpadIndex::Pad0)->GetStickRotation(K_Input::VpadStick::L);

	K_Math::Vector3 moveVec = { 0,0,0 };
	moveVec.x() += cosf(stickAngle) * stickDepth * move->GetAddVec();	//�X�e�B�b�N�̊p�x�����ɓ|�����������i��

	//�X�����Ȃ��ꍇ�͓�����~����
	if (stickDepth == 0)
	{
		moveVec.x() = 0.f;
	}

	//move�N���X��moveVec�Ɉړ��ʂ����Z����
	move->GetMoveVec() = moveVec;

	//�W�����v�{�^��������
	if (input->GetPad(K_Input::VpadIndex::Pad0)->IsPressButton(K_Input::VpadButton::R1))
	{
		move->JumpOperation();	//�W�����v����
	}

	//�B�e�{�^��������
	if (input->GetPad(K_Input::VpadIndex::Pad0)->IsStayButton(K_Input::VpadButton::L1))
	{
		//�J�����}�[�J�[��O�ɔ�΂�
	}

	//move->GravityOperation();	//�d�͓���

	input->Run();				//���͏����𓮂���
}



//InputClass�̐ݒ�
//�{���́AInput�̓Q�[���ݒ�ōs��
void	CharaController::SetInput()
{
	//�R���g���[���[���쐬
	input->AddGamePad(K_Input::VpadIndex::Pad0);

	//�L�[�R���t�B�O�����邱�Ƃœ��͂��󂯎��
	//�X�e�B�b�N��[A,B,X,Y]��[Z,X,C,V]�ƘA��������
	input->GetPad(K_Input::VpadIndex::Pad0)->SetButtonConfig(K_Input::VpadButton::A, K_Input::JoyButton::Button0, K_Input::Key::Z);
	input->GetPad(K_Input::VpadIndex::Pad0)->SetButtonConfig(K_Input::VpadButton::B, K_Input::JoyButton::Button1, K_Input::Key::X);
	input->GetPad(K_Input::VpadIndex::Pad0)->SetButtonConfig(K_Input::VpadButton::X, K_Input::JoyButton::Button2, K_Input::Key::C);
	input->GetPad(K_Input::VpadIndex::Pad0)->SetButtonConfig(K_Input::VpadButton::Y, K_Input::JoyButton::Button3, K_Input::Key::V);

	//���X�e�B�b�N��Arrow�L�[��A��������
	input->GetPad(K_Input::VpadIndex::Pad0)->SetAxisConfig(K_Input::VpadAxis::Axis0, K_Input::JoyAxis::Axis0, K_Input::Key::ArrowRight, K_Input::Key::ArrowLeft);
	input->GetPad(K_Input::VpadIndex::Pad0)->SetAxisConfig(K_Input::VpadAxis::Axis1, K_Input::JoyAxis::Axis1, K_Input::Key::ArrowUp, K_Input::Key::ArrowDown);

	//���z�Q�[���p�b�h�̎��Ɋ��蓖�ăX�e�B�b�N���쐬
	input->GetPad(K_Input::VpadIndex::Pad0)->SetStickConfig(K_Input::VpadStick::L, K_Input::VpadAxis::Axis0, K_Input::VpadAxis::Axis1);
}