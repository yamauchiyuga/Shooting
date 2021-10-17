#include <GSgame.h>
#include "Assets.h"
#include "ActorManager.h"
#include "Player.h"
#include "Asteroid.h"
#include "Light.h"
#include "Camera.h"

// ゲームクラス
class MyGame : public gslib::Game {
    // カメラクラス
    Camera camera_{ nullptr };
    // ライトクラス
    Light light_{ nullptr };
    // アクターマネージャークラス
    ActorManager manager_;

    // 開始
    void start() override {
        // メッシュの読み込み
        gsLoadMesh(Mesh_Player, "Assets/Model/vehicle_playerShip.msh");
        gsLoadMesh(Mesh_Asteroid01, "Assets/Model/prop_asteroid_01.msh");
        // プレーヤの追加
        manager_.add(new Player{ nullptr, GSvector3{ 0.0f, 0.0f, 0.0f } });
        // 隕石を３個追加
        manager_.add(new Asteroid{ nullptr,
             GSvector3{ 0.0f , 100.0f, 0.0f }, GSvector3{ 0.0f , -1.0f, 0.0f } });
        manager_.add(new Asteroid{ nullptr,
             GSvector3{  30.0f , 100.0f, 0.0f }, GSvector3{ 0.0f , -1.0f, 0.0f } });
        manager_.add(new Asteroid{ nullptr,
             GSvector3{ -30.0f , 100.0f, 0.0f }, GSvector3{ 0.0f , -1.0f, 0.0f } });
    }
    // 更新
    void update(float delta_time) override {
        // アクターの更新
        manager_.update(delta_time);
        // アクター同士の衝突判定
        manager_.collide();
        // アクターの遅延更新
        manager_.late_update(delta_time);
        // 死亡しているアクターの削除
        manager_.remove();
    }
    // 描画
    void draw() override {
        // カメラの設定
        camera_.draw();
        // ライトの設定
        light_.draw();
        // アクターの描画
        manager_.draw();
        // 半透明アクターの描画
        manager_.draw_transparent();
        // GUIの描画
        manager_.draw_gui();
    }
    // 終了
    void end() override {
        // アクターの消去
        manager_.clear();
        // メッシュの削除
        gsDeleteMesh(Mesh_Player);
        gsDeleteMesh(Mesh_Asteroid01);
    }
};

// メイン関数
int main() {
    return MyGame().run();
}





