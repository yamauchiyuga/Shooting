#include"ExplosionPartFire.h"
#include"Assets.h"
#include<GSeasing.h>

const float MoveTime{ 16.0f };

// �R���X�g���N�^
ExplosionPartFire::ExplosionPartFire(IWorld* world, const GSvector3& position, const GSvector3& velocity) {
	world_ = world;
	name_ = "ExplosionPartFire";
	tag_ = "EffectTag";
	velocity_ = velocity;
	transform_.position(position);
}

//
void ExplosionPartFire::update(float delta_time) {
	//
	transform_.translate(velocity_ * delta_time, GStransform::Space::World);
	//
	if (timer_ > MoveTime) {
		die();
	}
	timer_ += delta_time;
}

//
void ExplosionPartFire::draw_transparent()const {
	//OpenGL�̊e��ݒ��ޔ�
	glPushAttrib(GL_ENABLE_BIT | GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//���C�e�B���O����
    glDisable(GL_LIGHTING);
    // ���Z�u�����h�̎w��
    glBlendFunc(GL_SRC_ALPHA, GL_ONE);
    // �^�C�}�l������`��Ԃ̕�Ԓl(0.0 ~ 1.0)���v�Z
    float t = timer_ / MoveTime;
    // �r���{�[�h�̃T�C�Y
    static const GSrect body{ -5.0f, 0.0f, 5.0f, -10.0f };
    // �J�n�F
    static const GScolor start_color{ 1.0f, 1.0f, 1.0f, 1.0f };
    // �I���F
    static const GScolor end_color{ 1.0f, 0.5f, 0.5f, 0.0f };
    // ���`��ԂŁA���񂾂�Ɠ����ɂ���
    GScolor color = GScolor::lerp(start_color, end_color, gsEasingInExpo(t));
    // �J�n�X�P�[���l
    static const GSvector2 start_scale{ 1.0f, 1.0f };
    // �I���X�P�[���l
    static const GSvector2 end_scale{ 1.0f, 1.5f };
    // �c�����ɁA���񂾂�Ɗg�傷��
    GSvector2 scale = GSvector2::lerp(start_scale, end_scale, t);
    // �ړ������̊p�x�����߂�i�摜���c���ŏ�����������Ă���̂ŁA-90�x�␳����j
    float angle = GSvector2(velocity_.x, velocity_.y).getDirection() - 90.0f;
    GSvector3 position = transform_.position();
    // �r���{�[�h�̕`��
    gsDrawSprite3D(Texture_EffectLazerOrange,&position, &body, NULL, &color, &scale, angle);
    // OpenGL�̊e��ݒ�𕜋A
    glPopAttrib();
}
