#ifndef LIGHT_H_
#define LIGHT_H_

#include "Actor.h"

// ���C�g�N���X
class Light : public Actor {
public:
    // �R���X�g���N�^
    Light(IWorld* world);
    // �`��
    virtual void draw() const override;
};

#endif

