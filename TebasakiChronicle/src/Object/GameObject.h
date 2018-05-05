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
	void	SetImage();
	void	SetSound();
	void	SetEasing();

	//�擾����
	Status*				GetStatus();
	Move*				GetMove();
	ImageManager*		GetImage();
	Easing*				GetEasing();

	
private:
	Status			status;		//Status
	Move			move;		//�ړ�����
	ImageManager*	image;		//ImageManager
								//Sound
	Easing			easing;		//�C�[�W���O
};