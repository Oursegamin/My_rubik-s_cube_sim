/*
** EPITECH PROJECT, 2024
** Cpp-Snake
** File description:
** globals
*/

#ifndef GLOBALS_HPP_
#define GLOBALS_HPP_

#include <SFML/Graphics.hpp>

class SFML_globals
{
    public:
        SFML_globals();
        ~SFML_globals();

        static sf::Text Create_text(std::string text, sf::Font *font,
            sf::Vector2f pos, float size, sf::Color color);
        static void Set_text_mid_origin(sf::Text *text);

        static sf::Sprite Create_sprite(sf::Texture *texture, sf::Vector2f pos,
            sf::Vector2f scale = sf::Vector2f(1.f, 1.f));
        static void Set_sprite_mid_origin(sf::Sprite *sprite);

        static bool check_event_up_key_code(sf::Event::KeyEvent key);
        static bool check_event_down_key_code(sf::Event::KeyEvent key);
        static bool check_event_left_key_code(sf::Event::KeyEvent key);
        static bool check_event_right_key_code(sf::Event::KeyEvent key);
};

#endif /* !GLOBALS_HPP_ */
