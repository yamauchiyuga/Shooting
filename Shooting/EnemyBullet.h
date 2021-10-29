#ifndef ENEMY_BULLET_H_
#define ENEMY_BULLET_H_

#include"Actor.h"

//�G�e�N���X
class EnemyBullet :public Actor {
public:
	//�R���X�g���N�^
	EnemyBullet(IWorld* world, const GSvector3& postion, const GSvector3& velocity);
	//�X�V
	virtual void update(float delta_time)override;
	//�������I�u�W�F�N�g�`��
	virtual void draw_transparent()const override;
	//�Փ˃��A�N�V����
	virtual void react(Actor& other)override;
};
#endif // !ENEMY_BULLET_H_