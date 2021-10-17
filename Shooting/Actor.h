#ifndef ACTOR_H_
#define ACTOR_H_

#include <gslib.h>
#include <GStransform.h>
#include <string>
#include "BoundingSphere.h"

class IWorld;   // ���[���h���ۃC���^�[�t�F�[�X�̑O���錾

// �A�N�^�[�N���X
class Actor {
public:
    // �R���X�g���N�^
    Actor() = default;
    // ���z�f�X�g���N�^
    virtual ~Actor() = default;
    // �X�V
    virtual void update(float delta_time);
    // �x���X�V
    virtual void late_update(float delta_time);
    // �`��
    virtual void draw() const;
    // �������̕`��
    virtual void draw_transparent() const;
    // GUI�̕`��
    virtual void draw_gui() const;
    // �Փ˃��A�N�V����
    virtual void react(Actor& other);
    // ���b�Z�[�W����
    virtual void handle_message(const std::string& message, void* param);
    // �Փ˔���
    void collide(Actor& other);
    // ���S����
    void die();
    // �Փ˂��Ă��邩�H
    bool is_collide(const Actor& other) const;
    // ���S���Ă��邩�H
    bool is_dead() const;
    // ���O���擾
    const std::string& name() const;
    // �^�O�����擾
    const std::string& tag() const;
    // �g�����X�t�H�[�����擾(const��)
    const GStransform& transform() const;
    // �g�����X�t�H�[�����擾
    GStransform& transform();
    // �ړ��ʂ��擾
    GSvector3 velocity() const;
    // �Փ˔���f�[�^���擾
    BoundingSphere collider() const;

    // �R�s�[�֎~
    Actor(const Actor& other) = delete;
    Actor& operator = (const Actor& other) = delete;

protected:
    // ���[���h
    IWorld* world_{ nullptr };
    // �^�O��
    std::string     tag_;
    // ���O
    std::string     name_;
    // �g�����X�t�H�[��
    GStransform     transform_;
    // �ړ���
    GSvector3       velocity_{ 0.0f, 0.0f, 0.0f };
    // �Փ˔��肪�L�����H
    bool            enable_collider_{ true };
    // �Փ˔���
    BoundingSphere  collider_;
    // ���S�t���O
    bool            dead_{ false };
};

#endif

