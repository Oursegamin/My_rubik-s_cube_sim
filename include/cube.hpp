/*
** EPITECH PROJECT, 2024
** My_rubik-s_cube_sim
** File description:
** cube
*/

#ifndef CUBE_HPP_
#define CUBE_HPP_

#include "vector3D.hpp"

class Cube {
    std::vector<std::vector<int>> faces = {
        {0, 1, 5, 4},
        {1, 2, 6, 5},
        {2, 3, 7, 6},
        {3, 0, 4, 7},
        {0, 1, 2, 3},
        {4, 5, 6, 7}
    };

    public:
        Cube();
        ~Cube();
};

#endif /* !CUBE_HPP_ */
