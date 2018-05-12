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
	CC::RemoveCollisionShape(&shape2);
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
	object.SetImage("Player", CST::LoadAndGetTexture("Player", "data/image/resource2.png"), true);
	object.GetImage().CreateCharaChip(K_Math::Box2D(0, 0, 32, 48), 5, 6, true);
	object.GetImage().CreateCharaChip(K_Math::Box2D(0, 0, 160, 48), 4, 6, false);
	object.GetImage().CreateCharaChip(K_Math::Box2D(0, 48, 32, 48), 10, 6, true);

	//Move�̏d�͂̐ݒ�
	object.GetMove().SetAddVec(2.f);
	object.GetMove().SetJumpPow(5.f);

	//�J�����K���̏�����
	cameraGun.Initailize();

	//���肶���̐ݒ�-------------------------------
	//�{�b�N�X�̌`�̐���
	shape = CC::CreateBoxShape(16, 24, 1);
	shape2 = CC::CreateBoxShape(15, 1, 1);

	//��������[�`]�ŃR���W�����⍄�̂��쐬
	cManager.CreateBaseCollisionData(shape, object.GetPos(), object.GetAngle(), true);	//�x�[�X
	cManager.CreateSubCollisionData(shape, CollisionMask::EnemyCollision | CollisionMask::TakeDamagePlayer, CollisionMask::PlayerCollision, object.GetPos()); //��_��
	cManager.CreateSubCollisionData(shape2, CollisionMask::Ground, CollisionMask::Non, K_Math::Vector3(0, -24, 0)); //����
	cManager.CreateSubCollisionData(shape2, CollisionMask::Ground, CollisionMask::Non, K_Math::Vector3(0, 24, 0)); //����

	//�R���W�����ɏ�����������
	cManager.SetSubCollisionUserData(0, &object.GetStatus());
}

//�X�V
void	Player::UpDate()
{
	
	//������[���N���A
	object.GetMove().GetMoveVec() = K_Math::Vector3(0, 0, 0);

	//�d�͓���
	object.GetMove().GravityOperation(cManager.CheckHitSubCollisionObejct(1));

	//�W�����v�{�^��������
	if (cManager.CheckHitSubCollisionObejct(1) &&
		INPUT::IsPressButton(VpadIndex::Pad0, K_Input::VpadButton::R1))
	{
		object.GetMove().JumpOperation();
	}

	//�B�e�{�^���������ƃJ������O���Ɏˏo����
	if (INPUT::IsPressButton(VpadIndex::Pad0,K_Input::VpadButton::L1))
	{
		cameraGun.SetDirection(object.GetDirection());	//�����𓯊�������
		cameraGun.SetCameraGun(true);
	}

	//�B�e�{�^���𗣂�
	if (INPUT::IsReaveButton(VpadIndex::Pad0,K_Input::VpadButton::L1))
	{
		//�J�����}�[�J�[���v���C���[�̈ʒu�ɖ߂�
		cameraGun.SetCameraGun(false);
	}

	//���͂ɉ����Č�����ς���
	ChangeDir();

	//�J�����K���̍X�V
	cameraGun.UpDate(object.GetPos());
	
	//�R���g���[���[�̍X�V
	controller.UpDate(object.GetMove());
	
	//�R���W�����𓮂���
	cManager.MoveBaseCollision(object.GetMoveVec(), object.GetDirection(), false);
	//�v���C���[�ƃR���W�����̍��W�𓯊�������
	object.GetPos() = cManager.GetBaseCollisionObjectPosition();
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
		if ((K_Math::DegToRad(-90) < stickAngle) && (stickAngle < K_Math::DegToRad(90)))
		{
			object.SetDirection(Status::Direction::Right);
		}
		else
		{
			object.SetDirection(Status::Direction::Left);
		}

		object.GetImage().ChangeAnimationPattern(2, true);
	}
	else
	{
		object.GetImage().ChangeAnimationPattern(0, true);
	}
}


//�J�����K����O�ɔ�΂�
void	Player::ShotCameraGun()
{
	//�B�e�{�^���������ƃJ������O���Ɏˏo����
	if (INPUT::IsPressButton(VpadIndex::Pad0,K_Input::VpadButton::L1))
	{
		cameraGun.SetDirection(object.GetDirection());	//�����𓯊�������
		cameraGun.SetCameraGun(true);
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
		cameraGun.SetCameraGun(false);
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