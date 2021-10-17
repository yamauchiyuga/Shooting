#ifndef CAMERA_H_
#define CAMERA_H_

#include "Actor.h"


// カメラクラス
class Camera : public Actor {
public:
    // コンストラクタ
    Camera(IWorld* world);
    // 描画
    virtual void draw() const override;
};

#endif

