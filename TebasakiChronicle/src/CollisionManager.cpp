#include "CollisionManager.h"

CollisionManager* CollisionManager::cManager = nullptr;
//-------------------------------------------------------------------
//�C���X�^���X�𓾂�
CollisionManager* CollisionManager::GetInstance()
{
	if (cManager == nullptr)
		cManager = new CollisionManager();

	return cManager;
}
//-------------------------------------------------------------------
//�������
void CollisionManager::Destroy()
{
	delete cManager;
}

CollisionManager* cm = CollisionManager::GetInstance();

namespace CM
{
	//�I������
	void Delete()
	{
		if (cm != nullptr)
		{
			cm->Destroy();
			cm = nullptr;
		}
	}

	//������(BulletPhysics���쐬)
	void Initialize()
	{
		if (cm->bPhysics == nullptr)
			cm->bPhysics = new K_Physics::BulletPhysics();
	}

	//���̌`����쐬���A�A�h���X�l�𓾂�
	K_Physics::CollisionShape* CreateSphereShape(float radius)
	{
		return cm->bPhysics->CreateSphereShape(radius);
	}
	//�J�v�Z���̌`����쐬���A�A�h���X�l�𓾂�
	K_Physics::CollisionShape* CreateCapsuleShape(float radius, float height)
	{
		return cm->bPhysics->CreateCapsuleShape(radius, height);
	}
	//�����̂̌`����쐬���A�A�h���X�l�𓾂�
	K_Physics::CollisionShape* CreateBoxShape(float halfWidth, float halfHeight, float halfDepth)
	{
		return cm->bPhysics->CreateBoxShape(halfWidth, halfHeight, halfDepth);
	}

	//�R���W�����I�u�W�F�N�g���쐬���A�A�h���X�l�𓾂�
	K_Physics::CollisionData* CreateCollisionObject(btCollisionShape* shape, bool ghost, int mask, const K_Math::Vector3 &pos, const K_Math::Vector3 &rot)
	{
		return cm->bPhysics->CreateCollisionObject(shape, ghost, mask, pos, rot);
	}

	//�������E���X�V���A���W��ύX����(�t���[���̍ŏ��ɌĂ�)
	void Run()
	{
		cm->bPhysics->Run();
	}

	//�R���W�����̈ړ��Ɠ����蔻��(���m&�d��)
	void MoveCharacter(K_Physics::CollisionData* obj, const K_Math::Vector3 &move, float vLimitAngle, float hLimitAngle)
	{
		cm->bPhysics->MoveCharacter(obj, move, vLimitAngle, hLimitAngle);
	}
	//�R���W�����̈ړ��Ɠ����蔻��(��G�c&�y��)
	void MoveCharacterDiscrete(K_Physics::CollisionData* obj, const K_Math::Vector3& move, bool vLimitDirection, bool hLimitDirection)
	{
		cm->bPhysics->MoveCharacterDiscrete(obj, move, vLimitDirection, hLimitDirection);
	}
	//�Փ˂̃`�F�b�N
	std::vector<K_Physics::CollisionTag*>& FindConfrictionObjects(K_Physics::CollisionData *myself)
	{
		return cm->bPhysics->FindConfrictionObjects(myself);
	}

	//�R���W�����̕`��
	void DebugDraw(K_Graphics::ShaderClass* sc, K_Graphics::CameraClass* cc)
	{
		cm->bPhysics->DebugDraw(sc, cc);
	}
}