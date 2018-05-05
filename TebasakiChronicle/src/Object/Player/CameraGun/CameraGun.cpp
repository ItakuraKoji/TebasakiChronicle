#include "CameraGun.h"

//---------------------------------------------------------------
//�T�v:�J�����K���̎���
//�����:�����
//---------------------------------------------------------------

//-------------------------------------------------
//�R���X�g���N�^
//-------------------------------------------------
CameraGun::CameraGun()
{

}

CameraGun::CameraGun(const K_Math::Vector3& vec)
	: moveVec(vec)
{
	//�X�e�[�^�X�̐ݒ�
	object.GetStatus()->SetStatusData(
		Status::State::Walk,
		K_Math::Vector3(0, 0, 0),
		K_Math::Vector3(0, 0, 0),
		K_Math::Vector3(1, 1, 1),
		Status::Direction::Left,
		1.0f,
		1);

	//����������BulletPhysics
	physics = new K_Physics::BulletPhysics();

	//�{�b�N�X�̌`�̐���
	shape = physics->CreateSphereShape(10);

	//��������[�`]�ŃR���W�����⍄�̂��쐬
	//K_Physics::RigidBodyData*	rigid = physics->CreateRigidBody(shape, 1.0f, false, 1);
	collision = physics->CreateCollisionObject(shape, false, 1);

	//�R���W�����ɏ�����������
	collision->tag.tagIndex = 1;
	collision->tag.tagName = "CameraGun";
}

//-------------------------------------------------
//�f�X�g���N�^
//-------------------------------------------------
CameraGun::~CameraGun()
{
	if (shape != nullptr) { delete shape; shape = nullptr; }
	if (collision != nullptr) { delete collision; collision = nullptr; }
	if (physics != nullptr) { delete physics; physics = nullptr; }

}


//�X�V����
void	CameraGun::UpDate()
{	
	//�J�������L�����ǂ���
	//if (!active) { return; }

	
	if (HitCheck("Enemy"))
	{
		//�ǐՏ���
		K_Math::Vector3* targetPos = (K_Math::Vector3*)targetTag->userData;
		Chase(*targetPos);
	}
	else
	{
		//�ړ��ʂ��Z�b�g����
		object.SetMoveVec(moveVec);
	}

	//�J�����K���̈ړ�
	physics->MoveCharacter(collision, object.GetMoveVec());
	object.GetPos() += object.GetMoveVec();

	physics->Run();	//��������𑖂点��

}



//�ǔ�����
void	CameraGun::Chase(const K_Math::Vector3& targetPos)
{
	//�G�ƃJ�����K���Ƃ̋���
	K_Math::Vector3 targetVec = targetPos - object.GetStatus()->GetPos();

	//�`�F�b�N����
	if (targetVec.x() == 0 && targetVec.y() == 0)
	{
		//�G�Ƃ̍��W�͂��łɂ����Ă���
		return;
	}

	//�ǔ�
	float angle = atan2f(targetVec.y(), targetVec.x());	//�p�x
	float speed = 3.0f;		//�X�s�[�h

	object.GetMoveVec().x() = cosf(K_Math::DegToRad(angle)) * speed;
}




//-------------
//������
//-------------
void	CameraGun::Initailize()
{
	//�X�e�[�^�X�̐ݒ�
	object.GetStatus()->SetStatusData(
		Status::State::Walk,
		K_Math::Vector3(0, 0, 0),
		K_Math::Vector3(0, 0, 0),
		K_Math::Vector3(1, 1, 1),
		Status::Direction::Left,
		1.0f,
		1);
	
	//�����̏�����
	//�����̓f�t�H���g�Ő���������

	//�摜�̐ݒ�
	//�g�����͍��͕s��
	//object.GetImage()->

	//����������BulletPhysics
	physics = new K_Physics::BulletPhysics();

	//�{�b�N�X�̌`�̐���
	shape = physics->CreateSphereShape(10);

	//��������[�`]�ŃR���W�����⍄�̂��쐬
	//K_Physics::RigidBodyData*	rigid = physics->CreateRigidBody(shape, 1.0f, false, 1);
	collision = physics->CreateCollisionObject(shape, false, 1);

	//�R���W�����ɏ�����������
	collision->tag.tagIndex = 1;
	collision->tag.tagName = "CameraGun";

	active = false;
}

void	CameraGun::Render()
{
	if (!active) { return; }
}

//�����Ă�������Ɉړ�
void	CameraGun::MoveDir(const K_Math::Vector3& vec)
{
	moveVec = vec;	//�����ł͈ړ��ʂ�n��
}


//�J�����K���Ƃ̏Փ˔���
//�w�肵���u�^�O�̖��O�v�ƏՓ˂����ꍇ�Atrue
bool	CameraGun::HitCheck(const std::string& name)
{
	std::vector<K_Physics::CollisionTag*>	tags = physics->FindConfrictionObjects(collision);
	for (auto it = tags.begin(); it != tags.end(); ++it)
	{
		if ((*it)->tagName == name)
		{
			//targetTag->userData = (K_Math::Vector3*)(*it)->userData;
			std::cout << "�J�����K���ƏՓ˂��܂���" << std::endl;
			return true;
		}
	}
	return false;
}