/*
** EPITECH PROJECT, 2024
** My_rubik-s_cube_sim
** File description:
** vector3D
*/

#include "vector3D.hpp"

Vector3D::Vector3D(float x, float y, float z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

Vector3D::~Vector3D() {
}

Vector3D Vector3D::operator+(const Vector3D &other) {
    return Vector3D(this->x + other.x, this->y + other.y, this->z + other.z);
}

Vector3D Vector3D::operator-(const Vector3D &other) {
    return Vector3D(this->x - other.x, this->y - other.y, this->z - other.z);
}

Vector3D Vector3D::operator*(const float &factor) {
    return Vector3D(this->x * factor, this->y * factor, this->z * factor);
}
