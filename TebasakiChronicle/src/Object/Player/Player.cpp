#include "Player.h"


//--------------------------------------------------------------
//�T�v:�v���C���[�̎���
//�����:�����
//--------------------------------------------------------------

//-----------------------------------------------
//�R���X�g���N�^
//-----------------------------------------------
Player::Player()
{

}

//-----------------------------------------------
//�f�X�g���N�^
//-----------------------------------------------
Player::~Player()
{

}

//������
void	Player::Initliaze()
{
	//�I�u�W�F�N�g�̏�����
	//-----�܂Ƃ߂ď�����������--------
	K_Math::Vector3 vec = { 0,0,0 };
	object.GetStatus()->GetPos() = vec;
	object.GetStatus()->GetAngle() = vec;
	object.GetStatus()->GetScale() = K_Math::Vector3(1,1,1);
	object.GetStatus()->GetDirection() = Status::Direction::Left;
	object.GetStatus()->GetAttackPoint() = 1.0f;
	object.GetStatus()->GetState() = Status::State::Jump;

	//�R���g���[���[�̏�����

	//�J�����K���̏�����
}

//�X�V
void	Player::UpDate()
{
	cameraGun.UpDate();			//�J�����K���̍X�V
	controller.UpDate();		//���͏����̍X�V
}

//�`��
void	Player::Render()
{

}