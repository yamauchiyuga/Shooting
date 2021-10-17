#ifndef ASTEROID_H_
#define ASTEROID_H_

#include "Actor.h"

// 覐΃N���X
class Asteroid : public Actor {
public:
    // �R���X�g���N�^
    Asteroid(IWorld* world, const GSvector3& position, const GSvector3& velocity);
    // �X�V
    virtual void update(float delta_time) override;
    // �`��
    virtual void draw() const override;
    // �Փˏ���
    virtual void react(Actor& other) override;
};

#endif

