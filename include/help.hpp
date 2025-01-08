/*
** EPITECH PROJECT, 2024
** My_rubik-s_cube_sim
** File description:
** help
*/

#pragma once
#ifndef HELP_HPP_
#define HELP_HPP_

#include "SFML/Graphics.hpp"

#define HELP_TEXT_SIZE 20

class Help
{
    const std::vector<std::string> texts = {
        "all this moves are clockwise",
        "press 'SHIFT' to move the opposite direction :",
        "Keys to press : face that move",
        "Z / Numpad8  : top",
        "Q / Numpad4  : left",
        "S / Numpad2  : bottom",
        "D / Numpad6  : right",
        "A / Numpad5  : front",
        "E / Numpad0  : back",
        "      W      : mid (top) left to right",
        "      X      : mid bottom to top",
        "      C      : mid right to left",
    };

    sf::Font font;

    sf::Text not_shown_text;
    std::vector<sf::Text> help_texts;


    public:
        bool show_help = false;
        
        Help();
        ~Help();
        virtual void Init();

        void Update_keys();
        void Draw_help();
};

#endif /* !HELP_HPP_ */
