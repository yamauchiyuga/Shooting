#include"EnemyBullet.h"
#include"IWorld.h"
#include"Field.h"
#include"Assets.h"

//�R���X�g���N�^
EnemyBullet::EnemyBullet(IWorld* world, const GSvector3& position, const GSvector3& velocity) {
    world_ = world;
    name_ = "EnemyBullet";
    tag_ = "EnemyBulletTag";
    velocity_ = velocity;
    collider_ = BoundingSphere{ 1.0f };
    transform_.position(position);
}

// �X�V
void EnemyBullet::update(float delta_time) {
    // �ړ�����i���[���h���W�n��j
    transform_.translate(velocity_ * delta_time, GStransform::Space::World);
    // �G���A�O�Ɉړ������玀�S������
    if (world_->field()->is_outside(transform_.position())) {
        die();
    }
}

// �������I�u�W�F�N�g�̕`��
void EnemyBullet::draw_transparent() const {
    // ���Z�������̎w������ăr���{�[�h��`��
    glPushAttrib(GL_ENABLE_BIT | GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glDisable(GL_LIGHTING);
    glDepthMask(GL_FALSE);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE);
    glEnable(GL_BLEND);
    static const GSrect size{ -5.0f, 5.0f, 5.0f, -5.0f };
    GSvector3 position = transform_.position();
    gsDrawSprite3D(Texture_EffectLazerCyan,
        &position, &size, NULL, NULL, NULL, 0.0f);
    glPopAttrib();
}

// �Փˏ���
void EnemyBullet::react(Actor& other) {
    if (other.tag() == "PlayerTag") {
        die();
    }
}