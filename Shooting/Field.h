#ifndef FIELD_H_
#define FIELD_H_

#include<gslib.h>

//
class Field
{
public:
	//
	Field(GSuint bg);
	//
	void update(float delta_time);
	//
	void draw()const;
	//
	bool is_unsude(const GSvector3& position)const;
	//
	bool is_outside(const GSvector3& position)const;

	//
	Field(const Field& other) = delete;
	Field& operator=(const Field& other) = delete;
private:
	//
	GSuint bg_{ 0 };
	//
	float scroll_{ 0.0f };
};

#endif // !FIELD_H_
