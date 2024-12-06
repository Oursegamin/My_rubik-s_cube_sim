/*
** EPITECH PROJECT, 2024
** My_rubik-s_cube_sim
** File description:
** vector4
*/

#ifndef VECTOR4_HPP_
#define VECTOR4_HPP_

#include <iostream>

template<typename T>
class Vector4 {
    public:
        T x;
        T y;
        T z;
        T w;

        Vector4(T x = 0, T y = 0, T z = 0, T w = 0);
        template<typename U>
        Vector4(const Vector4<U> &other);
        ~Vector4();

        Vector4 operator+(const Vector4<T> &other);
        Vector4 operator+=(const Vector4<T> &other);
        Vector4 operator-();
        Vector4 operator-(const Vector4<T> &other);
        Vector4 operator-=(const Vector4<T> &other);
        Vector4 operator*(const T &factor);
        Vector4 operator*=(const T &factor);
        Vector4 operator/(const T &factor);
        Vector4 operator/=(const T &factor);
        bool operator==(const Vector4<T> &other);
        bool operator!=(const Vector4<T> &other);
        // template<typename U>
        // friend std::ostream operator<<(std::ostream &out, const Vector4<U> &vector);
};

template<typename T>
std::ostream &operator<<(std::ostream &out, const Vector4<T> &vector) {
    out <<
        "x : " << vector.x <<
        ", y : " << vector.y <<
        ", z : " << vector.z <<
        ", w : " << vector.w;
    return out;
}

typedef Vector4<int>        Vector4i;
typedef Vector4<unsigned>   Vector4u;
typedef Vector4<float>      Vector4f;

#endif /* !VECTOR3_HPP_ */
