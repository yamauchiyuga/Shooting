#ifndef EXPLOSION_PART_FLASH_H_
#define EXPLOSION_PART_FLASH_H_

#include"Actor.h"

//爆発フラッシュクラス
class ExplosionPartFlash : public Actor
{
public:
	//コンストラクタ
	ExplosionPartFlash(IWorld* world, const GSvector3& position);
	//更新
	virtual void update(float delta_time)override;
	//半透明オブジェクト描画
	virtual void draw_transparent()const override;
private:
	//消滅タイマー
	float timer_{ 0.0f };
};

#endif // !EXPLOSION_PART_FLASH_H_

