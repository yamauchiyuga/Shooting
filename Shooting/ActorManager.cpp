#include "ActorManager.h"
#include "Actor.h"

// �f�X�g���N�^
ActorManager::~ActorManager() {
    clear();
}

// �A�N�^�[�̒ǉ�
void ActorManager::add(Actor* actor) {
    actors_.push_back(actor);
}

// �A�N�^�[�̍X�V
void ActorManager::update(float delta_time) {
    for (auto actor : actors_) {
        actor->update(delta_time);
    }
}

// �A�N�^�[�̒x���X�V
void ActorManager::late_update(float delta_time) {
    for (auto actor : actors_) {
        actor->late_update(delta_time);
    }
}

// �A�N�^�[�̕`��
void ActorManager::draw() const {
    for (auto actor : actors_) {
        actor->draw();
    }
}

// �������A�N�^�[�̕`��
void ActorManager::draw_transparent() const {
    for (auto actor : actors_) {
        actor->draw_transparent();
    }
}

// �A�N�^�[��GUI�`�� 
void ActorManager::draw_gui() const {
    for (auto actor : actors_) {
        actor->draw_gui();
    }
}

// �A�N�^�[�̏Փ˔���
void ActorManager::collide() {
    for (auto i = actors_.begin(); i != actors_.end(); ++i) {
        for (auto j = std::next(i); j != actors_.end(); ++j) {
            (*i)->collide(**j);
        }
    }
}

// ���S���Ă���A�N�^�[�̍폜
void ActorManager::remove() {
    for (auto i = actors_.begin(); i != actors_.end(); ) {
        if ((*i)->is_dead()) {
            delete* i;
            i = actors_.erase(i);
        }
        else {
            ++i;
        }
    }
}

// �A�N�^�[�̌���
Actor* ActorManager::find(const std::string& name) const {
    for (auto actor : actors_) {
        if (actor->name() == name) {
            return actor;
        }
    }
    return nullptr;
}

// �w�肵���^�O�������A�N�^�[�̌���
std::vector<Actor*> ActorManager::find_with_tag(const std::string& tag) const {
    std::vector<Actor*> result;
    for (auto actor : actors_) {
        if (actor->tag() == tag) {
            result.push_back(actor);
        }
    }
    return result;
}

// �A�N�^�[����Ԃ�
int ActorManager::count() const {
    return (int)actors_.size();
}

// �w�肵���^�O�̃A�N�^�[����Ԃ�
int ActorManager::count_with_tag(const std::string& tag) const {
    int result = 0;
    for (auto actor : actors_) {
        if (actor->tag() == tag) {
            ++result;
        }
    }
    return result;
}

// ���b�Z�[�W�̑��M
void ActorManager::send_message(const std::string& message, void* param) {
    for (auto actor : actors_) {
        actor->handle_message(message, param);
    }
}

// ����
void ActorManager::clear() {
    for (auto actor : actors_) {
        delete actor;
    }
    actors_.clear();
}

