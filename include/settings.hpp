/*
** EPITECH PROJECT, 2024
** My_rubik-s_cube_sim
** File description:
** setting
*/

#pragma once
#ifndef SETTING_HPP_
#define SETTING_HPP_

#include "SFML/Graphics.hpp"

#define SETTINGS_BACKGROUND_COLOR sf::Color(64, 0, 128, 64)

class Settings : public Help
{
    sf::RectangleShape background;

    public:
        sf::Keyboard::Key help_key;
        sf::Keyboard::Key settings_key;

        Settings();
        ~Settings();
        void Init() override;
        void Init_keys();

        void Manager();
        void Events(sf::Event *event);
        void Draw();
};

#endif /* !SETTING_HPP_ */
