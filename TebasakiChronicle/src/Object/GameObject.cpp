#include "GameObject.h"

//------------------------------------------------------------
//�T�v:�Q�[���I�u�W�F�N�g�̏���
//�����:�����
//------------------------------------------------------------

//---------------------------------------------
//�R���X�g���N�^
//---------------------------------------------
GameObject::GameObject()
{

}

//---------------------------------------------
//�f�X�g���N�^
//---------------------------------------------
GameObject::~GameObject()
{

}


//---------------------------------------------
//�ݒ菈��
//---------------------------------------------
//�X�e�[�^�X�̐ݒ�
void	GameObject::SetStatus()
{

}

//�ړ��̐ݒ�
void	GameObject::SetMove(const Move* move)
{
	this->move = *move;
}

//�摜�̐ݒ�
void	GameObject::SetImage()
{

}

//�T�E���h�̐ݒ�
void	GameObject::SetSound()
{

}

//�C�[�W���O�̐ݒ�
void	GameObject::SetEasing()
{

}


//---------------------------------------------
//�擾����
//---------------------------------------------
//�X�e�[�^�X�̎擾
Status*	GameObject::GetStatus()
{
	return &status;
}

//�ړ��̎擾
Move*	GameObject::GetMove()
{
	return &move;
}

//�摜�̎擾
ImageManager*	GameObject::GetImage()
{
	return image;
}

//�C�[�W���O�̎擾
Easing*	GameObject::GetEasing()
{
	return &easing;
}