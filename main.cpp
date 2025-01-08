/*
** EPITECH PROJECT, 2024
** Cpp-Snake
** File description:
** main
*/

#include "main.h"

int launch_sim(int width, int height, const std::string &title)
{
    Window window(width, height, title);
    Rubiks cube(width, height);
    cube.Run();
    return OK;
}

int main()
{
    return launch_sim(WINDOW_WIDTH, WINDOW_HEIGHT, "Rubik's Cube");
}
