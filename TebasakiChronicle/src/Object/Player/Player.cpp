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
	object.GetStatus().SetStatusData(
		Status::State::Active,
		K_Math::Vector3(0, 0, 0),
		K_Math::Vector3(0, 0, 0),
		K_Math::Vector3(1, 1, 1),
		Status::Direction::Right,
		1,
		0);
	object.GetMove().SetAddVec(2.f);

	//�R���g���[���[�̏�����
	controller.SetInput();

	//�J�����K���̏�����
	cameraGun.Initailize();

	//�摜�Ǘ��̏�����
	object.SetImage("resource2", CST::GetTexture("resource2"), true);
	object.GetImage().CreateCharaChip(K_Math::Box2D(0, 0, 32, 48), 6, 10.f, true);
}

//�X�V
void	Player::UpDate()
{
	cameraGun.UpDate();			//�J�����K���̍X�V
	controller.UpDate();		//���͏����̍X�V
	object.GetImage().Animation();
}

//�`��
void	Player::Render()
{
	object.GetImage().ImageDraw3D(object.GetPos(), object.GetAngle(), object.GetScale(), object.GetDirection());
}