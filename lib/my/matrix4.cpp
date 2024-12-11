/*
** EPITECH PROJECT, 2024
** lib
** File description:
** matrix4
*/

#include "matrix4.hpp"

template class Matrix4<int>;
template class Matrix4<float>;
template Matrix4<float>::Matrix4(const Matrix4<int> &other);
template void Matrix4<float>::operator=<int>(const Matrix4<int> &);

template<typename T>
Matrix4<T>::Matrix4(
    T a11, T a12, T a13, T a14,
    T a21, T a22, T a23, T a24,
    T a31, T a32, T a33, T a34,
    T a41, T a42, T a43, T a44
) : a11(a11), a12(a12), a13(a13), a14(a14),
    a21(a21), a22(a22), a23(a23), a24(a24),
    a31(a31), a32(a32), a33(a33), a34(a34),
    a41(a41), a42(a42), a43(a43), a44(a44) {}

template<typename T>
Matrix4<T>::Matrix4(const std::array<std::array<T, 4>, 4> matrix) {
    a11 = matrix[0][0], a12 = matrix[0][1], a13 = matrix[0][2], a14 = matrix[0][3],
    a21 = matrix[1][0], a22 = matrix[1][1], a23 = matrix[1][2], a24 = matrix[1][3],
    a31 = matrix[2][0], a32 = matrix[2][1], a33 = matrix[2][2], a34 = matrix[2][3],
    a41 = matrix[3][0], a42 = matrix[3][1], a43 = matrix[3][2], a44 = matrix[3][3];
}

template<typename T>
Matrix4<T>::Matrix4(const Matrix4 &other) {
    a11 = other.a11, a12 = other.a12, a13 = other.a13, a14 = other.a14,
    a21 = other.a21, a22 = other.a22, a23 = other.a23, a24 = other.a24,
    a31 = other.a31, a32 = other.a32, a33 = other.a33, a34 = other.a34,
    a41 = other.a41, a42 = other.a42, a43 = other.a43, a44 = other.a44;
}

template<typename T>
template<typename U>
Matrix4<T>::Matrix4(const Matrix4<U> &other) {
    a11 = static_cast<T>(other.a11), a12 = static_cast<T>(other.a12), a13 = static_cast<T>(other.a13), a14 = static_cast<T>(other.a14),
    a21 = static_cast<T>(other.a21), a22 = static_cast<T>(other.a22), a23 = static_cast<T>(other.a23), a24 = static_cast<T>(other.a24),
    a31 = static_cast<T>(other.a31), a32 = static_cast<T>(other.a32), a33 = static_cast<T>(other.a33), a34 = static_cast<T>(other.a34),
    a41 = static_cast<T>(other.a41), a42 = static_cast<T>(other.a42), a43 = static_cast<T>(other.a43), a44 = static_cast<T>(other.a44);
}

template<typename T>
Matrix4<T>::~Matrix4() {}

template<typename T>
void Matrix4<T>::Set_identity() {
    a11 = 1, a12 = 0, a13 = 0, a14 = 0,
    a21 = 0, a22 = 1, a23 = 0, a24 = 0,
    a31 = 0, a32 = 0, a33 = 1, a34 = 0,
    a41 = 0, a42 = 0, a43 = 0, a44 = 1;
}

template<typename T>
void Matrix4<T>::Transpose() {
    std::swap(a21, a12);
    std::swap(a31, a13);
    std::swap(a32, a23);
    std::swap(a41, a14);
    std::swap(a42, a24);
    std::swap(a43, a34);
}

template<typename T>
float Matrix4<T>::Determinant3x3(
    T b11, T b12, T b13,
    T b21, T b22, T b23,
    T b31, T b32, T b33
) const {
    return  b11 * (b22 * b33 - b23 * b32) -
            b12 * (b21 * b33 - b23 * b31) +
            b13 * (b21 * b32 - b22 * b31);
}

