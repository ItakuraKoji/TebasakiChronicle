#pragma once
#include "../src/Object/Player/Skill/SkillType.h"

//---------------------------------------------------------------
//�X�L���\�[�h
//�T�v:�؂�X�L���𔭓�
//�����:�����
//---------------------------------------------------------------
class SkillSword : public SkillType
{
public:
	//!@brief �R���X�g���N�^
	//!@param[in] maxUseNum_ �ő�g�p��
	//!@param[in] continueTime_ �p������
	//!@param[in] appearPos_ �o���ʒu
	explicit SkillSword(const int& maxUseNum_, const int& continueTime_, const K_Math::Vector3& appearPos_);
	
	void	UpDate();
	void	Render();
};