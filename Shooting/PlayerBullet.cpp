#include"PlayerBullet.h"
#include"IWorld.h"
#include"Field.h"
#include"Assets.h"

//
PlayerBullet::PlayerBullet(IWorld* world, const GSvector3& position, const GSvector3& velocity) {
    world_ = world;
    name_ = "PlayerBullet";
    tag_ = "PlayerBulletTag";
    velocity_ = velocity;
    collider_ = BoundingSphere{ 1.0f };
    transform_.position(position);
}

//更新
void PlayerBullet::update(float delta_time) {
    //移動する（ワールド座標系基準）
    transform_.translate(velocity_ * delta_time, GStransform::Space::World);
    //エリア外に移動したら死亡させる

    if (world_->field()->is_outside(transform_.position())) {
        die();
    }

}
    //半透明オブジェクト描画
    void PlayerBullet::draw_transparent()const {
        //加算半透明の指定をしてビルボードを描画
        glPushAttrib(GL_ENABLE_BIT | GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glDisable(GL_LIGHTING);
        glDepthMask(GL_FALSE);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE);
        glEnable(GL_BLEND);
        static const GSrect size{ -5.0f, 5.0f, 5.0f, -5.0f };
        GSvector3 position = transform_.position();
        gsDrawSprite3D(Texture_EffectLazerOrange,
            &position, &size, NULL, NULL, NULL, 0.0f);
        glPopAttrib();
    }

    //衝突判定
    void PlayerBullet::react(Actor& other) {
        if (other.tag() == "EnemyTag") {
            die();
        }
    }