#pragma once
#include "K_Math\MyMathFanctions.h"

//----------------------------------------------------------
//�X�L���̎�ނ̃C���^�[�t�F�C�X
//�T�v:�X�L���̎�ނ�\���C���^�[�t�F�C�X
//�����:�����
//----------------------------------------------------------
class SkillType
{
protected:
	//!@brief �R���X�g���N�^
	//!@param[in] maxUseNum_ �ő�g�p��
	//!@param[in] continueTime_ �p������
	//!@param[in] appearPos_ �o���ʒu
	explicit SkillType(const int& maxUseNum_,const int& continueTime_,const K_Math::Vector3& appearPos_);
public:
	virtual ~SkillType() {};

	virtual void	UpDate() = 0;
	virtual void	Render() = 0;

protected:
	int				maxUseNum;		//�ő�g�p��
	int				continueTime;	//�p������
	K_Math::Vector3	appearPos;		//�o���ʒu
};