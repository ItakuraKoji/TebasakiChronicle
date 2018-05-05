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
	delete input;
	delete physics;
	delete collision;
	delete targetTag;
}

//������
void	Player::Initliaze()
{
	//�I�u�W�F�N�g�̏�����
	//-----�܂Ƃ߂ď�����������--------
	K_Math::Vector3 vec = { 0,0,0 };
	object.GetStatus()->GetPos() = vec;
	object.GetStatus()->GetAngle() = vec;
	object.GetStatus()->GetScale() = { 1,1,1 };
	object.GetStatus()->GetDirection() = Status::Direction::Left;
	object.GetStatus()->GetAttackPoint() = 1.0f;
	object.GetStatus()->GetLife() = 1.0f;
	object.GetStatus()->GetState() = Status::State::Jump;
	

	//�R���g���[���[�̏�����
	controller.SetInput(input);
	//�J�����K���̏�����
	cameraGun.Initailize();

	//���肶���̐ݒ�-------------------------------
	//����������BulletPhysics
	physics = new K_Physics::BulletPhysics();

	//�{�b�N�X�̌`�̐���
	shape = physics->CreateBoxShape(10, 10, 1);

	//��������[�`]�ŃR���W�����⍄�̂��쐬
	//K_Physics::RigidBodyData*	rigid = physics->CreateRigidBody(shape, 1.0f, false, 1);
	collision = physics->CreateCollisionObject(shape, false, 1);

	//�R���W�����ɏ�����������
	collision->tag.tagIndex = 2;
	collision->tag.tagName = "Player";
}

//�X�V
void	Player::UpDate()
{
	//�W�����v�{�^��������
	if (input->GetPad(K_Input::VpadIndex::Pad0)->IsPressButton(K_Input::VpadButton::R1))
	{
		std::cout << "�W�����v�{�^��" << std::endl;
	}

	//�B�e�{�^��������
	if (input->GetPad(K_Input::VpadIndex::Pad0)->IsStayButton(K_Input::VpadButton::L1))
	{
		cameraGun.active = true;
		K_Math::Vector3 dir;
		if (object.GetDirection() == Status::Direction::Left)
		{
			dir = K_Math::Vector3(-2, 0, 0);
		}
		else
		{
			dir = K_Math::Vector3(2, 0, 0);
		}
		//�J�����}�[�J�[��O�ɔ�΂�
		cameraGun.MoveDir(dir);
	}

	//�B�e�{�^���𗣂�
	if (input->GetPad(K_Input::VpadIndex::Pad0)->IsReaveButton(K_Input::VpadButton::L1))
	{
		//�J�����}�[�J�[���v���C���[�̈ʒu�ɖ߂�
		cameraGun.object.SetMoveVec(K_Math::Vector3(0, 0, 0));
		cameraGun.MoveDir(K_Math::Vector3(0, 0, 0));
		cameraGun.active = false;	//��\��
	}

	//���X�e�B�b�N�̓|��Ă���[��
	float stickDepth = input->GetPad(K_Input::VpadIndex::Pad0)->GetStickPower(K_Input::VpadStick::L);
	//�E������0�x�Ƃ�����]�x
	float stickAngle = input->GetPad(K_Input::VpadIndex::Pad0)->GetStickRotation(K_Input::VpadStick::L);

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
	}
	//�J�����K���̍X�V
	if (!cameraGun.active)
	{
		//�v���C���[�̈ʒu�ɏ�ɂ��Ă���
		cameraGun.MoveDir(object.GetMoveVec());
		cameraGun.object.GetPos() += cameraGun.object.GetMoveVec();
		cameraGun.object.GetPos() = object.GetPos();
		//-------------------------------------------
		//�R���W�����̈ʒu��ݒ�
		cameraGun.collision->SetCollisionPosition(object.GetPos());
	}
	else
	{
		cameraGun.UpDate();
	}
	std::cout << "�J�����R���W����" << cameraGun.collision->GetCollisionPosition().x() << std::endl;

	
	//�R���g���[���[�̍X�V
	controller.UpDate(object.GetMoveVec());

	//�v���C���[�̈ړ�
	//�ʒu�̈ړ�
	if (object.GetMoveVec().x() != 0)
	{
		object.GetPos() += object.GetMoveVec();
	}

	physics->MoveCharacter(collision, object.GetMoveVec());
	physics->Run();
}

//�`��
void	Player::Render()
{
	cameraGun.Render();
}


//InputClass�̎擾����
void	Player::GetInputClass(K_Input::InputClass* input)
{
	this->input = input;
}




