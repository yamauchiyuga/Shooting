#ifndef PLAYER_BULLET_H_
#define PLAYER_BULLET_H_

#include"Actor.h"

//�v���[���[�e�N���X
class PlayerBullet :public Actor {
public:
	//�R���X�g���N�^
	PlayerBullet(IWorld* world, const GSvector3& postion, const GSvector3& velocity);
	//�X�V
	virtual void update(float delta_time)override;
	//�������I�u�W�F�N�g�`��
	virtual void draw_transparent()const override;
	//�Փ˃��A�N�V����
	virtual void react(Actor& other)override;
};
#endif // !PLAYER_BULLET_H_a
