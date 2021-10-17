#include "Asteroid.h"
#include "Assets.h"

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
    if (other.tag() == "PlayerTag") {
        die();
    }
}