template<typename T>
float Matrix4<T>::Determinant() const {
    float m11 = Determinant3x3(a22, a23, a24, a32, a33, a34, a42, a43, a44);
    float m12 = Determinant3x3(a21, a23, a24, a31, a33, a34, a41, a43, a44);
    float m13 = Determinant3x3(a21, a22, a24, a31, a32, a34, a41, a42, a44);
    float m14 = Determinant3x3(a21, a22, a23, a31, a32, a33, a41, a42, a43);

    return a11 * m11 - a12 * m12 + a13 * m13 - a14 * m14;
}

template<typename T>
Matrix4<T> Matrix4<T>::Inverse() const {
    float det = Determinant();
    if (det == 0)
        return Matrix4<T>();

    Matrix4<T> cofactorMatrix(
        Determinant3x3(a22, a23, a24, a32, a33, a34, a42, a43, a44), -Determinant3x3(a12, a13, a14, a32, a33, a34, a42, a43, a44),
        Determinant3x3(a12, a13, a14, a22, a23, a24, a42, a43, a44), -Determinant3x3(a12, a13, a14, a22, a23, a24, a32, a33, a34),

        -Determinant3x3(a21, a23, a24, a31, a33, a34, a41, a43, a44), Determinant3x3(a11, a13, a14, a31, a33, a34, a41, a43, a44),
        -Determinant3x3(a11, a13, a14, a21, a23, a24, a41, a43, a44), Determinant3x3(a11, a13, a14, a21, a23, a24, a31, a33, a34),

        Determinant3x3(a21, a22, a24, a31, a32, a34, a41, a42, a44), -Determinant3x3(a11, a12, a14, a31, a32, a34, a41, a42, a44),
        Determinant3x3(a11, a12, a14, a21, a22, a24, a41, a42, a44), -Determinant3x3(a11, a12, a14, a21, a22, a24, a31, a32, a34),

        -Determinant3x3(a21, a22, a23, a31, a32, a33, a41, a42, a43), Determinant3x3(a11, a12, a13, a31, a32, a33, a41, a42, a43),
        -Determinant3x3(a11, a12, a13, a21, a22, a23, a41, a42, a43), Determinant3x3(a11, a12, a13, a21, a22, a23, a31, a32, a33)
    );

    return cofactorMatrix / det;
}


template<typename T>
void Matrix4<T>::Translate(const Vector3<T> &t) {
    a41 += t.x;
    a42 += t.y;
    a43 += t.z;
}

template<typename T>
void Matrix4<T>::Scale(const Vector3<T> &s) {
    if (s.x == 1 && s.y == 1 && s.z == 1)
        return;

    *this = Create_scale(s) * *this;
}

template<typename T>
void Matrix4<T>::RotateX(T angle) {
    Matrix4<T> rotationMatrix(
        1, 0,          0,          0,
        0, cosf(angle), -sinf(angle), 0,
        0, sinf(angle), cosf(angle),  0,
        0, 0,          0,          1
    );

    *this = rotationMatrix * *this;
}

template<typename T>
void Matrix4<T>::RotateY(T angle) {
    Matrix4<T> rotationMatrix(
        cosf(angle), 0, sinf(angle), 0,
        0,         1, 0,          0,
        -sinf(angle), 0, cosf(angle), 0,
        0,         0, 0,          1
    );

    *this = rotationMatrix * *this;
}

template<typename T>
void Matrix4<T>::RotateZ(T angle) {
    Matrix4<T> rotationMatrix(
        cosf(angle), -sinf(angle), 0,          0,
        sinf(angle), cosf(angle), 0,          0,
        0,          0,         1,          0,
        0,          0,         0,          1
    );

    *this = rotationMatrix * *this;
}

template<typename T>
void Matrix4<T>::Rotate(const Vector3<T> &angles) {
    RotateX(angles.x);
    RotateY(angles.y);
    RotateZ(angles.z);
}

template<typename T>
void Matrix4<T>::LookAt(const Vector3<T> &eye, const Vector3<T> &center, const Vector3<T> &up) {
    Vector3<T> f = eye - center;
    f.Normalize();
    Vector3<T> s = f.Cross(up);
    s.Normalize();
    Vector3<T> u = s.Cross(f);

    a11 = s.x; a12 = u.x; a13 = -f.x; a14 = 0.0f;
    a21 = s.y; a22 = u.y; a23 = -f.y; a24 = 0.0f;
    a31 = s.z; a32 = u.z; a33 = -f.z; a34 = 0.0f;
    a41 = 0.0f; a42 = 0.0f; a43 = 0.0f; a44 = 1.0f;
}

