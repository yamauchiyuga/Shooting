#ifndef ASTEROID_H_
#define ASTEROID_H_

#include "Actor.h"

// 隕石クラス
class Asteroid : public Actor {
public:
    // コンストラクタ
    Asteroid(IWorld* world, const GSvector3& position, const GSvector3& velocity);
    // 更新
    virtual void update(float delta_time) override;
    // 描画
    virtual void draw() const override;
    // 衝突処理
    virtual void react(Actor& other) override;
};

#endif

