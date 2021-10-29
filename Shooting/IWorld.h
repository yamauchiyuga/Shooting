#ifndef IWORLD_H_
#define IWORLD_H_

#include<string>
#include<vector>

class Actor;
class Field;

//���[���h���ۃC���^�[�t�F�[�X
class IWorld {
public:
	//���z�f�X�g���N�^
	virtual ~IWorld() = default;

	//�A�N�^�[�ǉ�
	virtual void add_actor(Actor* actor) = 0;
	//�A�N�^�[����
	virtual Actor* find_actor(const std::string& name) const = 0;
	//�w�肵���^�O�������A�N�^�[�̌���
	virtual std::vector<Actor*> find_actor_with_tag(const std::string& tag)const = 0;
	//�A�N�^�[����Ԃ�
	virtual int count_actor()const = 0;
	//�w�肵���^�O�������A�N�^�[��Ԃ�
	virtual int count_actor_with_tag(const std::string& tag)const = 0;
	//���b�Z�[�W���M
	virtual void send_message(const std::string& message, void* param = nullptr) = 0;

	// �t�B�[���h�̎擾
	virtual Field* field() = 0;
	// �J�����̎擾
	virtual Actor* camera() = 0;
	// ���C�g�̎擾
	virtual Actor* light() = 0;

};
#endif // !1

