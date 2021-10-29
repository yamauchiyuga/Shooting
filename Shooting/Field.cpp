#include"Field.h"

//�t�B�[���h�T�C�Y
const float FieldSize{ 150.0f };

//�R���X�g���N�^
Field::Field(GSuint bg)
	:bg_{ bg }, scroll_{ 0.0f }{
}

//�X�V
void Field::update(float delta_time) {
	//�X�N���[���l�̍X�V
	scroll_ -= 0.2f * delta_time;
}

//�`��
void Field::draw()const {
	//�w�i�摜�̕`��
	const GSrect src_rect{ 0.0f,scroll_,640.0f,480.0f + scroll_ };
	gsDrawSprite2D(bg_, NULL, &src_rect, NULL, NULL, NULL, 0.0f);
}

//�t�B�[���h����
bool Field::is_inside(const GSvector3& position)const {
	if (ABS(position.x) >= FieldSize)return false;
	if (ABS(position.y) >= FieldSize)return false;
	return true;
}

//�t�B�[���h�O��
bool Field::is_outside(const GSvector3& position)const {
	return !is_inside(position);
}