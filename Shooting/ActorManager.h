#ifndef ACTOR_MANAGER_H_
#define ACTOR_MANAGER_H_

#include <list>
#include <vector>
#include <string>

class Actor;    // �A�N�^�[�N���X�̑O���錾

// �A�N�^�[�}�l�[�W��
class ActorManager {
public:
    // �f�t�H���g�R���X�g���N�^
    ActorManager() = default;
    // �f�X�g���N�^
    ~ActorManager();
    // �A�N�^�[�̒ǉ�
    void add(Actor* actor);
    // �A�N�^�[�̍X�V
    void update(float delta_time);
    // �A�N�^�[�̒x���X�V
    void late_update(float delta_time);
    // �A�N�^�[�̕`��
    void draw() const;
    // �������A�N�^�[�̕`��
    void draw_transparent() const;
    // �A�N�^�[��GUI�`��
    void draw_gui() const;
    // �A�N�^�[�̏Փ˔���
    void collide();
    // ���S���Ă���A�N�^�[�̍폜
    void remove();
    // �A�N�^�[�̌���
    Actor* find(const std::string& name) const;
    // �w�肵���^�O�������A�N�^�[�̌���
    std::vector<Actor*> find_with_tag(const std::string& tag) const;
    // �A�N�^�[����Ԃ�
    int count() const;
    // �w�肵���^�O�������A�N�^�[����Ԃ�
    int count_with_tag(const std::string& tag) const;
    // ���b�Z�[�W�̑��M
    void send_message(const std::string& message, void* param);
    // ����
    void clear();
    // �R�s�[�֎~
    ActorManager(const ActorManager& other) = delete;
    ActorManager& operator = (const ActorManager& other) = delete;

private:
    // �A�N�^�[���X�g
    std::list<Actor*> actors_;
};

#endif

