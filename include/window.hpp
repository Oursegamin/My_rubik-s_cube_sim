/*
** EPITECH PROJECT, 2024
** My_rubik-s_cube_sim
** File description:
** window
*/

#ifndef WINDOW_HPP_
#define WINDOW_HPP_

#include <SFML/Graphics.hpp>

class Window
{
    public:
        static sf::RenderWindow *window;
        static sf::Vector2i window_size;

        Window(int width, int height, const std::string &title);
        ~Window();

        static void Clear();
        static void Events(sf::Event *event);
        static sf::Vector2i Get_size();
        static sf::Vector2f Get_resize(float x, float y);
        static float get_less_size(float value);
};

#endif /* !WINDOW_HPP_ */
