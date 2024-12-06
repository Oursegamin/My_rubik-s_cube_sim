/*
** EPITECH PROJECT, 2024
** Cpp-Snake
** File description:
** window
*/

using namespace std;

#include "main.h"
#include "SFML/OpenGL.hpp"

Rubiks::Rubiks(int width, UNUSED int height) {
    Init_cubes(
        3,
        1.5,
        new colors_t [6]{
            COLOR_ORANGE,       // back     side
            COLOR_GREEN,        // right    side
            COLOR_RED,          // front    side
            COLOR_BLUE,         // left     side
            COLOR_WHITE,        // top      side
            COLOR_YELLOW,       // bottom   side
        }
    );
    action = {0, 0, 0};
    this->font.loadFromFile(GENSHIN_IMPACT_FONT);
    this->title = SFML_globals::Create_text(
        RUBIKS_TITLE,
        &this->font,
        this->Get_resize(width / 2, 75),
        RUBIKS_TITLE_SIZE,
        sf::Color(75, 75, 255)
    );
}

Rubiks::~Rubiks() {}

void Rubiks::Init_cubes(int size, float scale, colors_t colors[6]) {
    for (int x = 0; x < size; x++) {
        for (int y = 0; y < size; y++) {
            for (int z = 0; z < size; z++) {
                if ((x > 0 && x < size - 1) &&
                    (y > 0 && y < size - 1) &&
                    (z > 0 && z < size - 1))
                    continue;
                this->gl_cubes.push_back(
                    GL_cube(size, scale, new int [3]{x, y, z}, colors)
                );
            }
        }
    }
}

void Rubiks::Run() {
    while (Window::window->isOpen()) {
        this->Clear_window(sf::Color(173, 216, 230));
        this->Manager();
        this->Events();
        this->Draw();
        Window::window->display();
    }
}

void Rubiks::Clear_window(sf::Color color) {
    // Window::window->clear(color);
    (void)color;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Rubiks::_Rotate(sf::Vector2i start, sf::Vector2i end) {
    float dx = end.x - start.x;
    float dy = end.y - start.y;

    Vector3f delta = Vector3f(dx, -dy, 0);

    float angle = delta.Length();

    Vector3f rot = Vector3f(0, 0, 1).Cross(delta).Normalize();

    x_angle += rot.x * angle;
    y_angle += rot.y * angle;
}

void Rubiks::Rotate(sf::Event *event) {
    if (event->type == sf::Event::MouseButtonPressed &&
        event->mouseButton.button == sf::Mouse::Left) {
        this->start = this->mouse.getPosition(*Window::window);
        moving = true;
    }
    if (moving && event->type == sf::Event::MouseMoved) {
        this->end = this->mouse.getPosition(*Window::window);
        _Rotate(start, end);
        start = end;
    }
    if (event->type == sf::Event::MouseButtonReleased &&
        event->mouseButton.button == sf::Mouse::Left)
        moving = false;
}

void Rubiks::Events() {
    sf::Event event;

    while (Window::window->pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            Window::window->close();
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::BackSpace)
                Window::window->close();
        }
        Randomize(&event);
        Moves(&event, &action);
        Rotate(&event);
    }
}

void Rubiks::Manager() {
    Update_randomization(&action);
    if (rotating)
        animation_angle += animation_speed;
    if (rotating && animation_angle >= 90) {
        for (auto &cube : gl_cubes)
            cube.Update(action);
        rotating = false;
        animation_angle = 0;
    }
}

void Rubiks::Draw() {
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(pos.x, pos.y, pos.z);
    glRotatef(x_angle, 1, 0, 0);
    glRotatef(y_angle, 0, 1, 0);

    for (auto &cube : gl_cubes)
        cube.Draw(rotating, animation_angle, action);

    Window::window->pushGLStates();
    Window::window->draw(this->title);
    Window::window->popGLStates();
}

sf::Vector2f Rubiks::Get_resize(float x, float y) {
    sf::Vector2f window_size = Rubiks::Get_window_size();
    return sf::Vector2f(
        x * window_size.x / WINDOW_WIDTH,
        y * window_size.y / WINDOW_HEIGHT
    );
}

sf::Vector2f Rubiks::Get_mouse_pos() {
    sf::Vector2f not_resize_pos = sf::Vector2f(sf::Mouse::getPosition(*Window::window));
    sf::Vector2f window_size = Rubiks::Get_window_size();
    return sf::Vector2f(not_resize_pos.x * window_size.x / WINDOW_WIDTH, not_resize_pos.y * window_size.y / WINDOW_HEIGHT);
}

sf::Vector2f Rubiks::Get_window_size() {
    return sf::Vector2f(Window::Get_size());
}
