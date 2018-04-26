#include "CSTList.h"

//-------------------------------------------------------------------
//�C���X�^���X�𓾂�
CSTList* CSTList::GetInstance()
{
	static CSTList sl;
	return &sl;
}

//-------------------------------------------------------------------
//�ˉe���e�J�������쐬
void CSTList::CreatePerspectiveCamera(const K_Math::Vector3& position, const K_Math::Vector3& target, int screenWidth, int screenHeight, float cameraNeer, float cameraFar, float fieldOfFar)
{
	cList.AddPerspectiveCamera("pers", position, target, screenWidth, screenHeight, cameraNeer, cameraFar, fieldOfFar);
	cPers = cList.GetCamera("pers");
}
//-------------------------------------------------------------------
//���s���e�J�������쐬
void CSTList::CreateOrthoCamera(const K_Math::Vector3& position, const K_Math::Vector3& target, int screenWidth, int screenHeight, float cameraNeer, float cameraFar)
{
	cList.AddOrthoCamera("ortho", position, target, screenWidth, screenHeight, cameraNeer, cameraFar);
	cOrtho = cList.GetCamera("ortho");
}
//-------------------------------------------------------------------
//�ˉe���e�J�����̃A�h���X�l�𓾂�
K_Graphics::CameraClass* CSTList::GetPerspectoveCamera()
{
	return cPers;
}
//-------------------------------------------------------------------
//���s���e�J�����̃A�h���X�l�𓾂�
K_Graphics::CameraClass* CSTList::GetOrthoCamera()
{
	return cOrtho;
}

//-------------------------------------------------------------------
//���_�V�F�[�_�[�ƃt���O�����g�V�F�[�_��ǂݍ���ŃV�F�[�_�[���쐬
void CSTList::CreateShader(const std::string& vsFileName, const std::string& psFileName)
{
	sList.LoadVertexShader(vsFileName);
	sList.LoadFragmentShader(psFileName);
	sList.CreateShaderProgram("shader", vsFileName, psFileName);
	shader = sList.GetShader("shader");
}
//-------------------------------------------------------------------
//�V�F�[�_�[�̃A�h���X�l�𓾂�
K_Graphics::ShaderClass* CSTList::GetShaderClass()
{
	return shader;
}

//-------------------------------------------------------------------
//�e�N�X�`�����X�g���擾
K_Graphics::TextureList* CSTList::GetTextureList()
{
	return &tList;
}