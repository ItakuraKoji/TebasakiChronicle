#include "SkillManager.h"
#include "../src/Helper.h"
#include "SkillSword\SkillSword.h"


//----------------------------------------------------------------
//�R���X�g���N�^
//----------------------------------------------------------------
SkillManager::SkillManager()
	: skillChangeFlag(false)
{

}

//----------------------------------------------------------------
//�f�X�g���N�^
//----------------------------------------------------------------
SkillManager::~SkillManager()
{
	for (auto it : skillObj)
	{
		if (it != nullptr)
		{
			delete it;
			it = nullptr;
		}
	}
}


//!@brief SkillID�����������`�F�b�N
//!@param[in] skillID_ �擾�����X�L��ID
//!@return ID�������Ȃ�true
bool	SkillManager::CheckSkillID(const int& skillID_)
{
	//��ɋ󂩂ǂ������`�F�b�N���A��Ȃ璲�ׂ��Ȃ�
	if (skillDatas.empty()) { return false; }

	for (auto it = skillDatas.begin(); it != skillDatas.end(); ++it)
	{
		if (it->GetSkillID() != skillID_)
		{
			return true;
		}
	}
	return false;
}


//!@brief Skill�𐶐�����{�^���ɑΉ����ăX�L�����o��������
//!@param[in] num �ԍ�
void	SkillManager::CreateSkill(const int& num)
{
	//�ԍ��̎�ނ̃I�u�W�F�N�g�𐶐�
	//�����ŁAskllType�ɉ��������̂𐶐�

	//�����Ă���X�L���f�[�^�𐶐�����
	skill.emplace_back(CreateSkillType(skillDatas[num].GetSkillID()));
	
	skillObj.emplace_back(new SkillObject(skillDatas[num].GetSkillType(), skillDatas[num].GetAnimCharaChip()));

}

//!@brief SkillID��0(���݂��Ȃ�)�łȂ������`�F�b�N
//!@param[in] skillID_ �擾�����X�L��ID
//!@return ID��0�Ȃ�true
bool	SkillManager::IsNonSkillID(const int& skillID_)
{
	if (skillID_ != 0)
	{
		return false;
	}
	return true;
}


//!@brief SkillAndCharaChip�^�̃f�[�^���󂯎��
//!@param[in] skill �X�L���f�[�^
//!@return �󂯎���f�[�^�Ȃ�(����Ɏ󂯎�ꂽ�Ȃ�)true
bool	SkillManager::ReceiveSkillAndCharaChip(const Enemy::SkillAndCharaChip& skill)
{
	//SkillID��0�łȂ������`�F�b�N
	if (IsNonSkillID(*skill.skillId))
	{
		//return false;
	}

	//�X�L���͈ꎞ�I�Ƀ{�^��5�ɓ���
	skillDatas[skillNum - 1].SetSkillID(*skill.skillId);
	skillDatas[skillNum - 1].SetSkillImageName(*skill.textureName);
	skillDatas[skillNum - 1].SetAnimCharaChip(skill.nowCharaChip);
	skillDatas[skillNum - 1].SetSkillAppearPos(*skill.pos);

	std::cout << "�X�L���f�[�^���󂯎��܂���" << std::endl;
	std::cout << "�󂯎��O��SkillID:" << *skill.skillId << std::endl;
	std::cout << "�󂯎�������Ƃ�SkillID:" << skillDatas[skillNum - 1].GetSkillID() << std::endl;
	return true;
}


//!@brief SkillID�ɂ���ăX�L������������̂�ς���
//!@param[in] SkillType �X�L���̎��
//!@return �X�L���̎��(�h���N���X)
SkillType*	SkillManager::CreateSkillType(const int& skillID_)
{
	switch (skillID_) {
	case 0:
		return new SkillSword(10,3,K_Math::Vector3(0,0,0));
	case 2:
		//return new Walk();
	default:
		return nullptr;
	}
}


