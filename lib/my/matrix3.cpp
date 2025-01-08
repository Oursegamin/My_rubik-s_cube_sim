/*
** EPITECH PROJECT, 2024
** lib
** File description:
** matrix3
*/

#include "matrix3.hpp"

template class Matrix3<int>;
template class Matrix3<float>;
template class Matrix3<double>;
template Matrix3<float>::Matrix3(const Matrix3<int> &other);
template void Matrix3<float>::operator=<int>(const Matrix3<int> &);

template<typename T>
Matrix3<T>::Matrix3(
    T a11, T a12, T a13,
    T a21, T a22, T a23,
    T a31, T a32, T a33
) :
    a11(a11), a12(a12), a13(a13),
    a21(a21), a22(a22), a23(a23),
    a31(a31), a32(a32), a33(a33) {}

template<typename T>
Matrix3<T>::Matrix3(const std::array<std::array<T, 3>, 3> matrix)
{
    a11 = matrix[0][0], a12 = matrix[0][1], a13 = matrix[0][2],
    a21 = matrix[1][0], a22 = matrix[1][1], a23 = matrix[1][2],
    a31 = matrix[2][0], a32 = matrix[2][1], a33 = matrix[2][2];
}

template<typename T>
Matrix3<T>::Matrix3(const Matrix3 &other)
{
    a11 = other.a11, a12 = other.a12, a13 = other.a13,
    a21 = other.a21, a22 = other.a22, a23 = other.a23,
    a31 = other.a31, a32 = other.a32, a33 = other.a33;
}

template<typename T>
template<typename U>
Matrix3<T>::Matrix3(const Matrix3<U> &other)
{
    a11 = other.a11, a12 = other.a12, a13 = other.a13,
    a21 = other.a21, a22 = other.a22, a23 = other.a23,
    a31 = other.a31, a32 = other.a32, a33 = other.a33;
}

template<typename T>
Matrix3<T>::~Matrix3() {}

template<typename T>
Matrix3<T> Matrix3<T>::Set_identity()
{
    a11 = 1, a12 = 0, a13 = 0;
    a21 = 0, a22 = 1, a23 = 0;
    a31 = 0, a32 = 0, a33 = 1;
    return *this;
}

template<typename T>
void Matrix3<T>::Transpose()
{
    std::swap(a12, a21);
    std::swap(a13, a31);
    std::swap(a23, a32);
}

template<typename T>
float Matrix3<T>::Determinant() const
{
    return (a11 * (a22 * a33 - a23 * a32)) -
           (a12 * (a21 * a33 - a23 * a31)) +
           (a13 * (a21 * a32 - a22 * a31));
}

template<typename T>
Matrix3<T> Matrix3<T>::Inverse() const
{
    float det = Determinant();
    if (det == 0)
        return Matrix3<T>();

    return Matrix3<T> (
        (a22 * a33 - a23 * a32) / det, -(a12 * a33 - a13 * a32) / det, (a12 * a23 - a13 * a22) / det,
        -(a21 * a33 - a23 * a31) / det, (a11 * a33 - a13 * a31) / det, -(a11 * a23 - a13 * a21) / det,
        (a21 * a32 - a22 * a31) / det, -(a11 * a32 - a12 * a31) / det, (a11 * a22 - a12 * a21) / det
    );
}

template<typename T>
void Matrix3<T>::Translate(const Vector3<T> &v)
{
	if (v.x == 0 && v.y == 0)
        return;

	this->a13 += this->a11 * v.x + this->a12 * v.y;
	this->a23 += this->a21 * v.x + this->a22 * v.y;
	this->a33 += this->a31 * v.x + this->a32 * v.y;
}

template<typename T>
void Matrix3<T>::Scale(const Vector3<T> &s)
{
    if (s.x == 1 && s.y == 1 && s.z == 1)
        return;

    this->a11 *= s.x, this->a12 *= s.x, this->a13 *= s.x;
    this->a21 *= s.y, this->a22 *= s.y, this->a23 *= s.y;
    this->a31 *= s.z, this->a32 *= s.z, this->a33 *= s.z;
}

template<typename T>
void Matrix3<T>::RotateX(const T x)
{
    Matrix3<T> rotation(
        1, 0, 0,
        0, cos(x), -sin(x),
        0, sin(x), cos(x)
    );
    *this *= rotation;
}

template<typename T>
void Matrix3<T>::RotateY(const T y)
{
    Matrix3<T> rotation(
        cos(y), 0, sin(y),
        0, 1, 0,
        -sin(y), 0, cos(y)
    );
    *this *= rotation;
}

template<typename T>
void Matrix3<T>::RotateZ(const T z)
{
    Matrix3<T> rotation(
        cos(z), -sin(z), 0,
        sin(z), cos(z), 0,
        0, 0, 1
    );
    *this *= rotation;
}

template<typename T>
void Matrix3<T>::Rotate(const Vector3<T> &angles)
{
    RotateX(angles.x);
    RotateY(angles.y);
    RotateZ(angles.z);
}

template<typename T>
T *Matrix3<T>::Get_list() const
{
    return new T[3 * 3]{
        a11, a12, a13,
        a21, a22, a23,
        a31, a32, a33
    };
}

template<typename T>
std::array<std::array<T, 3>, 3> Matrix3<T>::Get_matrixed_list() const
{
    return {{
        {a11, a12, a13},
        {a21, a22, a23},
        {a31, a32, a33}
    }};
}

template<typename T>
Matrix3<T> Matrix3<T>::Create_identity()
{
    return Matrix3<T> (
        1, 0, 0,
        0, 1, 0,
        0, 0, 1
    );
}

