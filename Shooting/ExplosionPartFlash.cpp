#include "ExplosionPartFlash.h"
#include "Assets.h"
#include <GSeasing.h>

const float FlashTime{ 20.0f };

// �R���X�g���N�^
ExplosionPartFlash::ExplosionPartFlash(IWorld* world, const GSvector3& position) {
    world_ = world;
    name_ = "ExplosionPartFlash";
    tag_ = "EffectTag";
    transform_.position(position);
}

// �X�V
void ExplosionPartFlash::update(float delta_time) {
    if (timer_ > FlashTime) {
        die();
    }
    timer_ += delta_time;
}

// �������I�u�W�F�N�g�̕`��
void ExplosionPartFlash::draw_transparent() const {
    glPushAttrib(GL_ENABLE_BIT | GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glDisable(GL_LIGHTING);
    glDepthMask(GL_FALSE);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE);
    float t = timer_ / FlashTime;
    static const GSrect body{ -20.0f, 20.0f, 20.0f, -20.0f };
    static const GScolor start_color{ 1.0f, 1.0f, 1.0f, 1.0f };
    static const GScolor end_color{ 0.8f, 0.0f, 0.0f, 0.0f };
    GScolor color = GScolor::lerp(start_color, end_color, gsEasingInOutCubic(t));
    static const GSvector2 start_scale{ 0.5f, 0.5f };
    static const GSvector2 end_scale{ 1.0f, 1.0f };
    GSvector2 scale = GSvector2::lerp(start_scale, end_scale, gsEasingOutBack(t));
    GSvector3 position = transform_.position();
    gsDrawSprite3D(Texture_EffectFlash,
        &position, &body, NULL, &color, &scale, 0.0f);
    glPopAttrib();
}

