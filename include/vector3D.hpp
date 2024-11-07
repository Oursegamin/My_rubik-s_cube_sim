/*
** EPITECH PROJECT, 2024
** My_rubik-s_cube_sim
** File description:
** vector3D
*/

#ifndef VECTOR3D_HPP_
#define VECTOR3D_HPP_

class Vector3D {
    public:
        float x;
        float y;
        float z;

        Vector3D(float x = 0.0f, float y = 0.0f, float z = 0.0f);
        ~Vector3D();

        Vector3D operator+(const Vector3D &other);
        Vector3D operator-(const Vector3D &other);
        Vector3D operator*(const float &factor);
};

#endif /* !VECTOR3D_HPP_ */
