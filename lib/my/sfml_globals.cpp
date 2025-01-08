/*
** EPITECH PROJECT, 2024
** Cpp-Snake
** File description:
** globals
*/

#include "sfml_globals.hpp"

SFML_globals::SFML_globals() {}

SFML_globals::~SFML_globals() {}

sf::Text SFML_globals::Create_text(std::string text, sf::Font *font,
    sf::Vector2f pos, float size, sf::Color color)
{
    sf::Text new_text;

    new_text.setFont(*font);
    new_text.setString(text);
    new_text.setCharacterSize(size);
    Set_text_mid_origin(&new_text);
    new_text.setPosition(pos);
    new_text.setFillColor(color);
    return new_text;
}

void SFML_globals::Set_text_mid_origin(sf::Text *text) 
{
    sf::FloatRect bounds = text->getGlobalBounds();
    text->setOrigin(bounds.width / 2, bounds.height);
}

void SFML_globals::Set_text_mid_left_origin(sf::Text *text)
{
    sf::FloatRect bounds = text->getGlobalBounds();
    text->setOrigin(0, bounds.height);
}

sf::Sprite SFML_globals::Create_sprite(sf::Texture *texture,
    sf::Vector2f pos, sf::Vector2f scale)
{
    sf::Sprite new_sprite;

    new_sprite.setTexture(*texture);
    new_sprite.setPosition(pos);
    new_sprite.setScale(scale);
    return new_sprite;
}

void SFML_globals::Set_sprite_mid_origin(sf::Sprite *sprite)
{
    sf::FloatRect bounds = sprite->getLocalBounds();

    sprite->setOrigin(bounds.width / 2, bounds.height / 2);
}

bool SFML_globals::check_event_up_key_code(sf::Event::KeyEvent key)
{
    return key.code == sf::Keyboard::Up || key.code == sf::Keyboard::Z;
}

bool SFML_globals::check_event_down_key_code(sf::Event::KeyEvent key)
{
    return key.code == sf::Keyboard::Down || key.code == sf::Keyboard::S;
}

bool SFML_globals::check_event_left_key_code(sf::Event::KeyEvent key)
{
    return key.code == sf::Keyboard::Left || key.code == sf::Keyboard::Q;
}

bool SFML_globals::check_event_right_key_code(sf::Event::KeyEvent key)
{
    return key.code == sf::Keyboard::Right || key.code == sf::Keyboard::D;
}
