#ifndef EXPLOSION_H_
#define EXPLOSION_H_

#include"Actor.h"

//���������N���X
class Explosion :public Actor {
public:
	//�R���X�g���N�^
	Explosion(IWorld* world, const GSvector3& postion);
	//�X�V
	virtual void update(float delta_time)override;
};
#endif // !EXPLOSION_H_
