#ifndef CAMERA_H_
#define CAMERA_H_

#include "Actor.h"


// �J�����N���X
class Camera : public Actor {
public:
    // �R���X�g���N�^
    Camera(IWorld* world);
    // �`��
    virtual void draw() const override;
};

#endif