template<typename T>
Matrix3<T> Matrix3<T>::Create_translation(const Vector3<T> &v)
{
    return Matrix3<T> (
        1, 0, 0,
        0, 1, 0,
        v.x, v.y, 1
    );
}

template<typename T>
Matrix3<T> Matrix3<T>::Create_scale(const T &s)
{
    return Matrix3<T> (
        s, 0, 0,
        0, s, 0,
        0, 0, 1
    );
}

template<typename T>
Matrix3<T> Matrix3<T>::Create_scale(const Vector3<T> &s)
{
    return Matrix3<T> (
        s.x, 0, 0,
        0, s.y, 0,
        0, 0, 1
    );
}

template<typename T>
Matrix3<T> Matrix3<T>::Create_rotation(const Vector3<T> &angles)
{
    Matrix3<T> mat = Matrix3<T>::Create_identity();
    mat.Rotate(angles);
    return mat;
}


//=============================================================================
// OPERATORS


template<typename T>
Matrix3<T> Matrix3<T>::operator+(const Matrix3<T> &other)
{
    return Matrix3<T> (
        a11 + other.a11, a12 + other.a12, a13 + other.a13,
        a21 + other.a21, a22 + other.a22, a23 + other.a23,
        a31 + other.a31, a32 + other.a32, a33 + other.a33
    );
}

template<typename T>
void Matrix3<T>::operator+=(const Matrix3<T> &other)
{
    a11 += other.a11, a12 += other.a12, a13 += other.a13;
    a21 += other.a21, a22 += other.a22, a23 += other.a23;
    a31 += other.a31, a32 += other.a32, a33 += other.a33;
}

template<typename T>
Matrix3<T> Matrix3<T>::operator-()
{
    return Matrix3<T> (
        -a11, -a12, -a13,
        -a21, -a22, -a23,
        -a31, -a32, -a33
    );
}

template<typename T>
Matrix3<T> Matrix3<T>::operator-(const Matrix3<T> &other)
{
    return Matrix3<T> (
        a11 - other.a11, a12 - other.a12, a13 - other.a13,
        a21 - other.a21, a22 - other.a22, a23 - other.a23,
        a31 - other.a31, a32 - other.a32, a33 - other.a33
    );
}

template<typename T>
void Matrix3<T>::operator-=(const Matrix3<T> &other)
{
    a11 -= other.a11, a12 -= other.a12, a13 -= other.a13;
    a21 -= other.a21, a22 -= other.a22, a23 -= other.a23;
    a31 -= other.a31, a32 -= other.a32, a33 -= other.a33;
}

template<typename T>
Matrix3<T> Matrix3<T>::operator*(const Matrix3<T> &other)
{
    return Matrix3<T> (
        a11 * other.a11 + a12 * other.a21 + a13 * other.a31,
        a11 * other.a12 + a12 * other.a22 + a13 * other.a32,
        a11 * other.a13 + a12 * other.a23 + a13 * other.a33,

        a21 * other.a11 + a22 * other.a21 + a23 * other.a31,
        a21 * other.a12 + a22 * other.a22 + a23 * other.a32,
        a21 * other.a13 + a22 * other.a23 + a23 * other.a33,

        a31 * other.a11 + a32 * other.a21 + a33 * other.a31,
        a31 * other.a12 + a32 * other.a22 + a33 * other.a32,
        a31 * other.a13 + a32 * other.a23 + a33 * other.a33
    );
}

template<typename T>
void Matrix3<T>::operator*=(const Matrix3<T> &other)
{
    *this = *this * other;
}

// template<typename T>
// Matrix3<T> Matrix3<T>::operator/(const Matrix3<T> &other) {
//     Matrix3<T> inv = other.Inverse();
//     if (inv == *other)
//         return Transpose();

//     return *this * other;
// }

// template<typename T>
// void Matrix3<T>::operator/=(const Matrix3<T> &other) {
//     *this = *this / other;
// }

template<typename T>
void Matrix3<T>::operator=(const Matrix3 &other)
{
    a11 = other.a11, a12 = other.a12, a13 = other.a13;
    a21 = other.a21, a22 = other.a22, a23 = other.a23;
    a31 = other.a31, a32 = other.a32, a33 = other.a33;
}

template<typename T>
template<typename U>
void Matrix3<T>::operator=(const Matrix3<U> &other)
{
    a11 = static_cast<T>(other.a11), a12 = static_cast<T>(other.a12), a13 = static_cast<T>(other.a13);
    a21 = static_cast<T>(other.a21), a22 = static_cast<T>(other.a22), a23 = static_cast<T>(other.a23);
    a31 = static_cast<T>(other.a31), a32 = static_cast<T>(other.a32), a33 = static_cast<T>(other.a33);
}

template<typename T>
bool Matrix3<T>::operator==(const Matrix3 &other)
{
    return (
        a11 == other.a11 && a12 == other.a12 && a13 == other.a13 &&
        a21 == other.a21 && a22 == other.a22 && a23 == other.a23 &&
        a31 == other.a31 && a32 == other.a32 && a33 == other.a33
    );
}

// template<typename T>
// template<typename U, typename std::enable_if<!std::is_same<T, U>::value, int>::type>
// bool Matrix3<T>::operator==(const Matrix3<U> &other) {
//     return (
//         a11 == other.a11 && a12 == other.a12 && a13 == other.a13 &&
//         a21 == other.a21 && a22 == other.a22 && a23 == other.a23 &&
//         a31 == other.a31 && a32 == other.a32 && a33 == other.a33
//     );
// }

template<typename T>
bool Matrix3<T>::operator!=(const Matrix3 &other)
{
    return!(*this == other);
}
