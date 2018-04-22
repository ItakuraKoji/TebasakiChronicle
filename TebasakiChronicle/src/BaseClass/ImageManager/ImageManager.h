#pragma once
#include "MeshModel.h"
#include "K_Graphics\CameraList.h"
#include "K_Graphics\ShaderList.h"
#include "K_Graphics\TextureList.h"
#include "AnimationCharaChip.h"

class ImageManager
{
private:
	const bool	isDelete;
public:
	K_Graphics::CameraClass*			camera;
	K_Graphics::ShaderClass*			shader;

	K_Graphics::SpriteObject*			spobj;
	std::vector<AnimationCharaChip*>	charaChip;
	int									nowAnimNum;
	float								animCnt;

	//�R���X�g���N�^(�L�����`�b�v���쐬����)
	ImageManager(	K_Graphics::CameraClass*	cc,
					K_Graphics::ShaderClass*	sc, 
					K_Graphics::Texture*		tex);

	//�R���X�g���N�^(�O���̃L�����`�b�v���Q�Ƃ���)
	//���L�����`�b�v��V���ɐݒ肷�邱�Ƃ͂ł��Ȃ�
	ImageManager(	K_Graphics::CameraClass*			cc,
					K_Graphics::ShaderClass*			sc,
					K_Graphics::Texture*				tex,
					std::vector<AnimationCharaChip*>	acc);

	//�f�X�g���N�^
	~ImageManager();

	//----------------------------------------------
	//�L�����`�b�v�̍쐬
	void CreateCharaChip(const K_Math::Box2D& src, int sheet, float spd, bool isroop);

	//----------------------------------------------
	//�A�j���[�V�����p�^�[���̕ύX
	void ChangeAnimationPattern(int motionNum);

	//----------------------------------------------
	//�A�j���[�V����
	void Animation();

	//----------------------------------------------
	//�`��
	void ImageDraw(	const K_Math::Vector3& posc, 
					const K_Math::Vector3& angle,
					const K_Math::Vector3& scale);
};