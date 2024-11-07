/*
** EPITECH PROJECT, 2024
** Cpp-Snake
** File description:
** window
*/

#ifndef GAME_HPP_
#define GAME_HPP_

#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <SFML/Graphics.hpp>

#include "macros.h"
#include "assets.h"
#include "globals/sfml_globals.hpp"
#include "cube.hpp"

#define RUBIKS_TITLE "Rubik's Cube Sim"
#define RUBIKS_TITLE_SIZE 50
#define RUBIKS_CUBE_SIZE 3
#define RUBIKS_CUBE_UNIQUE_CUBES pow(RUBIKS_CUBE_SIZE, 3) - pow(RUBIKS_CUBE_SIZE - 2, 3)
#define RUBIKS_TEXTURE_PATH "assets/textures/rubiks_cube.png"
#define RUBIKS_TEXTURE_PATH_2 "assets/textures/rubiks_cube_2.png"
#define RUBIKS_TEXTURE_PATH_3 "assets/textures/rubiks_cube_3.png"

class Rubiks {
    static sf::RenderWindow *window;

    sf::Font font;
    sf::Text title;

    Cube *cube[RUBIKS_CUBE_SIZE];

    public:
        Rubiks(int width, int height, std::string title);
        ~Rubiks();
        void Run();
        void Clear_window(sf::Color color = sf::Color::Black);
        void Events();
        void Manager();
        void Draw();

        static void Init_window(int width, int height, const std::string title);

        static sf::Vector2f Get_resize(float x, float y);
        static sf::Vector2f Get_mouse_pos();
        static sf::RenderWindow *Get_window();
        static sf::Vector2f Get_window_size();
};

#endif /*GAME_HPP_ */
