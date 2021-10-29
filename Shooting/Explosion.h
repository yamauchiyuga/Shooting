#ifndef EXPLOSION_H_
#define EXPLOSION_H_

#include"Actor.h"

//爆発生成クラス
class Explosion :public Actor {
public:
	//コンストラクタ
	Explosion(IWorld* world, const GSvector3& postion);
	//更新
	virtual void update(float delta_time)override;
};
#endif // !EXPLOSION_H_
