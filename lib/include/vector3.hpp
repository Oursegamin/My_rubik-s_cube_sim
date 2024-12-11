/*
** EPITECH PROJECT, 2024
** My_rubik-s_cube_sim
** File description:
** vector3
*/

#ifndef VECTOR3_HPP_
#define VECTOR3_HPP_

#include <iostream>
#include <math.h>

template<typename T>
class Vector3 {
    int length = 3;

    public:
        T x;
        T y;
        T z;

        Vector3(T x = 0, T y = 0, T z = 0);
        template<typename U>
        Vector3(const Vector3<U> &other);
        ~Vector3();

        T Length();
        Vector3 Normalize();
        Vector3 Cross(const Vector3 &other);
        T Dot(const Vector3 &other);

        T *Get_list() const;

        T &operator[](const int index);
        const T &operator[](const int index) const;
        Vector3 operator+(const Vector3 &other) const;
        Vector3 operator+=(const Vector3 &other);
        Vector3 operator-() const;
        Vector3 operator-(const Vector3 &other) const;
        Vector3 operator-=(const Vector3 &other);
        Vector3 operator*(const T &factor) const;
        Vector3 operator*=(const T &factor);
        Vector3 operator/(const T &factor) const;
        Vector3 operator/=(const T &factor);
        bool operator==(const Vector3 &other) const;
        bool operator!=(const Vector3 &other) const;
        // template<typename U>
        // friend std::ostream operator<<(std::ostream &out, const Vector3<U> &vector);
};

template<typename T>
std::ostream &operator<<(std::ostream &out, const Vector3<T> &vector) {
    out <<
        "x : " << vector.x <<
        ", y : " << vector.y <<
        ", z : " << vector.z;
    return out;
}

typedef Vector3<int>        Vector3i;
typedef Vector3<unsigned>   Vector3u;
typedef Vector3<float>      Vector3f;
typedef Vector3<double>      Vector3d;

#endif /* !VECTOR3_HPP_ */
