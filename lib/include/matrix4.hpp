/*
** EPITECH PROJECT, 2024
** lib
** File description:
** matrix4
*/
#pragma once
#ifndef MATRIX4_HPP_
#define MATRIX4_HPP_

#include <array>
#include "vector3.hpp"
#include "vector4.hpp"

template<typename T>
class Matrix4 {

    public:
        T a11, a12, a13, a14;
        T a21, a22, a23, a24;
        T a31, a32, a33, a34;
        T a41, a42, a43, a44;

        Matrix4(
            T a11 = 1, T a12 = 0, T a13 = 0, T a14 = 0,
            T a21 = 0, T a22 = 1, T a23 = 0, T a24 = 0,
            T a31 = 0, T a32 = 0, T a33 = 1, T a34 = 0,
            T a41 = 0, T a42 = 0, T a43 = 0, T a44 = 1
        );
        Matrix4(const std::array<std::array<T, 4>, 4> matrix);
        Matrix4(const Matrix4 &other);
        template<typename U>
        Matrix4(const Matrix4<U> &other);
        ~Matrix4();

        void Set_identity();

        float Determinant3x3(
            T b11, T b12, T b13,
            T b21, T b22, T b23,
            T b31, T b32, T b33
        ) const;
        float Determinant() const;
        Matrix4 Inverse() const;
        void Transpose();
        void Translate(const Vector3<T> &v);

        void Scale(const Vector3<T> &s);
        void RotateX(const T x);
        void RotateY(const T y);
        void RotateZ(const T z);
        void Rotate(const Vector3<T> &angles);
        void LookAt(const Vector3<T> &eye, const Vector3<T> &center, const Vector3<T> &up);
        void Ortho(const T left, const T right, const T bottom, const T top, const T near, const T far);
        void Frustum(const T left, const T right, const T bottom, const T top, const T near, const T far);
        void Perspective(const T fov, const T aspect, const T near, const T far);
        Vector3f ToEulerAngles() const;

        T *Get_list() const;
        std::array<std::array<T, 4>, 4> Get_matrixed_list() const;

        static Matrix4 Create_identity();
        static Matrix4 Create_translation(const Vector3<T> &t);
        static Matrix4 Create_scale(const T &s);
        static Matrix4 Create_scale(const Vector3<T> &s);
        static Matrix4 Create_rotation(const Vector3<T> &angles);
        static Vector3f ToEulerAngles(const Matrix4<T> &rotation_matrix);

        T &operator()(int row, int column);
        const T &operator()(int row, int column) const;
        Matrix4 operator+(const Matrix4 &other) const;
        void operator+=(const Matrix4 &other);
        Matrix4 operator-() const;
        Matrix4 operator-(const Matrix4 &other) const;
        void operator-=(const Matrix4 &other);
        Matrix4 operator*(const Matrix4 &other) const;
        Vector4<T> operator*(const Vector4<T> &other) const;
        void operator*=(const Matrix4 &other);
        Matrix4 operator/(const T &scalar) const;
        void operator/=(const T &scalar);
        void operator=(const Matrix4 &other);
        template<typename U>
        void operator=(const Matrix4<U> &other);
        bool operator==(const Matrix4 &other) const;
        bool operator!=(const Matrix4 &other) const;
};

template<typename T>
std::ostream &operator<<(std::ostream &out, const Matrix4<T> &vector) {
    out <<
    "[[" << vector.a11 << ", " << vector.a12 << ", " << vector.a13 << ", " << vector.a14 << "]," << std::endl <<
    " [" << vector.a21 << ", " << vector.a22 << ", " << vector.a23 << ", " << vector.a24 << "]," << std::endl <<
    " [" << vector.a31 << ", " << vector.a32 << ", " << vector.a33 << ", " << vector.a34 << "]," << std::endl <<
    " [" << vector.a41 << ", " << vector.a42 << ", " << vector.a43 << ", " << vector.a44 << "]]";
    return out;
}

typedef Matrix4<int>                            Matrix4i;
typedef Matrix4<float>                          Matrix4f;

typedef std::array<std::array<int, 4>, 4>       Matrix4iArray;
typedef std::array<std::array<float, 4>, 4>     Matrix4fArray;

#endif /* !MATRIX4_HPP_ */
