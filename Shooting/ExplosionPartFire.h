#ifndef EXPLOSION_PART_FIRE_H_
#define EXPLOSION_PART_FIRE_H_

#include"Actor.h"

//�����ԉ΃N���X
class ExplosionPartFire :public Actor {
public:
	//�R���X�g���N�^
	ExplosionPartFire(IWorld* world, const GSvector3& position, const GSvector3& velocity);
	//�X�V
	virtual void update(float delta_time)override;
	//�������I�u�W�F�N�g�`��
	virtual void draw_transparent()const override;
private:
	//���Ń^�C�}�[
	float timer_{ 0.0f };
};
#endif