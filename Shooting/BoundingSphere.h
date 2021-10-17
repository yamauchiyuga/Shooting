#ifndef BOUNDING_SPHERE_H_
#define BOUNDING_SPHERE_H_

#include <gslib.h>

// ���E���N���X
class BoundingSphere {
public:
    // �R���X�g���N�^
    BoundingSphere(float radius = 0.0f, const GSvector3& center = GSvector3{ 0.0f, 0.0f, 0.0f });
    // ���s�ړ�
    BoundingSphere translate(const GSvector3& position) const;
    // ���W�ϊ�
    BoundingSphere transform(const GSmatrix4& matrix) const;
    // �d�Ȃ��Ă��邩�H
    bool intersects(const BoundingSphere& other) const;
    // �f�o�b�O�\��
    void draw() const;

public:
    // ���a
    float       radius{ 0.0f };
    // ���S���W
    GSvector3   center{ 0.0f, 0.0f, 0.0f };
};

#endif

