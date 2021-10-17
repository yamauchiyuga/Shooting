#ifndef PLAYER_H_
#define PLAYER_H_

#include "Actor.h"

// �v���[��
class Player : public Actor {
public:
    // �R���X�g���N�^
    Player(IWorld* world, const GSvector3& position);
    // �X�V
    virtual void update(float delta_time) override;
    // �`��
    virtual void draw() const override;
    // �Փˏ���
    virtual void react(Actor& other) override;
};

#endif

