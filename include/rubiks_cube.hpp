/*
** EPITECH PROJECT, 2024
** Cpp-Snake
** File description:
** window
*/

#pragma once
#ifndef GAME_HPP_
#define GAME_HPP_

#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <SFML/Graphics.hpp>

#include "assets.h"
#include "window.hpp"
#include "rubiks_moves.hpp"
#include "gl_cube.hpp"

#define RUBIKS_TITLE "Rubik's Cube Sim"
#define RUBIKS_TITLE_SIZE 50
#define RUBIKS_CUBE_SIZE 3
#define RUBIKS_CUBE_UNIQUE_CUBES(size) pow(size, 3) - pow(size - 2, 3)

class Rubiks : public Rubiks_moves {
    sf::Font font;
    sf::Text title;

    bool moving = false;
    bool shifting = false;
    sf::Vector2i start;
    sf::Vector2i end;
    sf::Mouse mouse;

    std::vector<GL_cube> gl_cubes;

    float scale = 1.f;
    action_t action;
    Vector3f pos = Vector3f(0.f, 0.f, -40.f);
    Vector3f angles = {
        RUBIKS_CUBE_X_ANGLE,
        RUBIKS_CUBE_Y_ANGLE,
        RUBIKS_CUBE_Z_ANGLE,
    };

    public:
        Rubiks(int width, int height);
        ~Rubiks();
        void Init_cubes(int size, float scale, colors_t colors[6]);

        void Run();

        void Translation(sf::Event *event);
        void Rotate(sf::Event *event);
        void Apply_rotation(sf::Vector2i start, sf::Vector2i end);
        void Scale(sf::Event *event);
        void Transform(sf::Event *event);

        void Events();
        void Window_events(sf::Event *event);

        void Manager();

        void Draw();

        static sf::Vector2f Get_resize(float x, float y);
        static sf::Vector2f Get_mouse_pos();
        static sf::Vector2f Get_window_size();
};

#endif /*GAME_HPP_ */
