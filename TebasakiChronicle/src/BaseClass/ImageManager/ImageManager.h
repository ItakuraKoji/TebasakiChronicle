#pragma once
#include <math.h>
#include "AnimationCharaChip.h"

class ImageManager
{
private:
	const bool	isDelete;
	std::string							textureName;
	K_Graphics::SpriteObject*			spobj;
	std::vector<AnimationCharaChip*>	charaChip;
	int									nowAnimNum;
	float								animCnt;

public:
	//コンストラクタ
	//キャラチップをImageManager内で作成しない場合は第二引数にfalseを指定
	ImageManager(const std::string& texName, K_Graphics::Texture* tex, bool isde = true);

	//デストラクタ
	~ImageManager();

	//テクスチャ名の取得
	std::string& GetTextureName();
	//現在のキャラチップを取得
	AnimationCharaChip* GetNowAnimationCharaChip();

	//----------------------------------------------
	//キャラチップの作成
	bool CreateCharaChip(const K_Math::Box2D& src, int sheet, float spd, bool isroop);

	//----------------------------------------------
	//キャラチップを変更
	//※コンストラクタでisdeをfalseにしていないと失敗する
	bool ChangeCharaChip(const std::vector<AnimationCharaChip*>& acc);

	//----------------------------------------------
	//アニメーションパターンの変更
	void ChangeAnimationPattern(int motionNum, bool timeReset = true);

	//----------------------------------------------
	//アニメーション
	void Animation();

	//----------------------------------------------
	//描画(3D)
	void ImageDraw3D(	const K_Math::Vector3&	posc, 
						const K_Math::Vector3&	angle,
						const K_Math::Vector3&	scale,
						int						direction);
};