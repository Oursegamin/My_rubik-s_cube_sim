/*
** EPITECH PROJECT, 2024
** Cpp-Snake
** File description:
** window
*/

using namespace std;

#include "rubiks_cube.hpp"

sf::RenderWindow *Rubiks::window;

Rubiks::Rubiks(int width, int height, const string title) {
    Init_window(width, height, title);
    this->font.loadFromFile(GENSHIN_IMPACT_FONT);
    this->title = SFML_globals::Create_text(
        RUBIKS_TITLE,
        &this->font,
        this->Get_resize(width / 2, 75),
        RUBIKS_TITLE_SIZE,
        sf::Color(75, 75, 255)
    );
}

Rubiks::~Rubiks() {
    delete window;
}

void Rubiks::Init_window(int width, int height, const string title) {
    window = new sf::RenderWindow(sf::VideoMode(width, height), title, sf::Style::Fullscreen);
    window->setFramerateLimit(FPS);
}

void Rubiks::Run() {
    while (this->window->isOpen()) {
        this->Clear_window(sf::Color(173, 216, 230));
        this->Manager();
        this->Events();
        this->Draw();
        this->window->display();
    }
}

void Rubiks::Clear_window(sf::Color color) {
    this->window->clear(color);
}

void Rubiks::Events() {
    sf::Event event;

    while (this->window->pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            this->window->close();
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::BackSpace)
                this->window->close();
        }
    }
}

void Rubiks::Manager() {
}

void Rubiks::Draw() {
    this->window->draw(this->title);
}

sf::Vector2f Rubiks::Get_resize(float x, float y) {
    sf::Vector2f window_size = Rubiks::Get_window_size();
    return sf::Vector2f(x * window_size.x / 1920, y * window_size.y / 1080);
}

sf::Vector2f Rubiks::Get_mouse_pos() {
    sf::Vector2f not_resize_pos = sf::Vector2f(sf::Mouse::getPosition(*window));
    sf::Vector2f window_size = Rubiks::Get_window_size();
    return sf::Vector2f(not_resize_pos.x * window_size.x / WINDOW_WIDTH, not_resize_pos.y * window_size.y / WINDOW_HEIGHT);
}

sf::RenderWindow *Rubiks::Get_window() {
    return window;
}

sf::Vector2f Rubiks::Get_window_size() {
    return sf::Vector2f(window->getSize());
}
