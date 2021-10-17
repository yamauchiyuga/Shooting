#include "Asteroid.h"
#include "Assets.h"

// コンストラクタ
Asteroid::Asteroid(IWorld* world, const GSvector3& position, const GSvector3& velocity) {
    world_ = world;
    name_ = "Asteroid";
    tag_ = "EnemyTag";
    transform_.position(position);
    velocity_ = velocity;
    collider_ = BoundingSphere{ 8.0f };
}

// 更新
void Asteroid::update(float delta_time) {
    // 回転させる
    transform_.rotate(2.0f, 0.0f, 0.5f);
    // 移動する（ワールド座標系を基準に移動）
    transform_.translate(velocity_ * delta_time, GStransform::Space::World);
}

// 描画
void Asteroid::draw() const {
    glPushMatrix();
    glMultMatrixf(transform_.localToWorldMatrix());
    gsDrawMesh(Mesh_Asteroid01);
    glPopMatrix();
}

// 衝突処理
void Asteroid::react(Actor& other) {
    if (other.tag() == "PlayerTag") {
        die();
    }
}

