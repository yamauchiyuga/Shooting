#ifndef EXPLOSION_PART_FLASH_H_
#define EXPLOSION_PART_FLASH_H_

#include"Actor.h"

//�����t���b�V���N���X
class ExplosionPartFlash : public Actor
{
public:
	//�R���X�g���N�^
	ExplosionPartFlash(IWorld* world, const GSvector3& position);
	//�X�V
	virtual void update(float delta_time)override;
	//�������I�u�W�F�N�g�`��
	virtual void draw_transparent()const override;
private:
	//���Ń^�C�}�[
	float timer_{ 0.0f };
};

#endif // !EXPLOSION_PART_FLASH_H_

