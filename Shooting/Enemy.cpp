#include "Enemy.h"
#include "IWorld.h"
#include "Assets.h"
#include "Field.h"
#include "EnemyBullet.h"
#include"Explosion.h"

// コンストラクタ
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

// 更新
void Enemy::update(float delta_time) {
    // 敵がｙ軸マイナス方向を向くように回転させる
    transform_.eulerAngles(90.0f, 0.0f, 0.0f);
    // ランダムな間隔でプレーヤーに向かう
    if (moving_timer_ <= 0.0f) {
        Actor* player = world_->find_actor("Player");
        if (player != nullptr) {
            // プレーヤー方向の単位ベクトルを求める
            GSvector3 to_player =
                (player->transform().position() - transform_.position()).normalized();
            // 前進しながらプレーヤーのx座標に近づく
            velocity_ = GSvector3{ to_player.x, -2.0f, 0.0f }.normalized();
        }
        moving_timer_ = gsRandf(30.0f, 120.0f); // 30フレーム～60フレームの乱数を求める
    }
    moving_timer_ -= delta_time; // 移動タイマの更新

    // 移動する（ワールド座標系基準）
    transform_.translate(velocity_ * delta_time, GStransform::Space::World);

    // ランダムな間隔で弾を発射
    if (shooting_timer_ <= 0.0f) {
        world_->add_actor(
            new EnemyBullet{ world_, transform_.position(), GSvector3{0.0f, -4.0f, 0.0f} });
        shooting_timer_ = gsRandf(20.0f, 60.0f); // 20～60の乱数を求める
    }
    shooting_timer_ -= delta_time; // 発射タイマの更新

    // 画面外であれば死亡
    if (world_->field()->is_outside(transform_.position())) {
        die();
    }
}

// 描画
void Enemy::draw() const {
    glPushMatrix();
    glMultMatrixf(transform_.localToWorldMatrix());
    gsDrawMesh(Mesh_Enemy);
    glPopMatrix();
}

// 衝突処理
void Enemy::react(Actor& other) {
    if (other.tag() == "PlayerTag" || other.tag() == "PlayerBulletTag") {
        // 爆発エフェクトを生成
        world_->add_actor(new Explosion{ world_, transform_.position() });
        die();
    }
}