template<typename T>
void Matrix4<T>::Ortho(const T left, const T right, const T bottom, const T top, const T near, const T far) {
    T width = right - left;
    T height = top - bottom;  // y = bottom - top;
    T depth = far - near;

    a11 = 2.0f / width; a12 = 0.0f;             a13 = 0.0f;             a14 = -(right + left) / width;
    a21 = 0.0f;         a22 = 2.0f / height;    a23 = 0.0f;             a24 = -(top + bottom) / height;
    a31 = 0.0f;         a32 = 0.0f;             a33 = -2.0f / depth;    a34 = -(far + near) / depth;
    a41 = 0.0f;         a42 = 0.0f;             a43 = 0.0f;             a44 = 1.0f;
}

template<typename T>
void Matrix4<T>::Frustum(const T left, const T right, const T bottom, const T top, const T near, const T far) {
    T width = right - left;
    T height = bottom - top;  // y = top - bottom;
    T depth = far - near;

    a11 = (2.0f * near) / width;    a12 = 0.0f;                     a13 = (right + left) / width;   a14 = 0.0f;
    a21 = 0.0f;                     a22 = (2.0f * near) / height;   a23 = (top + bottom) / height;  a24 = 0.0f;
    a31 = 0.0f;                     a32 = 0.0f;                     a33 = -(far + near) / depth;    a34 = -(2.0f * far * near) / depth;
    a41 = 0.0f;                     a42 = 0.0f;                     a43 = -1.0f;                    a44 = 0.0f;
}

template<typename T>
void Matrix4<T>::Perspective(const T fov, const T aspect, const T near, const T far) {
    const T height_rate = (near * tan(fov * M_PI / 360.0f));
    const T rate = height_rate * aspect;
    Frustum(-rate, rate, height_rate, -height_rate, near, far);
}

template<typename T>
Vector3f Matrix4<T>::ToEulerAngles() const {
    float sy = sqrt((*this)(0, 0) * (*this)(0, 0) +
        (*this)(1, 0) * (*this)(1, 0));

    bool singular = sy < 1e-6;

    float x, y, z;
    if (!singular) {
        x = atan2((*this)(2, 1), (*this)(2, 2));
        y = atan2(-(*this)(2, 0), sy);
        z = atan2((*this)(1, 0), (*this)(0, 0));
    } else {
        x = atan2(-(*this)(1, 2), (*this)(1, 1));
        y = atan2(-(*this)(2, 0), sy);
        z = 0;
    }

    return Vector3f(x, y, z);
}

template<typename T>
Vector3f Matrix4<T>::ToEulerAngles(const Matrix4<T> &rotation_matrix) {
    float sy = sqrt(rotation_matrix(0, 0) * rotation_matrix(0, 0) +
        rotation_matrix(1, 0) * rotation_matrix(1, 0));

    bool singular = sy < 1e-6;

    float x, y, z;
    if (!singular) {
        x = atan2(rotation_matrix(2, 1), rotation_matrix(2, 2));
        y = atan2(-rotation_matrix(2, 0), sy);
        z = atan2(rotation_matrix(1, 0), rotation_matrix(0, 0));
    } else {
        x = atan2(-rotation_matrix(1, 2), rotation_matrix(1, 1));
        y = atan2(-rotation_matrix(2, 0), sy);
        z = 0;
    }

    return Vector3f(x, y, z);
}

template<typename T>
Vector3<T> Matrix4<T>::TransformDirection(const Vector3<T> &direction) const {
    return Vector3<T>(
        a11 * direction.x + a12 * direction.y + a13 * direction.z,
        a21 * direction.x + a22 * direction.y + a23 * direction.z,
        a31 * direction.x + a32 * direction.y + a33 * direction.z
    );
}

