#include"ExplosionPartFire.h"
#include"Assets.h"
#include<GSeasing.h>

const float MoveTime{ 16.0f };

// コンストラクタ
ExplosionPartFire::ExplosionPartFire(IWorld* world, const GSvector3& position, const GSvector3& velocity) {
	world_ = world;
	name_ = "ExplosionPartFire";
	tag_ = "EffectTag";
	velocity_ = velocity;
	transform_.position(position);
}

//
void ExplosionPartFire::update(float delta_time) {
	//
	transform_.translate(velocity_ * delta_time, GStransform::Space::World);
	//
	if (timer_ > MoveTime) {
		die();
	}
	timer_ += delta_time;
}

//
void ExplosionPartFire::draw_transparent()const {
	//OpenGLの各種設定を退避
	glPushAttrib(GL_ENABLE_BIT | GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//ライティング無効
    glDisable(GL_LIGHTING);
    // 加算ブレンドの指定
    glBlendFunc(GL_SRC_ALPHA, GL_ONE);
    // タイマ値から線形補間の補間値(0.0 ~ 1.0)を計算
    float t = timer_ / MoveTime;
    // ビルボードのサイズ
    static const GSrect body{ -5.0f, 0.0f, 5.0f, -10.0f };
    // 開始色
    static const GScolor start_color{ 1.0f, 1.0f, 1.0f, 1.0f };
    // 終了色
    static const GScolor end_color{ 1.0f, 0.5f, 0.5f, 0.0f };
    // 線形補間で、だんだんと透明にする
    GScolor color = GScolor::lerp(start_color, end_color, gsEasingInExpo(t));
    // 開始スケール値
    static const GSvector2 start_scale{ 1.0f, 1.0f };
    // 終了スケール値
    static const GSvector2 end_scale{ 1.0f, 1.5f };
    // 縦方向に、だんだんと拡大する
    GSvector2 scale = GSvector2::lerp(start_scale, end_scale, t);
    // 移動方向の角度を求める（画像が縦長で上方向を向いているので、-90度補正する）
    float angle = GSvector2(velocity_.x, velocity_.y).getDirection() - 90.0f;
    GSvector3 position = transform_.position();
    // ビルボードの描画
    gsDrawSprite3D(Texture_EffectLazerOrange,&position, &body, NULL, &color, &scale, angle);
    // OpenGLの各種設定を復帰
    glPopAttrib();
}
