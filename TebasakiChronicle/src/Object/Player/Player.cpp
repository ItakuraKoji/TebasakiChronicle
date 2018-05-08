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
	CC::RemoveCollisionShape(&shape);
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
		0
	);

	//�摜�̐���
	object.CreateImg("Player", "./data/image/player.tga");
	object.GetImage().CreateCharaChip(K_Math::Box2D(0, 0, 32, 48), 5, 6, true);
	object.GetImage().CreateCharaChip(K_Math::Box2D(0, 0, 160, 48), 4, 6, false);
	object.GetImage().CreateCharaChip(K_Math::Box2D(0, 48, 32, 48), 10, 6, true);

	//Move�̏d�͂̐ݒ�
	object.GetMove().SetAddVec(2.f);
	object.GetMove().SetGravity(-0.04f);

	//�J�����K���̏�����
	cameraGun.Initailize();

	//���肶���̐ݒ�-------------------------------
	//�{�b�N�X�̌`�̐���
	shape = CC::CreateBoxShape(10, 10, 1);

	//��������[�`]�ŃR���W�����⍄�̂��쐬
	cManager.CreateBaseCollisionData(shape, object.GetPos(), object.GetAngle(), true);
	cManager.CreateSubCollisionData(shape, CollisionMask::EnemyCollision | CollisionMask::TakeDamagePlayer, CollisionMask::PlayerCollision, object.GetPos());

	//�R���W�����ɏ�����������
	cManager.SetSubCollisionTug(0, &object.GetStatus());
}

//�X�V
void	Player::UpDate()
{
	//�W�����v�{�^��������
	if (INPUT::IsPressButton(VpadIndex::Pad0, K_Input::VpadButton::R1))
	{
		object.GetMove().JumpOperation();
	}

	//�B�e�{�^���������ƃJ������O���Ɏˏo����
	if (INPUT::IsPressButton(VpadIndex::Pad0,K_Input::VpadButton::L1))
	{
		cameraGun.SetDirection(object.GetDirection());	//�����𓯊�������
		cameraGun.SetMoveVec(true);
		cameraGun.object.SetState(Status::State::Active);
	}

	//�B�e�{�^���𗣂�
	if (INPUT::IsReaveButton(VpadIndex::Pad0,K_Input::VpadButton::L1))
	{
		//�J�����}�[�J�[���v���C���[�̈ʒu�ɖ߂�
		cameraGun.SetMoveVec(false);
		cameraGun.object.SetState(Status::State::Non);
	}
	

	if (object.GetMove().GetMoveVec().y() != 0)
	{
		object.GetImage().ChangeAnimationPattern(1);
	}

	//���͂ɉ����Č�����ς���
	ChangeDir();

	//�J�����K���̍X�V
	cameraGun.UpDate(object.GetPos());
	
	//�R���g���[���[�̍X�V
	controller.UpDate(object.GetMoveVec());

	//�d�͓���
	object.GetMove().GravityOperation();
	
	//�R���W�����𓮂���
	cManager.MoveBaseCollision(object.GetMoveVec(), object.GetDirection(), true);

	object.GetPos() += object.GetMoveVec();
	//�v���C���[�ƃR���W�����̍��W�𓯊�������
	cManager.GetBaseCollisionObjectPosition() = object.GetPos();
	//�A�j���[�V����
	object.GetImage().Animation();
}



//�`��
void	Player::Render()
{
	cameraGun.Render();
	object.GetImage().ImageDraw3D(object.GetPos(), object.GetAngle(), object.GetScale(), object.GetDirection());
}






//���͂ɉ����Č�����ς���
void	Player::ChangeDir()
{
	//���X�e�B�b�N�̓|��Ă���[��
	float stickDepth = INPUT::GetStickPower(VpadIndex::Pad0,K_Input::VpadStick::L);
	//�E������0�x�Ƃ�����]�x
	float stickAngle = INPUT::GetStickRotation(VpadIndex::Pad0,K_Input::VpadStick::L);

	if (stickDepth != 0)
	{
		if (K_Math::DegToRad(-90) < stickAngle && stickAngle < K_Math::DegToRad(90))
		{
			object.SetDirection(Status::Direction::Right);
		}
		else
		{
			object.SetDirection(Status::Direction::Left);
		}

		object.GetImage().ChangeAnimationPattern(2);
	}
	else
	{
		object.GetImage().ChangeAnimationPattern(0);
	}
}


//�J�����K����O�ɔ�΂�
void	Player::ShotCameraGun()
{
	//�B�e�{�^���������ƃJ������O���Ɏˏo����
	if (INPUT::IsPressButton(VpadIndex::Pad0,K_Input::VpadButton::L1))
	{
		cameraGun.SetDirection(object.GetDirection());	//�����𓯊�������
		cameraGun.SetMoveVec(true);
		cameraGun.object.SetState(Status::State::Active);
	}
}

//�J�����K�������ɖ߂�
void	Player::ReverseCameraGun()
{
	//�B�e�{�^���𗣂�
	if (INPUT::IsReaveButton(VpadIndex::Pad0,K_Input::VpadButton::L1))
	{
		//�J�����}�[�J�[���v���C���[�̈ʒu�ɖ߂�
		cameraGun.SetMoveVec(false);
		cameraGun.object.SetState(Status::State::Non);
	}
}


//�W�����v����
void	Player::Jump()
{
	if (INPUT::IsPressButton(VpadIndex::Pad0,K_Input::VpadButton::R1))
	{
		object.GetMove().JumpOperation();
	}
}