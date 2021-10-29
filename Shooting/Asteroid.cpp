#include "Asteroid.h"
#include "Assets.h"
#include"IWorld.h"
#include"Field.h"
#include"Explosion.h"

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
    // エリア外に移動したら死亡させる
    if (world_->field()->is_outside(transform_.position())) {
        die();
    }
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
    if (other.tag() == "PlayerTag"||other.tag()=="PlayerBulletTag") {
        // 爆発エフェクトを生成
        world_->add_actor(new Explosion{ world_, transform_.position() });
        die();
    }
}

