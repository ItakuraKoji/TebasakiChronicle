#pragma once
#include <iostream>
#include <vector>
#include "SystemClass.h"
#include "MeshModel.h"
#include "..\..\CSTList.h"

//画像の分割情報(キャラチップ)を保持するやつ
class AnimationCharaChip
{
public:
	K_Math::Box2D	chip;			//キャラチップのサイズ
	int				chipSheetNum;	//アニメーション枚数
	float			animSpd;		//アニメーション速度
	bool			isAnimRoop;		//ループするか否か(trueでループする)

	//コンストラクタ
	AnimationCharaChip(const K_Math::Box2D& src, int sheet, float spd, bool ir);

	//デストラクタ
	~AnimationCharaChip();
};