#include "TemporaryCollision.h"

//�R���X�g���N�^
//�R���W�����̌`�����delete����
TemporaryCollision::TemporaryCollision(	K_Physics::CollisionShape*	shape,
										CollisionMask&				mmask,
										CollisionMask&				gmask,
										K_Math::Vector3&			setpos,
										K_Math::Vector3&			movevec,
										Status::Direction&			dir,
										int							damage,
										int							deletetime,
										bool						ishitground,
										bool						doground):
	cShape(shape),
	deleteTime(deletetime),
	isHitGround(ishitground)
{
	colmanager.CreateGroundCollisionData(shape, setpos, K_Math::Vector3(0, 0, 0), doground);
	colmanager.CreateSubCollisionData(shape, mmask, gmask, K_Math::Vector3(0, 0, 0));

	gameObject.GetStatus().SetStatusData(
		Status::State::Active,
		setpos,
		K_Math::Vector3(0, 0, 0),
		K_Math::Vector3(1, 1, 1),
		dir,
		damage,
		0);

	colmanager.SetSubCollisionTug(0, &gameObject.GetState());
}

//�R���X�g���N�^
//�R���W�����̌`�����delete���Ȃ�(�����������L�����Ȃ�)
TemporaryCollision::TemporaryCollision(	K_Physics::CollisionData*	basedata,
										K_Physics::CollisionData*	subdata,
										K_Math::Vector3&			setpos,
										K_Math::Vector3&			moveVec,
										Status::Direction&			dir,
										int							damage,
										int							deletetime,	
										bool						ishitground):
	cShape(nullptr),
	deleteTime(deletetime),
	isHitGround(ishitground)
{
	colmanager.SetBaseCollisionData(basedata, setpos);
	colmanager.SetSubCollisionData(subdata);

	gameObject.GetStatus().SetStatusData(
		Status::State::Active,
		setpos,
		K_Math::Vector3(0, 0, 0),
		K_Math::Vector3(1, 1, 1),
		dir,
		damage,
		0);

	colmanager.SetSubCollisionTug(0, &gameObject.GetState());
}

//�f�X�g���N�^
TemporaryCollision::~TemporaryCollision()
{
	if (cShape != nullptr)
	{
		CC::RemoveCollisionShape(&cShape);
	}
}

//-----------------------------------------------------------------------------
//�摜�Ǘ��҂𐶐����A�����ɃL�����`�b�v��ݒ肷��
void TemporaryCollision::SetImageManagerAndCharaChip(	std::string&			texName,
														K_Graphics::Texture*	texture,
														K_Math::Box2D&			src,
														int						sheet,
														float					spd,
														bool					isroop)
{
	gameObject.SetImage(texName, texture);
	gameObject.GetImage().CreateCharaChip(src, sheet, spd, isroop);
}

//-----------------------------------------------------------------------------
//�X�V(���ł���ۂ�true���Ԃ�)
bool TemporaryCollision::Update()
{
	//����
	if (Extinction())
	{
		return true;
	}

	//�R���W�����̓���
	colmanager.MoveBaseCollision(	gameObject.GetMove().GetMoveVec(),
									gameObject.GetStatus().GetDirection(),
									true);

	//�A�j���[�V�����̍X�V
	if (&gameObject.GetImage() != nullptr)
	{
		gameObject.GetImage().Animation();
	}

	return false;
}

//-----------------------------------------------------------------------------
//���Ńt���O�𗧂Ă�
bool TemporaryCollision::Extinction()
{
	if ((gameObject.GetStatus().GetState() != Status::State::Active) ||		//�O���ɂ����State��Active�ȊO�ɂ���Ă��������
		(timeCnt >= deleteTime) ||											//���Ԍo�߂ŏ���
		(isHitGround == true && colmanager.CheckHitBaseCollisionObject()))	//�n�`�ƐڐG���ď�����ꍇ�̔���
	{
		return true;
	}
	++timeCnt;
	
	return false;
}

//-----------------------------------------------------------------------------
//�`��
void TemporaryCollision::Render()
{
	//�A�j���[�V�����̍X�V
	if (&gameObject.GetImage() != nullptr)
	{
		gameObject.GetImage().ImageDraw3D(	gameObject.GetStatus().GetPos(),
											gameObject.GetStatus().GetAngle(),
											gameObject.GetStatus().GetScale(),
											gameObject.GetStatus().GetDirection());
	}
}