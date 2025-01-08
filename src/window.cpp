/*
** EPITECH PROJECT, 2024
** My_rubik-s_cube_sim
** File description:
** window
*/

#include "main.h"

sf::RenderWindow *Window::window;
sf::Vector2i Window::window_size;

Window::Window(int width, int height, const std::string &title)
{
    window_size = sf::Vector2i(width, height);
    window = new sf::RenderWindow(
        sf::VideoMode(width, height),
        title,
        sf::Style::Resize | sf::Style::Close,
        sf::ContextSettings(24, 8, 8, 4, 6)
    );
    window->setFramerateLimit(FPS);
    window->setVerticalSyncEnabled(true);

    glEnable(GL_DEPTH_TEST);
    glClearColor(173.f / 255, 216.f / 255, 230.f / 255, 1.f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (float)width / height, 0.1, 200);
}

Window::~Window()
{
    window->close();
}

void Window::Clear()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Window::Events(sf::Event *event)
{
    if (event->type == sf::Event::Closed)
        window->close();
    if (event->type == sf::Event::KeyPressed) {
        if (event->key.code == sf::Keyboard::BackSpace)
            window->close();
    }
    if (event->type == sf::Event::Resized) {
        window_size = sf::Vector2i(event->size.width, event->size.height);
        glViewport(0, 0, event->size.width, event->size.height);
    }
}

sf::Vector2i Window::Get_size()
{
    return window_size;
}

sf::Vector2f Window::Get_resize(float x, float y)
{
    return sf::Vector2f(
        x * window_size.x / WINDOW_WIDTH,
        y * window_size.y / WINDOW_HEIGHT
    );
}

float Window::get_less_size(float value)
{
    float x = Get_resize(value, 0).x;
    float y = Get_resize(0, value).y;

    return x > y ? y : x;
}
