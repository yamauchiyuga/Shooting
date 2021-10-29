#include <GSgame.h>
#include "Assets.h"
#include "ActorManager.h"
#include "Player.h"
#include "Asteroid.h"
#include "Light.h"
#include "Camera.h"
#include "Field.h"
#include "World.h"
#include"Enemy.h"


// ゲームクラス
class MyGame : public gslib::Game {
	// ワールドクラス
	World world_;

	// 開始
	void start() override {
		// メッシュの読み込み
		gsLoadMesh(Mesh_Player, "Assets/Model/vehicle_playerShip.msh");
		gsLoadMesh(Mesh_Asteroid01, "Assets/Model/prop_asteroid_01.msh");
		// 背景用画像の読み込み
		gsLoadTexture(Texture_BgTileNebulaGreen, "Assets/BG/tile_nebula_green_dff.png");
		// プレーヤ弾画像を読み込み
		gsLoadTexture(Texture_EffectLazerOrange, "Assets/Effect/fx_lazer_orange_dff.png");
		// 敵メッシュの読み込み
		gsLoadMesh(Mesh_Enemy, "Assets/Model/vehicle_enemyShip.msh");
		// 敵弾画像を読み込み
		gsLoadTexture(Texture_EffectLazerCyan, "Assets/Effect/fx_lazer_cyan_dff.png");
		// フィールドの追加
		world_.add_field(new Field{ Texture_BgTileNebulaGreen });
		// カメラの追加
		world_.add_camera(new Camera{ &world_ });
		// ライトの追加
		world_.add_light(new Light{ &world_ });
		// プレーヤの追加
		world_.add_actor(new Player{ &world_, GSvector3{ 0.0f, 0.0f, 0.0f } });
		// 隕石を３個追加
		world_.add_actor(new Asteroid{ &world_, GSvector3{ 0.0f , 100.0f, 0.0f }, GSvector3{ 0.0f , -1.0f, 0.0f } });
		world_.add_actor(new Asteroid{ &world_, GSvector3{  30.0f , 100.0f, 0.0f }, GSvector3{ 0.0f , -1.0f, 0.0f } });
		world_.add_actor(new Asteroid{ &world_, GSvector3{ -30.0f , 100.0f, 0.0f }, GSvector3{ 0.0f , -1.0f, 0.0f } });
		//敵を追加
		world_.add_actor(new Enemy{ &world_,GSvector3{-20.0f,100.0f,0.0f} });
	}
	// 更新
	void update(float delta_time) override {
		// ワールドクラスの更新
		world_.update(delta_time);
	}
	// 描画
	void draw() override {
		// ワールドクラスの描画
		world_.draw();
	}
	// 終了
	void end() override {
		// ワールドクラスの消去
		world_.clear();
		// メッシュの削除
		gsDeleteMesh(Mesh_Player);
		gsDeleteMesh(Mesh_Asteroid01);
		// テクスチャの削除
		gsDeleteTexture(Texture_BgTileNebulaGreen);
	}
};

// メイン関数
int main() {
	return MyGame().run();
}
