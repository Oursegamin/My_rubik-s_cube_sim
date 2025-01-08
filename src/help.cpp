/*
** EPITECH PROJECT, 2024
** My_rubik-s_cube_sim
** File description:
** help
*/

#include "main.h"

Help::Help()
{
    Init();
}

Help::~Help() {}

void Help::Init()
{
    font.loadFromFile(TITLE_FONT);
    sf::Vector2f pos = sf::Vector2f(20, WINDOW_HEIGHT - 80);

    not_shown_text = SFML_globals::Create_text(
        "Press H to show / hide help",
        &font,
        Window::Get_resize(pos.x, pos.y),
        HELP_TEXT_SIZE,
        sf::Color::Black
    );
    SFML_globals::Set_text_mid_left_origin(&not_shown_text);

    float text_size = Window::get_less_size(HELP_TEXT_SIZE);
    help_texts.clear();
    for (int i = (int)texts.size() - 1; i >= 0; i--) {
        sf::Text tmp = SFML_globals::Create_text(
            texts[i],
            &font,
            Window::Get_resize(pos.x, pos.y),
            text_size,
            sf::Color::Black
        );
        SFML_globals::Set_text_mid_left_origin(&tmp);
        help_texts.push_back(tmp);
        pos.y -= text_size * 1.75;
    }
}

void Help::Update_keys() {}

void Help::Draw_help()
{
    if (!show_help) {
        Window::window->draw(not_shown_text);
        return;
    }
    for (size_t i = 0; i < help_texts.size(); i++)
        Window::window->draw(help_texts[i]);
}
