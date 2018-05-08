#pragma once
#include "K_Math/MyMathFanctions.h"
#include "../BaseClass/Move.h"
#include "../BaseClass/easing.h"
#include "../BaseClass/Status/Status.h"
#include "../src/BaseClass/ImageManager/ImageManager.h"

//-------------------------------------------------------------
//�Q�[���I�u�W�F�N�g
//�T�v:�I�u�W�F�N�g�̕K�v�Œ���̋@�\��񋟂���
//�����:�����
//-------------------------------------------------------------
class GameObject
{
public:
	GameObject();
	~GameObject();

	//�ݒ菈��
	void	SetStatus();
	void	SetMove(const Move* move);
	void	SetImage(const std::string& texName, K_Graphics::Texture* tex, bool isde = true);
	void	SetSound();
	void	SetEasing();

	//�擾����
	Status&				GetStatus();
	Move&				GetMove();
	ImageManager&		GetImage();
	Easing&				GetEasing();

	//�X�e�[�^�X�̐ݒ�
	void	SetPos(const K_Math::Vector3& vec);
	void	SetAngle(const K_Math::Vector3& vec);
	void	SetScale(const K_Math::Vector3& vec);
	void	SetMoveVec(const K_Math::Vector3& vec);
	void	SetState(const Status::State& state);
	void	SetDirection(const Status::Direction& dir);
	void	SetAttackPoint(const int& atPoint);
	void	SetLife(const int& life);

	//�X�e�[�^�X�̎擾����
	Status::State&		GetState();
	K_Math::Vector3&	GetPos();
	K_Math::Vector3&	GetAngle();
	K_Math::Vector3&	GetScale();
	K_Math::Vector3&	GetMoveVec();
	Status::Direction&	GetDirection();
	int&				GetAttackPoint();
	int&				GetLife();

	//�摜�̐���
	//�摜�����ɂ́A�摜������ꍇ�́A1��delete����K�v������
	bool	CreateImage(K_Graphics::Texture* tex, bool isde = true);

	bool	CreateImg(const std::string& texName, const std::string& filePath);

	//�摜�̔j��
	//�摜������ꍇ�A�摜��delete����
	//�摜���Ȃ��ꍇ�A�摜��delete���Ȃ�
	bool	DeleteImage();

private:
	K_Graphics::Texture*	texture;
private:
	Status			status;		//Status
	Move			move;		//�ړ�����
	ImageManager*	image;		//ImageManager
								//Sound
	Easing			easing;		//�C�[�W���O
};