#pragma once
#include "K_Graphics\CameraList.h"
#include "K_Graphics\ShaderList.h"
#include "K_Graphics\TextureList.h"

class CSTList
{
private:
	K_Graphics::CameraList			cList;
	K_Graphics::CameraClass*		cPers;
	K_Graphics::CameraClass*		cOrtho;

	K_Graphics::ShaderList			sList;
	K_Graphics::ShaderClass*		shader;

	K_Graphics::TextureList			tList;

	static CSTList* cstlist;
	CSTList() {}

public:
	//�C���X�^���X�𓾂�
	static CSTList* GetInstance();

	//�ˉe���e�J�������쐬
	void CreatePerspectiveCamera(const K_Math::Vector3& position, const K_Math::Vector3& target, int screenWidth, int screenHeight, float cameraNeer, float cameraFar, float fieldOfFar);
	//���s���e�J�������쐬
	void CreateOrthoCamera(const K_Math::Vector3 &position, const K_Math::Vector3 &target, int screenWidth, int screenHeight, float cameraNeer, float cameraFar);
	//�ˉe���e�J�����̃A�h���X�l�𓾂�
	K_Graphics::CameraClass* GetPerspectoveCamera();
	//���s���e�J�����̃A�h���X�l�𓾂�
	K_Graphics::CameraClass* GetOrthoCamera();

	//���_�V�F�[�_�[�ƃt���O�����g�V�F�[�_��ǂݍ���ŃV�F�[�_�[���쐬
	void CreateShader(const std::string& vsFileName, const std::string& psFileName);
	//�V�F�[�_�[�̃A�h���X�l�𓾂�
	K_Graphics::ShaderClass* GetShaderClass();

	//�e�N�X�`�����X�g�̃A�h���X�l�𓾂�
	K_Graphics::TextureList* GetTextureList();
};