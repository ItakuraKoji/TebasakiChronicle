#pragma once
#include "SkillData.h"
#include "../src/Object/GameObject.h"
#include "../src/BaseClass/Collision/CollisionManager.h"

//--------------------------------------------------------------
//�X�L���I�u�W�F�N�g
//�T�v:�X�L���������A�����蔻���L�����`�b�v���o��������
//�����:�����
//--------------------------------------------------------------
class SkillObject
{
public:
	explicit SkillObject(const SkillType& skillType_, const AnimationCharaChip& animCharaChip);
	~SkillObject();

	//!@brief SkillType�ɉ��������ʏ���
	void	SkillEffect();

	//!@brief SkillObject���g�������邩�̔��f
	//!@return �����鎞�Ԃ�������true
	bool	CheckContinueTime();

	//!@brief �X�V����
	void	UpDate();

	//!@brief �`�揈��
	void	Render();

private:
	GameObject					object;	//�Q�[���I�u�W�F�N�g
	K_Physics::CollisionShape*	shape;	//�x�[�X�R���W����
	CollisionManager		cManager;	//�R���W�����Ǘ���
	int						continueTime;	//�p������
};