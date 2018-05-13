#include "SkillObject.h"


//----------------------------------------------------------------
//�R���X�g���N�^
//----------------------------------------------------------------
SkillObject::SkillObject(const SkillType& skillType_, const AnimationCharaChip& animCharaChip)
{
	object.GetStatus().SetStatusData(
		Status::State::Active,
		K_Math::Vector3(0,0,0),
		K_Math::Vector3(0, 0, 0),
		K_Math::Vector3(1, 1, 1),
		Status::Direction::Right,
		1,
		0
	);


	continueTime = 180;

	object.SetImage("SkillImg", CST::LoadAndGetTexture("SkillImg", "data/image/resource2.png"), true);
	object.GetImage().CreateCharaChip(K_Math::Box2D(0, 0, 32, 48), 5, 6, true);

	shape = CC::CreateBoxShape(16, 24, 1);

	cManager.CreateBaseCollisionData(shape, object.GetPos(), object.GetAngle(), true);
	cManager.CreateSubCollisionData(shape, CollisionMask::Non, CollisionMask::Non, object.GetPos());

	cManager.SetSubCollisionUserData(0, &object.GetStatus());
}

//-------------------------------------------------------------
//�f�X�g���N�^
//-------------------------------------------------------------
SkillObject::~SkillObject()
{
	CC::RemoveCollisionShape(&shape);
}


//�X�L���̌��ʏ���
void	SkillObject::SkillEffect()
{

}

//!@brief SkillObject���g�������邩�̔��f
//!@return �����鎞�Ԃ�������true
bool	SkillObject::CheckContinueTime()
{
	if (continueTime <= 0)
	{
		return true;
	}
	return false;
}

//!@brief �X�V����
void	SkillObject::UpDate()
{
	object.GetImage().Animation();
	continueTime--;
}

//!@brief �`�揈��
void	SkillObject::Render()
{
	object.GetImage().ImageDraw3D(object.GetPos(), object.GetAngle(), object.GetScale(), object.GetDirection());
}