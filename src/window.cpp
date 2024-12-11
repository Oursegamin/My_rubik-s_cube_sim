/*
** EPITECH PROJECT, 2024
** My_rubik-s_cube_sim
** File description:
** window
*/

#include "main.h"

sf::RenderWindow *Window::window;
sf::Vector2i Window::window_size;

Window::Window(int width, int height, const std::string &title) {
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

Window::~Window() {
    window->close();
}

void Window::Clear() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

sf::Vector2i Window::Get_size() {
    return window_size;
}
