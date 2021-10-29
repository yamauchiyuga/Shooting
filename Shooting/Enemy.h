#ifndef ENEMY_H_
#define ENEMY_H_

#include "Actor.h"

// �G
class Enemy : public Actor {
public:
    // �R���X�g���N�^
    Enemy(IWorld* world, const GSvector3& position);
    // �X�V
    virtual void update(float delta_time) override;
    // �`��
    virtual void draw() const override;
    // �Փˏ���
    virtual void react(Actor& other) override;

private:
    // �ړ��p�^�C�}
    float moving_timer_{ 0.0f };
    // �V���b�g�p�^�C�}
    float shooting_timer_{ 0.0f };
};

#endif

