/*
** EPITECH PROJECT, 2024
** lib
** File description:
** matrix3
*/

#ifndef MATRIX3_HPP_
#define MATRIX3_HPP_

#include <iostream>
#include <array>
#include <math.h>
#include "vector3.hpp"

template<typename T>
class Matrix3
{

    public:
        T a11, a12, a13;
        T a21, a22, a23;
        T a31, a32, a33;

        Matrix3(T a11 = 1, T a12 = 0, T a13 = 0, T a21 = 0, T a22 = 1, T a23 = 0, T a31 = 0, T a32 = 0, T a33 = 1);
        Matrix3(const std::array<std::array<T, 3>, 3> matrix);
        Matrix3(const Matrix3 &other);
        template<typename U>
        Matrix3(const Matrix3<U> &other);
        ~Matrix3();

        Matrix3 Set_identity();
        void Transpose();
        float Determinant() const;
        Matrix3 Inverse() const;
        void Translate(const Vector3<T> &v);
        void Scale(const Vector3<T> &s);
        void RotateX(const T x);
        void RotateY(const T y);
        void RotateZ(const T z);
        void Rotate(const Vector3<T> &angles);

        T *Get_list() const;
        std::array<std::array<T, 3>, 3> Get_matrixed_list() const;

        static Matrix3 Create_identity();
        static Matrix3 Create_translation(const Vector3<T> &v);
        static Matrix3 Create_scale(const T &s);
        static Matrix3 Create_scale(const Vector3<T> &s);
        static Matrix3 Create_rotation(const Vector3<T> &angles);

        Matrix3 operator+(const Matrix3 &other);
        void operator+=(const Matrix3 &other);
        Matrix3 operator-();
        Matrix3 operator-(const Matrix3 &other);
        void operator-=(const Matrix3 &other);
        Matrix3 operator*(const Matrix3 &other);
        void operator*=(const Matrix3 &other);
        // Matrix3 operator/(const Matrix3 &other);
        // void operator/=(const Matrix3 &other);
        void operator=(const Matrix3 &other);
        template<typename U>
        void operator=(const Matrix3<U> &other);
        bool operator==(const Matrix3 &other);
        bool operator!=(const Matrix3 &other);
};

template<typename T>
std::ostream &operator<<(std::ostream &out, const Matrix3<T> &vector) {
    out <<
        "[[" << vector.a11 << ", " << vector.a12 << ", " << vector.a13 << "]," << std::endl <<
        " [" << vector.a21 << ", " << vector.a22 << ", " << vector.a23 << "]," << std::endl <<
        " [" << vector.a31 << ", " << vector.a32 << ", " << vector.a33 << "]]";
    return out;
}

typedef Matrix3<int>        Matrix3i;
typedef Matrix3<float>      Matrix3f;
typedef Matrix3<double>     Matrix3d;

#endif /* !MATRIX3_HPP_ */
