/*
** EPITECH PROJECT, 2024
** Cpp-Snake
** File description:
** window
*/

using namespace std;

#include "main.h"
#include "SFML/OpenGL.hpp"

screen_mode_t Rubiks::screen = RUBIKS_GAME;

Rubiks::Rubiks(int width, UNUSED int height)
{
    settings = new Settings();

    Init(sf::Vector2f(width, height));
    Init_cubes(
        3,
        1,
        new colors_t [6]{
            COLOR_ORANGE,       // back     side
            COLOR_GREEN,        // right    side
            COLOR_RED,          // front    side
            COLOR_BLUE,         // left     side
            COLOR_WHITE,        // top      side
            COLOR_YELLOW,       // bottom   side
        }
    );
}

Rubiks::~Rubiks() {}

void Rubiks::Init(sf::Vector2f w_size)
{
    action = {0, 0, 0};
    scale = 1.5;
    glLineWidth(RUBIKS_CUBE_LINES_WIDTH * scale);
    glPointSize(RUBIKS_CUBE_POINTS_WIDTH * scale);
    current_matrix = (
        Matrix4f::Create_scale(Vector3f(scale, scale, scale)) *
        Matrix4f::Create_rotation(angles) *
        Matrix4f::Create_translation(pos)
    );
    this->font.loadFromFile(GENSHIN_IMPACT_FONT);
    this->title = SFML_globals::Create_text(
        RUBIKS_TITLE,
        &this->font,
        Window::Get_resize(w_size.x / 2, 75),
        RUBIKS_TITLE_SIZE,
        RUBIKS_CUBE_TEXT_COLOR
    );
}

void Rubiks::Init_cubes(int size, float scale, colors_t colors[6])
{
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

void Rubiks::Run()
{
    while (Window::window->isOpen()) {
        Window::Clear();
        this->Manager();
        this->Events();
        this->Draw();
        Window::window->display();
    }
}

void Rubiks::Translation(sf::Event *event)
{
    if (event->type == sf::Event::MouseButtonPressed &&
        event->mouseButton.button == sf::Mouse::Right) {
        this->start = this->mouse.getPosition(*Window::window);
        shifting = true;
    }
    if (shifting && event->type == sf::Event::MouseMoved) {
        this->end = this->mouse.getPosition(*Window::window);
        current_matrix.Translate(Vector3f(
            (end.x - start.x) * RUBIKS_CUBE_TRANSLATION_SENSITIVITY,
            -(end.y - start.y) * RUBIKS_CUBE_TRANSLATION_SENSITIVITY,
            0
        ));
        start = end;
    }
    if (event->type == sf::Event::MouseButtonReleased &&
        event->mouseButton.button == sf::Mouse::Right)
        shifting = false;
}

void Rubiks::Apply_rotation(sf::Vector2i start, sf::Vector2i end)
{
    float dx = end.x - start.x;
    float dy = end.y - start.y;

    Vector3f delta = Vector3f(dx, -dy, 0);

    float angle = delta.Length() * RUBIKS_CUBE_SENSITIVITY;

    if (angle == 0.0f)
        return;

    Vector3f screenAxis = Vector3f(delta.y, -delta.x, 0).Normalize();

    Vector3f cubeAxis = current_matrix.TransformDirection(screenAxis).Normalize();

    current_matrix.Rotate(cubeAxis * angle);
}

void Rubiks::Rotate(sf::Event *event)
{
    if (event->type == sf::Event::MouseButtonPressed &&
        event->mouseButton.button == sf::Mouse::Left) {
        this->start = this->mouse.getPosition(*Window::window);
        moving = true;
    }
    if (moving && event->type == sf::Event::MouseMoved) {
        this->end = this->mouse.getPosition(*Window::window);
        Apply_rotation(start, end);
        start = end;
    }
    if (event->type == sf::Event::MouseButtonReleased &&
        event->mouseButton.button == sf::Mouse::Left)
        moving = false;
}

void Rubiks::Scale(sf::Event *event)
{
    if (event->type == sf::Event::MouseWheelScrolled) {
        float scale_factor = 1.0f + event->mouseWheelScroll.delta * -RUBIKS_CUBE_SENSITIVITY;
        scale *= scale_factor;
        glLineWidth(RUBIKS_CUBE_LINES_WIDTH * scale);
        glPointSize(RUBIKS_CUBE_POINTS_WIDTH * scale);
        current_matrix.Scale(Vector3f(scale_factor, scale_factor, scale_factor));
    }
}

void Rubiks::Transform(sf::Event *event)
{
    Translation(event);
    Rotate(event);
    Scale(event);
}

void Rubiks::Events()
{
    sf::Event event;

    while (Window::window->pollEvent(event)) {
        Window::Events(&event);
        Screen_events(&event);
        if (screen == RUBIKS_GAME) {
            Transform(&event);
            Randomize(&event);
            Moves(&event, &action);
        } else if (screen == RUBIKS_SETTINGS)
            settings->Events(&event);
    }
}

void Rubiks::Screen_events(sf::Event *event)
{
    if (screen < RUBIKS_SCREEN_MODE_SIZE && event->type == sf::Event::KeyPressed) {
        if (screen != RUBIKS_SETTINGS && event->key.code == settings->help_key)
            settings->show_help = settings->show_help ? false : true;
        if (event->key.code == settings->settings_key)
            screen = screen == RUBIKS_GAME ? RUBIKS_SETTINGS : RUBIKS_GAME;
    }
}

void Rubiks::Manager()
{
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

void Rubiks::Draw()
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glLoadMatrixf(current_matrix.Get_list());

    for (auto &cube : gl_cubes)
        cube.Draw(rotating, animation_angle, action);

    Window::window->pushGLStates();

    settings->Draw_help();

    if (screen == RUBIKS_SETTINGS)
        settings->Draw();

    Window::window->draw(this->title);

    Window::window->popGLStates();
}
