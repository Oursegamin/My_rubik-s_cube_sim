/*
** EPITECH PROJECT, 2024
** Cpp-Snake
** File description:
** main
*/

#include "rubiks_cube.hpp"

int main()
{
    Rubiks cube(WINDOW_WIDTH, WINDOW_HEIGHT, "Rubik's Cube");
    cube.Run();
    return OK;
}