template<typename T>
T *Matrix4<T>::Get_list() const {
    return new T[4 * 4]{
        a11, a12, a13, a14,
        a21, a22, a23, a24,
        a31, a32, a33, a34,
        a41, a42, a43, a44
    };
}

template<typename T>
std::array<std::array<T, 4>, 4> Matrix4<T>::Get_matrixed_list() const {
    return {{
        {a11, a12, a13, a14},
        {a21, a22, a23, a24},
        {a31, a32, a33, a34},
        {a41, a42, a43, a44}
    }};
}

template<typename T>
Matrix4<T> Matrix4<T>::Create_identity() {
    return Matrix4<T> (
        1, 0, 0, 0,
        0, 1, 0, 0,
        0, 0, 1, 0,
        0, 0, 0, 1
    );
}

template<typename T>
Matrix4<T> Matrix4<T>::Create_translation(const Vector3<T> &t) {
    return Matrix4<T> (
        1, 0, 0, 0,
        0, 1, 0, 0,
        0, 0, 1, 0,
        t.x, t.y, t.z, 1
    );
}

template<typename T>
Matrix4<T> Matrix4<T>::Create_scale(const T &s) {
    return Matrix4<T> (
        s, 0, 0, 0,
        0, s, 0, 0,
        0, 0, s, 0,
        0, 0, 0, 1
    );
}

template<typename T>
Matrix4<T> Matrix4<T>::Create_scale(const Vector3<T> &s) {
    return Matrix4<T> (
        s.x, 0, 0, 0,
        0, s.y, 0, 0,
        0, 0, s.z, 0,
        0, 0, 0, 1
    );
}

template<typename T>
Matrix4<T> Matrix4<T>::Create_rotation(const Vector3<T> &angles) {
    Matrix4<T> rotate;
    rotate.Rotate(angles);
    return rotate;
}


//=============================================================================
// OPERATORS


template<typename T>
T &Matrix4<T>::operator()(int row, int column) {
    T *list = Get_list();
    return list[row * 4 + column];
}

template<typename T>
const T &Matrix4<T>::operator()(int row, int column) const {
    T *list = Get_list();
    return list[row * 4 + column];
}

template<typename T>
Matrix4<T> Matrix4<T>::operator+(const Matrix4<T> &other) const {
    return Matrix4<T> (
        a11 + other.a11, a12 + other.a12, a13 + other.a13, a14 + other.a14,
        a21 + other.a21, a22 + other.a22, a23 + other.a23, a24 + other.a24,
        a31 + other.a31, a32 + other.a32, a33 + other.a33, a34 + other.a34,
        a41 + other.a41, a42 + other.a42, a43 + other.a43, a44 + other.a44
    );
}

template<typename T>
void Matrix4<T>::operator+=(const Matrix4<T> &other) {
    *this = *this + other;
}

template<typename T>
Matrix4<T> Matrix4<T>::operator-() const {
    return Matrix4<T> (
        -a11, -a12, -a13, -a14,
        -a21, -a22, -a23, -a24,
        -a31, -a32, -a33, -a34,
        -a41, -a42, -a43, -a44
    );
}

template<typename T>
Matrix4<T> Matrix4<T>::operator-(const Matrix4<T> &other) const {
    return *this + (-other);
}

template<typename T>
void Matrix4<T>::operator-=(const Matrix4<T> &other) {
    *this = *this - other;
}

