#include "ImageManager.h"

//�R���X�g���N�^(�L�����`�b�v���쐬����)
ImageManager::ImageManager(	K_Graphics::CameraClass* cc,
							K_Graphics::ShaderClass* sc,
							K_Graphics::Texture* tex) :
	camera(cc),
	shader(sc),
	spobj(new K_Graphics::SpriteObject(tex)),
	animCnt(0.f),
	nowAnimNum(0),
	isDelete(true) {}

//�R���X�g���N�^(�O���̃L�����`�b�v���Q�Ƃ���)
ImageManager::ImageManager(	K_Graphics::CameraClass* cc,
							K_Graphics::ShaderClass* sc, 
							K_Graphics::Texture* tex,
							std::vector<AnimationCharaChip*> acc) :
	camera(cc),
	shader(sc),
	spobj(new K_Graphics::SpriteObject(tex)),
	animCnt(0.f),
	nowAnimNum(0),
	charaChip(acc),
	isDelete(false) {}

//�f�X�g���N�^
ImageManager::~ImageManager()
{
	delete spobj;

	if (isDelete)
	{
		for (auto it : charaChip)
			delete it;
	}

}

//-----------------------------------------------------------------------------
//�L�����`�b�v���쐬
void ImageManager::CreateCharaChip(const K_Math::Box2D& src, int sheet, float spd, bool isroop)
{
	if (isDelete)
	{
		charaChip.emplace_back(new AnimationCharaChip(src, sheet, spd, isroop));
	}
}

//-----------------------------------------------------------------------------
//�A�j���[�V�����p�^�[���̕ύX
void ImageManager::ChangeAnimationPattern(int motionNum)
{
	animCnt = 0.f;
	nowAnimNum = motionNum;
}

//-----------------------------------------------------------------------------
//�A�j���[�V����
void ImageManager::Animation()
{
	animCnt += 1.f / charaChip[nowAnimNum]->animSpd;

	//���[�v���Ȃ��ꍇ�͍Ō�̓���Œ�~
	if (charaChip[nowAnimNum]->isAnimRoop == false &&
		(int)animCnt >= charaChip[nowAnimNum]->chipSheetNum)
	{
		animCnt = (float)charaChip[nowAnimNum]->chipSheetNum;
	}
}

//-----------------------------------------------------------------------------
//�`��
void ImageManager::ImageDraw(	const K_Math::Vector3& posc,
								const K_Math::Vector3& angle,
								const K_Math::Vector3& scale)
{
	K_Math::Box2D src = charaChip[nowAnimNum]->chip;
	src.x += src.w * (int(animCnt) % charaChip[nowAnimNum]->chipSheetNum);
	spobj->controlPoint = K_Math::Vector2(src.w / 2.f, src.h / 2.f);

	K_Math::Vector3 pos = posc;
	pos.x() -= (float)src.w / 2.f;
	pos.y() += (float)src.h / 2.f;

	spobj->Draw3D(
		camera,
		shader,
		src,
		pos,
		angle,
		scale);
}