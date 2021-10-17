#include <GSgame.h>
#include "Assets.h"
#include "ActorManager.h"
#include "Player.h"
#include "Asteroid.h"
#include "Light.h"
#include "Camera.h"

// �Q�[���N���X
class MyGame : public gslib::Game {
    // �J�����N���X
    Camera camera_{ nullptr };
    // ���C�g�N���X
    Light light_{ nullptr };
    // �A�N�^�[�}�l�[�W���[�N���X
    ActorManager manager_;

    // �J�n
    void start() override {
        // ���b�V���̓ǂݍ���
        gsLoadMesh(Mesh_Player, "Assets/Model/vehicle_playerShip.msh");
        gsLoadMesh(Mesh_Asteroid01, "Assets/Model/prop_asteroid_01.msh");
        // �v���[���̒ǉ�
        manager_.add(new Player{ nullptr, GSvector3{ 0.0f, 0.0f, 0.0f } });
        // 覐΂��R�ǉ�
        manager_.add(new Asteroid{ nullptr,
             GSvector3{ 0.0f , 100.0f, 0.0f }, GSvector3{ 0.0f , -1.0f, 0.0f } });
        manager_.add(new Asteroid{ nullptr,
             GSvector3{  30.0f , 100.0f, 0.0f }, GSvector3{ 0.0f , -1.0f, 0.0f } });
        manager_.add(new Asteroid{ nullptr,
             GSvector3{ -30.0f , 100.0f, 0.0f }, GSvector3{ 0.0f , -1.0f, 0.0f } });
    }
    // �X�V
    void update(float delta_time) override {
        // �A�N�^�[�̍X�V
        manager_.update(delta_time);
        // �A�N�^�[���m�̏Փ˔���
        manager_.collide();
        // �A�N�^�[�̒x���X�V
        manager_.late_update(delta_time);
        // ���S���Ă���A�N�^�[�̍폜
        manager_.remove();
    }
    // �`��
    void draw() override {
        // �J�����̐ݒ�
        camera_.draw();
        // ���C�g�̐ݒ�
        light_.draw();
        // �A�N�^�[�̕`��
        manager_.draw();
        // �������A�N�^�[�̕`��
        manager_.draw_transparent();
        // GUI�̕`��
        manager_.draw_gui();
    }
    // �I��
    void end() override {
        // �A�N�^�[�̏���
        manager_.clear();
        // ���b�V���̍폜
        gsDeleteMesh(Mesh_Player);
        gsDeleteMesh(Mesh_Asteroid01);
    }
};

// ���C���֐�
int main() {
    return MyGame().run();
}





