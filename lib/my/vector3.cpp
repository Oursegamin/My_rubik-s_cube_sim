/*
** EPITECH PROJECT, 2024
** My_rubik-s_cube_sim
** File description:
** vector3
*/

#include "vector3.hpp"

template class Vector3<int>;
template class Vector3<unsigned>;
template class Vector3<float>;

template<typename T>
Vector3<T>::Vector3(T x, T y, T z) : x(x), y(y), z(z) {}

template<typename T>
template<typename U>
Vector3<T>::Vector3(const Vector3<U> &other) :
    x(static_cast<T>(other.x)),
    y(static_cast<T>(other.y)),
    z(static_cast<T>(other.z)) {}

template<typename T>
Vector3<T>::~Vector3() {}

template<typename T>
inline T Vector3<T>::Length() {
    return sqrtf(x * x + y * y + z * z);
}

template<typename T>
inline Vector3<T> Vector3<T>::Normalize() {
    T length = Length();
    if (length == 0)
        return Vector3<T>(0, 0, 0);
    return Vector3<T>(x / length, y / length, z / length);
}

template<typename T>
inline Vector3<T> Vector3<T>::Cross(const Vector3<T> &other) {
    return Vector3<T>(
        y * other.z - z * other.y,
        z * other.x - x * other.z,
        x * other.y - y * other.x
    );
}

template<typename T>
inline T Vector3<T>::Dot(const Vector3<T> &other) {
    return x * other.x + y * other.y + z * other.z;
}

template<typename T>
inline Vector3<T> Vector3<T>::operator+(const Vector3<T> &other) const {
    return Vector3<T>(x + other.x, y + other.y, z + other.z);
}

template<typename T>
inline Vector3<T> Vector3<T>::operator+=(const Vector3<T> &other) {
    x += other.x;
    y += other.y;
    z += other.z;
    return *this;
}

template<typename T>
inline Vector3<T> Vector3<T>::operator-() const {
    return Vector3<T>(-x, -y, -z);
}

template<typename T>
inline Vector3<T> Vector3<T>::operator-(const Vector3<T> &other) const {
    return Vector3<T>(x - other.x, y - other.y, z - other.z);
}

template<typename T>
inline Vector3<T> Vector3<T>::operator-=(const Vector3<T> &other) {
    x -= other.x;
    y -= other.y;
    z -= other.z;
    return *this;
}

template<typename T>
inline Vector3<T> Vector3<T>::operator*(const T &factor) const {
    return Vector3<T>(x * factor, y * factor, z * factor);
}

template<typename T>
inline Vector3<T> Vector3<T>::operator*=(const T &factor) {
    x *= factor;
    y *= factor;
    z *= factor;
    return *this;
}

template<typename T>
inline Vector3<T> Vector3<T>::operator/(const T &factor) const {
    if (factor == 0)
        throw std::invalid_argument("Division by zero");
    return Vector3<T>(x / factor, y / factor, z / factor);
}

template<typename T>
inline Vector3<T> Vector3<T>::operator/=(const T &factor) {
    if (factor == 0)
        throw std::invalid_argument("Division by zero");
    x /= factor;
    y /= factor;
    z /= factor;
    return *this;
}

template<typename T>
inline bool Vector3<T>::operator==(const Vector3<T> &other) const {
    return (x == other.x && y == other.y && z == other.z);
}

template<typename T>
inline bool Vector3<T>::operator!=(const Vector3<T> &other) const {
    return !(*this == other);
}
