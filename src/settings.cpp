/*
** EPITECH PROJECT, 2024
** My_rubik-s_cube_sim
** File description:
** settings
*/

#include "main.h"

Settings::Settings() {
    Init_keys();
    Init();
}

Settings::~Settings() {}

void Settings::Init()
{
    sf::Vector2i window_size = Window::Get_size();

    background.setFillColor(SETTINGS_BACKGROUND_COLOR);
    background.setSize(sf::Vector2f(window_size.x, window_size.y));
}

void Settings::Init_keys()
{
    help_key = sf::Keyboard::H;
    settings_key = sf::Keyboard::Escape;
}

void Settings::Manager() {}

void Settings::Events(sf::Event *event)
{
    (void)event;
}

void Settings::Draw()
{
    Window::window->draw(background);
}
