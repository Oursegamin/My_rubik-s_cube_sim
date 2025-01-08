/*
** EPITECH PROJECT, 2024
** My_rubik-s_cube_sim
** File description:
** vector4
*/

#include "vector4.hpp"

template class Vector4<int>;
template class Vector4<unsigned>;
template class Vector4<float>;

template<typename T>
Vector4<T>::Vector4(T x, T y, T z, T w)
{
    this->x = x;
    this->y = y;
    this->z = z;
    this->w = w;
}

template<typename T>
template<typename U>
Vector4<T>::Vector4(const Vector4<U> &other) :
    x(static_cast<T>(other.x)),
    y(static_cast<T>(other.y)),
    z(static_cast<T>(other.z)),
    w(static_cast<T>(other.w)) {}

template<typename T>
Vector4<T>::~Vector4() {}

template<typename T>
Vector4<T> Vector4<T>::operator+(const Vector4<T> &other)
{
    return Vector4<T>(
        this->x + other.x,
        this->y + other.y,
        this->z + other.z,
        this->w + other.w
    );
}

template<typename T>
Vector4<T> Vector4<T>::operator+=(const Vector4<T> &other)
{
    this->x += other.x;
    this->y += other.y;
    this->z += other.z;
    this->w += other.w;
    return *this;
}

template<typename T>
Vector4<T> Vector4<T>::operator-()
{
    this->x = -this->x;
    this->y = -this->y;
    this->z = -this->z;
    this->w = -this->w;
    return *this;
}

template<typename T>
Vector4<T> Vector4<T>::operator-(const Vector4<T> &other)
{
    return Vector4<T>(
        this->x - other.x,
        this->y - other.y,
        this->z - other.z,
        this->w - other.w
    );
}

template<typename T>
Vector4<T> Vector4<T>::operator-=(const Vector4<T> &other)
{
    this->x -= other.x;
    this->y -= other.y;
    this->z -= other.z;
    this->w -= other.w;
    return *this;
}

template<typename T>
Vector4<T> Vector4<T>::operator*(const T &factor)
{
    return Vector4<T>(
        this->x * factor,
        this->y * factor,
        this->z * factor,
        this->w * factor
    );
}

template<typename T>
Vector4<T> Vector4<T>::operator*=(const T &factor)
{
    this->x *= factor;
    this->y *= factor;
    this->z *= factor;
    this->w *= factor;
    return *this;
}

template<typename T>
Vector4<T> Vector4<T>::operator/(const T &factor)
{
    if (factor == 0)
        throw std::invalid_argument("Division by zero");
    return Vector4<T>(
        this->x / factor,
        this->y / factor,
        this->z / factor,
        this->w / factor
    );
}

template<typename T>
Vector4<T> Vector4<T>::operator/=(const T &factor)
{
    if (factor == 0)
        throw std::invalid_argument("Division by zero");
    this->x /= factor;
    this->y /= factor;
    this->z /= factor;
    this->w /= factor;
    return *this;
}

template<typename T>
bool Vector4<T>::operator==(const Vector4<T> &other)
{
    return (
        this->x == other.x &&
        this->y == other.y &&
        this->z == other.z &&
        this->w == other.w
    );
}

template<typename T>
bool Vector4<T>::operator!=(const Vector4<T> &other)
{
    return !(*this == other);
}