//!@brief Skill����������̂��g�p���邩�̃`�F�b�N
//!@return �X�L������������Ȃ�true�A�g�p����Ȃ�false
bool	SkillManager::CheckSkillChangeFlag()
{
	if (!skillChangeFlag)
	{
		return false;
	}
	return true;
}


//!@brief Skill��o�^����
void	SkillManager::RegistSkill(const int& num)
{
	//�Ή������{�^���ɃX�L��Datas��n��
	//���̃{�^���������ꂽSkillDatas�Ƀf�[�^���Ȃ�(-1)
	if (skillDatas[num].GetSkillID() == -1)
	{
		//�X�L��ID���������`�F�b�N
		if (skillDatas[skillNum - 1].GetSkillID() == skillDatas[num].GetSkillID())
		{
			//�����Ȃ�A�{�^��5�̃X�L���f�[�^�X�L���ԍ��̃X�L���ɓn��
			skillDatas[num].SetSkillID(skillDatas[skillNum - 1].GetSkillID());
			skillDatas[num].SetSkillType(&skillDatas[skillNum - 1].GetSkillType());
			skillDatas[num].SetSkillImageName(skillDatas[skillNum - 1].GetSkillImageName());
			skillDatas[num].SetSkillAppearPos(skillDatas[skillNum - 1].GetSkillAppearPos());

		}
		else
		{
			//�O�̃f�[�^���폜���āA�V�����X�L���f�[�^��n��
			skillDatas[num].SetSkillID(skillDatas[skillNum - 1].GetSkillID());
			skillDatas[num].SetSkillType(&skillDatas[skillNum - 1].GetSkillType());
			skillDatas[num].SetSkillImageName(skillDatas[skillNum - 1].GetSkillImageName());
			skillDatas[num].SetSkillAppearPos(skillDatas[skillNum - 1].GetSkillAppearPos());
		}
	}
}

//!@brief �g�p���邩�o�^���邩���f���A���ꂼ��̏������s��
void	SkillManager::Process(const int& btnNum)
{
	if (CheckSkillChangeFlag())
	{
		RegistSkill(btnNum);
		std::cout << "�X�L����" << btnNum << "�ɓo�^" << std::endl;
		ChangeSkillFlag(false);
	}
	else
	{
		CreateSkill(btnNum);
		std::cout << "�X�L����" << btnNum << "�g���܂���" << std::endl;
	}
}


//!@brief �X�L�����������邩�̃t���O�؂�ւ�
//!@param[in] skillChangeFlag_ �X�L���`�F���W�t���O
void	SkillManager::ChangeSkillFlag(bool skillChangeFlag_)
{
	skillChangeFlag = skillChangeFlag_;
}


//!@brief �X�V����
void	SkillManager::UpDate()
{
	for (auto it = skill.begin(); it != skill.end(); ++it)
	{
		if ((*it) != nullptr)
		{
			(*it)->UpDate();
		}
	}
	for (auto it = skillObj.begin(); it != skillObj.end();)
	{
		if ((*it) != nullptr)
		{
			(*it)->UpDate();
			//���Ԃ�������vector����r��
			if ((*it)->CheckContinueTime())
			{
				delete (*it);
				(*it) = nullptr;
				it = skillObj.erase(it);
			}
			else
			{
				++it;
			}
		}
	}
}


//!@brief �`�揈��
void	SkillManager::Render()
{
	for (auto it = skill.begin(); it != skill.end(); ++it)
	{
		if ((*it) != nullptr)
		{
			(*it)->Render();
		}
	}
	for (auto it = skillObj.begin(); it != skillObj.end(); ++it)
	{
		if ((*it) != nullptr)
		{
			(*it)->Render();
		}
	}
}

//private:

//!@brief SkillID�Ɋ�Â����ASkillObject�𐶐�����
void	SkillManager::Create()
{

}