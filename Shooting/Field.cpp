#include"Field.h"

//
const float FieldSize{ 150.0f };

//
Field::Field(GSuint bg)
	:bg_{bg},scroll_{0.0f}{
}

//
void Field::update(float delta_time) {
	//
	scroll_ -= 0.2f * delta_time;
}