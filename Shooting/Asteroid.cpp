#include "Asteroid.h"
#include "Assets.h"
#include"IWorld.h"
#include"Field.h"
#include"Explosion.h"

// �R���X�g���N�^
Asteroid::Asteroid(IWorld* world, const GSvector3& position, const GSvector3& velocity) {
    world_ = world;
    name_ = "Asteroid";
    tag_ = "EnemyTag";
    transform_.position(position);
    velocity_ = velocity;
    collider_ = BoundingSphere{ 8.0f };
}

// �X�V
void Asteroid::update(float delta_time) {
    // ��]������
    transform_.rotate(2.0f, 0.0f, 0.5f);
    // �ړ�����i���[���h���W�n����Ɉړ��j
    transform_.translate(velocity_ * delta_time, GStransform::Space::World);
    // �G���A�O�Ɉړ������玀�S������
    if (world_->field()->is_outside(transform_.position())) {
        die();
    }
}

// �`��
void Asteroid::draw() const {
    glPushMatrix();
    glMultMatrixf(transform_.localToWorldMatrix());
    gsDrawMesh(Mesh_Asteroid01);
    glPopMatrix();
}

// �Փˏ���
void Asteroid::react(Actor& other) {
    if (other.tag() == "PlayerTag"||other.tag()=="PlayerBulletTag") {
        // �����G�t�F�N�g�𐶐�
        world_->add_actor(new Explosion{ world_, transform_.position() });
        die();
    }
}