template<typename T>
Matrix4<T> Matrix4<T>::operator*(const Matrix4<T> &other) const {
    return Matrix4<T> (
		a11 * other.a11 + a12 * other.a21 + a13 * other.a31 + a14 * other.a41,
		a11 * other.a12 + a12 * other.a22 + a13 * other.a32 + a14 * other.a42,
		a11 * other.a13 + a12 * other.a23 + a13 * other.a33 + a14 * other.a43,
		a11 * other.a14 + a12 * other.a24 + a13 * other.a34 + a14 * other.a44,
		a21 * other.a11 + a22 * other.a21 + a23 * other.a31 + a24 * other.a41,
		a21 * other.a12 + a22 * other.a22 + a23 * other.a32 + a24 * other.a42,
		a21 * other.a13 + a22 * other.a23 + a23 * other.a33 + a24 * other.a43,
		a21 * other.a14 + a22 * other.a24 + a23 * other.a34 + a24 * other.a44,
		a31 * other.a11 + a32 * other.a21 + a33 * other.a31 + a34 * other.a41,
		a31 * other.a12 + a32 * other.a22 + a33 * other.a32 + a34 * other.a42,
		a31 * other.a13 + a32 * other.a23 + a33 * other.a33 + a34 * other.a43,
		a31 * other.a14 + a32 * other.a24 + a33 * other.a34 + a34 * other.a44,
		a41 * other.a11 + a42 * other.a21 + a43 * other.a31 + a44 * other.a41,
		a41 * other.a12 + a42 * other.a22 + a43 * other.a32 + a44 * other.a42,
		a41 * other.a13 + a42 * other.a23 + a43 * other.a33 + a44 * other.a43,
		a41 * other.a14 + a42 * other.a24 + a43 * other.a34 + a44 * other.a44
    );
}

template<typename T>
Vector4<T> Matrix4<T>::operator*(const Vector4<T> &other) const {
    return Vector4<T> (
        a11 * other.x + a12 * other.y + a13 * other.z + a14 * other.w,
        a21 * other.x + a22 * other.y + a23 * other.z + a24 * other.w,
        a31 * other.x + a32 * other.y + a33 * other.z + a34 * other.w,
        a41 * other.x + a42 * other.y + a43 * other.z + a44 * other.w
    );
}

template<typename T>
void Matrix4<T>::operator*=(const Matrix4<T> &other) {
    *this = *this * other;
}

template<typename T>
Matrix4<T> Matrix4<T>::operator/(const T &scalar) const {
    return Matrix4<T> (
        a11 / scalar, a12 / scalar, a13 / scalar, a14 / scalar,
        a21 / scalar, a22 / scalar, a23 / scalar, a24 / scalar,
        a31 / scalar, a32 / scalar, a33 / scalar, a34 / scalar,
        a41 / scalar, a42 / scalar, a43 / scalar, a44 / scalar
    );
}

template<typename T>
void Matrix4<T>::operator/=(const T &scalar) {
    *this = *this / scalar;
}

template<typename T>
void Matrix4<T>::operator=(const Matrix4 &other) {
    a11 = other.a11, a12 = other.a12, a13 = other.a13, a14 = other.a14;
    a21 = other.a21, a22 = other.a22, a23 = other.a23, a24 = other.a24;
    a31 = other.a31, a32 = other.a32, a33 = other.a33, a34 = other.a34;
    a41 = other.a41, a42 = other.a42, a43 = other.a43, a44 = other.a44;
}

template<typename T>
template<typename U>
void Matrix4<T>::operator=(const Matrix4<U> &other) {
    a11 = static_cast<T>(other.a11), a12 = static_cast<T>(other.a12), a13 = static_cast<T>(other.a13), a14 = static_cast<T>(other.a14);
    a21 = static_cast<T>(other.a21), a22 = static_cast<T>(other.a22), a23 = static_cast<T>(other.a23), a24 = static_cast<T>(other.a24);
    a31 = static_cast<T>(other.a31), a32 = static_cast<T>(other.a32), a33 = static_cast<T>(other.a33), a34 = static_cast<T>(other.a34);
    a41 = static_cast<T>(other.a41), a42 = static_cast<T>(other.a42), a43 = static_cast<T>(other.a43), a44 = static_cast<T>(other.a44);
}

template<typename T>
bool Matrix4<T>::operator==(const Matrix4 &other) const {
    return (
        a11 == other.a11 && a12 == other.a12 && a13 == other.a13 && a14 == other.a14 &&
        a21 == other.a21 && a22 == other.a22 && a23 == other.a23 && a24 == other.a24 &&
        a31 == other.a31 && a32 == other.a32 && a33 == other.a33 && a34 == other.a34 &&
        a41 == other.a41 && a42 == other.a42 && a43 == other.a43 && a44 == other.a44
    );
}

template<typename T>
bool Matrix4<T>::operator!=(const Matrix4 &other) const {
    return !(*this == other);
}
