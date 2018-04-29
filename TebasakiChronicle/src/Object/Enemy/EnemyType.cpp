#include "EnemyType.h"

EnemyType::EnemyType(std::string imgName, K_Physics::CollisionShape* cs, int ml, int hd) :
	imageName(imgName),
	maxLife(ml),
	hitDamage(hd),
	emSet(new EnemyMoveSet())
{
	//�e�N�X�`����ǂݍ���
	texture = CST::LoadAndGetTexture(imageName, "data/image/" + imgName + ".tga");
	//�R���W�����̌`���ݒ�
	cShape = cs;
}

EnemyType::~EnemyType()
{
	delete emSet;
}
