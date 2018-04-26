#include "EnemyType.h"

EnemyType::EnemyType(std::string imgName, int ml, int hd) :
	imageName(imgName),
	maxLife(ml),
	hitDamage(hd),
	emSet(new EnemyMoveSet())
{
	//�e�N�X�`����ǂݍ���
	CSTList* cst = CSTList::GetInstance();
	cst->GetTextureList()->LoadTexture(imageName, "data/image/" + imgName + ".tga");
	texture = cst->GetTextureList()->GetTexture(imageName);
}

EnemyType::~EnemyType()
{
	//�s�v�ȉ摜(�e�N�X�`��)���J������
	CSTList* cst = CSTList::GetInstance();
	cst->GetTextureList()->DeleteTexture(imageName);

	delete emSet;
}
