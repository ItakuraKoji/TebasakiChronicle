#pragma once
#include "../src/Object//Player/CameraGun/CameraGun.h"
#include "../src/Object/Player/CharaController/CharaController.h"

//--------------------------------------------------------------------
//プレイヤー
//概要:プレイヤー専用のもの
//製作者:日比野
//--------------------------------------------------------------------
class Player
{
public:
	//モーション
	enum Motion
	{
		Non = -1,	//なし
		Idle = 0,	//待機
		Walk,		//歩く
		Run,		//走る
		Jump,		//上昇中
		Fall,		//落下中
		TakeOff,	//飛ぶ前
		Landing,	//着地
		SkillUse,	//スキル使用中
	};

	//コリジョンの種類
	enum CollisionKind
	{
		Base = 0,	//体
		Foot,		//足元
		Head,		//頭上
	};

public:
	Player();
	~Player();

	//仮の大きな処理
	void	Initliaze();	//初期化
	void	UpDate();		//更新
	void	Render();		//描画

private:
	void	ChangeDir();			//入力に応じて向きを変える
	void	ShotCameraGun();		//カメラガンを飛ばす
	void	ReverseCameraGun();		//カメラガンを戻す
	void	JumpMove();				//ジャンプ
	void	SetSkillData();			//カメラガンからスキルを取得

	void	Think();	//思考処理(モーション決定)
	void	Move();		//モーションに対応した処理
	//モーションの更新
	bool	UpDateMotion(const Motion& nowMotion);


private:
	Motion			motion;		//モーション
	int				motionCnt;	//モーションのカウント
	GameObject		object;		//ゲームオブジェクト
	CharaController	controller;	//コントローラー
	CameraGun		cameraGun;	//カメラガン
	int				maxFrame;	//最大のフレーム数

public:
	K_Physics::CollisionShape*	shape;		//ベースコリジョンの形状
	K_Physics::CollisionShape*	shape2;		//足元と頭上用コリジョンの形状
	CollisionManager			cManager;	//コリジョンの管理者
};