#include "EnemyType.h"

EnemyType::EnemyType(std::string texName, K_Physics::CollisionShape* cs, int ml, int hd) :
	textureName(texName),
	maxLife(ml),
	hitDamage(hd),
	emSet(new EnemyMoveSet())
{
	//�e�N�X�`����ǂݍ���
	texture = CST::LoadAndGetTexture(textureName, "data/image/" + textureName + ".tga");
	//�R���W�����̌`���ݒ�
	cShape = cs;
}

EnemyType::~EnemyType()
{
	delete emSet;
}