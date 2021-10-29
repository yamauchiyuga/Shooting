#include "Enemy.h"
#include "IWorld.h"
#include "Assets.h"
#include "Field.h"
#include "EnemyBullet.h"
#include"Explosion.h"

// �R���X�g���N�^
Enemy::Enemy(IWorld* world, const GSvector3& position) {
    world_ = world;
    name_ = "Enemy";
    tag_ = "EnemyTag";
    velocity_ = GSvector3{ 0.0f, -1.0f, 0.0f };
    collider_ = BoundingSphere{ 5.0f };
    moving_timer_ = gsRandf(0.0f, 60.0f);
    shooting_timer_ = gsRandf(0.0f, 60.0f);
    transform_.position(position);
    transform_.eulerAngles(90.0f, 0.0f, 0.0f);
}

// �X�V
void Enemy::update(float delta_time) {
    // �G�������}�C�i�X�����������悤�ɉ�]������
    transform_.eulerAngles(90.0f, 0.0f, 0.0f);
    // �����_���ȊԊu�Ńv���[���[�Ɍ�����
    if (moving_timer_ <= 0.0f) {
        Actor* player = world_->find_actor("Player");
        if (player != nullptr) {
            // �v���[���[�����̒P�ʃx�N�g�������߂�
            GSvector3 to_player =
                (player->transform().position() - transform_.position()).normalized();
            // �O�i���Ȃ���v���[���[��x���W�ɋ߂Â�
            velocity_ = GSvector3{ to_player.x, -2.0f, 0.0f }.normalized();
        }
        moving_timer_ = gsRandf(30.0f, 120.0f); // 30�t���[���`60�t���[���̗��������߂�
    }
    moving_timer_ -= delta_time; // �ړ��^�C�}�̍X�V

    // �ړ�����i���[���h���W�n��j
    transform_.translate(velocity_ * delta_time, GStransform::Space::World);

    // �����_���ȊԊu�Œe�𔭎�
    if (shooting_timer_ <= 0.0f) {
        world_->add_actor(
            new EnemyBullet{ world_, transform_.position(), GSvector3{0.0f, -4.0f, 0.0f} });
        shooting_timer_ = gsRandf(20.0f, 60.0f); // 20�`60�̗��������߂�
    }
    shooting_timer_ -= delta_time; // ���˃^�C�}�̍X�V

    // ��ʊO�ł���Ύ��S
    if (world_->field()->is_outside(transform_.position())) {
        die();
    }
}

// �`��
void Enemy::draw() const {
    glPushMatrix();
    glMultMatrixf(transform_.localToWorldMatrix());
    gsDrawMesh(Mesh_Enemy);
    glPopMatrix();
}

// �Փˏ���
void Enemy::react(Actor& other) {
    if (other.tag() == "PlayerTag" || other.tag() == "PlayerBulletTag") {
        // �����G�t�F�N�g�𐶐�
        world_->add_actor(new Explosion{ world_, transform_.position() });
        die();
    }
}

