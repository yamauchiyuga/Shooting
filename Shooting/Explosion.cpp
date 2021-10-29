#include "Explosion.h"
#include "IWorld.h"
#include "ExplosionPartFlash.h"
#include "ExplosionPartFire.h"

// �R���X�g���N�^
Explosion::Explosion(IWorld* world, const GSvector3& position) {
    world_ = world;
    name_ = "Explosion";
    tag_ = "EffectTag";
    transform_.position(position);
}

// �X�V
void Explosion::update(float delta_time) {
    // �����̃t���b�V���G�t�F�N�g�̐���
    world_->add_actor(new ExplosionPartFlash(world_, transform_.position()));
    // �ΉԂ̃G�t�F�N�g�̐���
    for (float pitch = 0.0f; pitch < 360.0f; pitch += 20.0f) {
        // �ΉԂ̈ړ��ʂ��v�Z����
        GSvector3 velocity = GSvector3::createFromPitchYaw(pitch + gsRandf(-10.0f, 10.0f), 90.0f) * gsRandf(3.0f, 4.0f);
        world_->add_actor(new ExplosionPartFire{ world_, transform_.position(), velocity });
    }
    // �������I������玀�S
    die();
}

