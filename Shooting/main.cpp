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


// �Q�[���N���X
class MyGame : public gslib::Game {
	// ���[���h�N���X
	World world_;

	// �J�n
	void start() override {
		// ���b�V���̓ǂݍ���
		gsLoadMesh(Mesh_Player, "Assets/Model/vehicle_playerShip.msh");
		gsLoadMesh(Mesh_Asteroid01, "Assets/Model/prop_asteroid_01.msh");
		// �w�i�p�摜�̓ǂݍ���
		gsLoadTexture(Texture_BgTileNebulaGreen, "Assets/BG/tile_nebula_green_dff.png");
		// �v���[���e�摜��ǂݍ���
		gsLoadTexture(Texture_EffectLazerOrange, "Assets/Effect/fx_lazer_orange_dff.png");
		// �G���b�V���̓ǂݍ���
		gsLoadMesh(Mesh_Enemy, "Assets/Model/vehicle_enemyShip.msh");
		// �G�e�摜��ǂݍ���
		gsLoadTexture(Texture_EffectLazerCyan, "Assets/Effect/fx_lazer_cyan_dff.png");
		// �t�B�[���h�̒ǉ�
		world_.add_field(new Field{ Texture_BgTileNebulaGreen });
		// �J�����̒ǉ�
		world_.add_camera(new Camera{ &world_ });
		// ���C�g�̒ǉ�
		world_.add_light(new Light{ &world_ });
		// �v���[���̒ǉ�
		world_.add_actor(new Player{ &world_, GSvector3{ 0.0f, 0.0f, 0.0f } });
		// 覐΂��R�ǉ�
		world_.add_actor(new Asteroid{ &world_, GSvector3{ 0.0f , 100.0f, 0.0f }, GSvector3{ 0.0f , -1.0f, 0.0f } });
		world_.add_actor(new Asteroid{ &world_, GSvector3{  30.0f , 100.0f, 0.0f }, GSvector3{ 0.0f , -1.0f, 0.0f } });
		world_.add_actor(new Asteroid{ &world_, GSvector3{ -30.0f , 100.0f, 0.0f }, GSvector3{ 0.0f , -1.0f, 0.0f } });
		//�G��ǉ�
		world_.add_actor(new Enemy{ &world_,GSvector3{-20.0f,100.0f,0.0f} });
	}
	// �X�V
	void update(float delta_time) override {
		// ���[���h�N���X�̍X�V
		world_.update(delta_time);
	}
	// �`��
	void draw() override {
		// ���[���h�N���X�̕`��
		world_.draw();
	}
	// �I��
	void end() override {
		// ���[���h�N���X�̏���
		world_.clear();
		// ���b�V���̍폜
		gsDeleteMesh(Mesh_Player);
		gsDeleteMesh(Mesh_Asteroid01);
		// �e�N�X�`���̍폜
		gsDeleteTexture(Texture_BgTileNebulaGreen);
	}
};

// ���C���֐�
int main() {
	return MyGame().run();
}
