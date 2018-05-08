#include "EnemyType.h"

EnemyType::EnemyType(	std::string texName,
						int		maxlife,
						int		hitdamage,
						float	movespeed,
						float	jumppower,
						K_Physics::CollisionShape* sBase,
						K_Physics::CollisionShape* sReceive,
						K_Physics::CollisionShape* sFieldofview,
						K_Physics::CollisionShape* sAttackArea,
						K_Physics::CollisionShape* sCheck,
						K_Math::Vector3& pRecieve,
						K_Math::Vector3& pFieldofview,
						K_Math::Vector3& pAttackArea,
						K_Math::Vector3& pCheckFoot,
						K_Math::Vector3& pCheckHead) :
	textureName(texName),
	maxLife(maxlife),
	hitDamage(hitdamage),
	moveSpeed(movespeed),
	jumpPower(jumppower),
	emSet(new EnemyMoveSet())
{
	texture = CST::LoadAndGetTexture(textureName, "data/image/" + textureName + ".tga");
	baseShape = sBase;
	receiveShape = sReceive;
	receivePos = pRecieve;
	fovShape = sFieldofview;
	fovPos = pFieldofview;
	attackAreaShape = sAttackArea;
	attackAreaPos = pAttackArea;
	checkShape = sCheck;
	checkFootPos = pCheckFoot;
	checkHeadPos = pCheckHead;
}

EnemyType::~EnemyType()
{
	CST::DeleteTexture(textureName);
	delete emSet;
	CC::RemoveCollisionShape(&baseShape);
	CC::RemoveCollisionShape(&receiveShape);
	CC::RemoveCollisionShape(&fovShape);
	CC::RemoveCollisionShape(&attackAreaShape);
	CC::RemoveCollisionShape(&checkShape);
}

//-----------------------------------------------------------------------------
//EnemyMoveSet���擾
EnemyMoveSet* EnemyType::GetEnemyMoveSet()
{
	return emSet;
}
//-----------------------------------------------------------------------------
//�摜�����擾
const std::string& EnemyType::GetTextureName()
{
	return textureName;
}
//-----------------------------------------------------------------------------
//�̗͏�����擾
const int EnemyType::GetMaxLife()
{
	return maxLife;
}
//-----------------------------------------------------------------------------
//�v���C���[�ɗ^����_���[�W�ʂ��擾
const int EnemyType::GetHitDamage()
{
	return hitDamage;
}
//-----------------------------------------------------------------------------
//1�t���[���̈ړ����x���擾
const float EnemyType::GetMoveSpeed()
{
	return moveSpeed;
}
//-----------------------------------------------------------------------------
//�W�����v�͂��擾
const float EnemyType::GetJumpPower()
{
	return jumpPower;
}
//-----------------------------------------------------------------------------
//�e�N�X�`�����擾
K_Graphics::Texture* EnemyType::GetTexture()
{
	return texture;
}

//-----------------------------------------------------------------------------
//�n�`�p�R���W�����f�[�^�̐����Ǝ擾
K_Physics::CollisionData* EnemyType::GetBaseCollisionData()
{
	return CC::CreateCollisionObject(baseShape, false, CollisionMask::Ground, CollisionMask::Non);
}
//-----------------------------------------------------------------------------
//��_���p�R���W�����f�[�^�̐����Ǝ擾
K_Physics::CollisionData* EnemyType::GetRecieveDamageCollisionData()
{
	return CC::CreateCollisionObject(receiveShape, true, CollisionMask::TakeDamageEnemy, CollisionMask::EnemyCollision, receivePos);
}
//-----------------------------------------------------------------------------
//��J�����K���p�R���W�����f�[�^�̐����Ǝ擾
K_Physics::CollisionData* EnemyType::GetRecieveCameraCollisionData()
{
	return CC::CreateCollisionObject(receiveShape, true, CollisionMask::CameraGan, CollisionMask::EnemyCamCollision, receivePos);
}
//-----------------------------------------------------------------------------
//���E�p�R���W�����f�[�^�̐����Ǝ擾
K_Physics::CollisionData* EnemyType::GetFieldofviewCollisionData()
{
	return CC::CreateCollisionObject(fovShape, true, CollisionMask::PlayerCollision, CollisionMask::Non, fovPos);
}
//-----------------------------------------------------------------------------
//�U������J�ڗp�R���W�����̐����Ǝ擾
K_Physics::CollisionData* EnemyType::GetAttackAreaCollisionData()
{
	return CC::CreateCollisionObject(attackAreaShape, true, CollisionMask::PlayerCollision, CollisionMask::Non, attackAreaPos);
}
//-----------------------------------------------------------------------------
//�����p�R���W�����̐����Ǝ擾
K_Physics::CollisionData* EnemyType::GetCheckFootCollisionData()
{
	return CC::CreateCollisionObject(checkShape, true, CollisionMask::Ground, CollisionMask::Non, checkFootPos);
}
//-----------------------------------------------------------------------------
//����p�R���W�����̐����Ǝ擾
K_Physics::CollisionData* EnemyType::GetCheckHeadCollisionData()
{
	return CC::CreateCollisionObject(checkShape, true, CollisionMask::Ground, CollisionMask::Non, checkHeadPos);
}
//-----------------------------------------------------------------------------