#include "AnimationCharaChip.h"

//�R���X�g���N�^
AnimationCharaChip::AnimationCharaChip(	const K_Math::Box2D&	src,
										int						sheet,
										float					spd,
										bool					ir):
			chip(src), chipSheetNum(sheet), animSpd(spd), isAnimRoop(ir)
{

}

//�f�X�g���N�^
AnimationCharaChip::~AnimationCharaChip() {}