/*
** EPITECH PROJECT, 2024
** My_rubik-s_cube_sim
** File description:
** moves
*/

#pragma once
#ifndef MOVES_H_
#define MOVES_H_

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

#include "macros.h"

typedef struct action_s {
    int axis;
    int layer;
    float dir;

    action_s();
    action_s(int axis, int layer, float dir);
    action_s(const action_s &other);
    ~action_s();

    void operator=(const action_s &other);
    action_s operator*(const float clock) const;
    void operator*=(const float clock);
} action_t;


#define RUBIKS_CUBE_X_ANGLE 20.f
#define RUBIKS_CUBE_Y_ANGLE -30.f
#define RUBIKS_CUBE_Z_ANGLE 0.f

#define RUBIKS_CUBE_SENSITIVITY 0.5f
#define RUBIKS_CUBE_DEFAULT_MOVE_SPEED 10

#define RUBIKS_CUBE_RANDOM_MOVE_NUMBER 75
#define RUBIKS_CUBE_RANDOM_MOVE_SPEED 45

#define RUBIKS_MOVE_TOP     (action_t){1, 2, -1}
#define RUBIKS_MOVE_BOTTOM  (action_t){1, 0, -1}
#define RUBIKS_MOVE_LEFT    (action_t){0, 0, 1}
#define RUBIKS_MOVE_RIGHT   (action_t){0, 2, 1}
#define RUBIKS_MOVE_FRONT   (action_t){2, 2, -1}
#define RUBIKS_MOVE_BACK    (action_t){2, 0, -1}
#define RUBIKS_MOVE_MID_H   (action_t){0, 1, -1}
#define RUBIKS_MOVE_MID_V   (action_t){1, 1, -1}

UNUSED static std::vector<action_t> all_rubiks_possible_actions = {
    RUBIKS_MOVE_TOP,
    RUBIKS_MOVE_BOTTOM,
    RUBIKS_MOVE_LEFT,
    RUBIKS_MOVE_RIGHT,
    RUBIKS_MOVE_FRONT,
    RUBIKS_MOVE_BACK,
    RUBIKS_MOVE_TOP * -1.f,
    RUBIKS_MOVE_BOTTOM * -1.f,
    RUBIKS_MOVE_LEFT * -1.f,
    RUBIKS_MOVE_RIGHT * -1.f,
    RUBIKS_MOVE_FRONT * -1.f,
    RUBIKS_MOVE_BACK * -1.f,
};

UNUSED static std::vector<sf::Keyboard::Key> keyboard_moves = {
    sf::Keyboard::Z,
    sf::Keyboard::S,
    sf::Keyboard::Q,
    sf::Keyboard::D,
    sf::Keyboard::A,
    sf::Keyboard::E,
    sf::Keyboard::R,
    sf::Keyboard::F
};

UNUSED static std::vector<action_t> clockwise_moves = {
    RUBIKS_MOVE_TOP,
    RUBIKS_MOVE_BOTTOM,
    RUBIKS_MOVE_LEFT,
    RUBIKS_MOVE_RIGHT,
    RUBIKS_MOVE_FRONT,
    RUBIKS_MOVE_BACK,
    RUBIKS_MOVE_MID_H,
    RUBIKS_MOVE_MID_V
};

UNUSED static std::vector<sf::Keyboard::Key> numpadkey_moves = {
    // sf::Keyboard::Numpad7,           // numpad top left
    sf::Keyboard::Numpad8,              // numpad top
    // sf::Keyboard::Numpad9,              // numpad top right
    sf::Keyboard::Numpad4,              // numpad left
    sf::Keyboard::Numpad5,              // numpad mid
    sf::Keyboard::Numpad6,              // numpad right
    // sf::Keyboard::Numpad1,              // numpad bottom left
    sf::Keyboard::Numpad2,              // numpad bottom
    // sf::Keyboard::Numpad3               // numpad bottom right
    sf::Keyboard::Numpad0,              // numpad bottom bottom
};

UNUSED static std::vector<action_t> numpad_moves = {
    // 
    RUBIKS_MOVE_TOP,
    // 
    RUBIKS_MOVE_LEFT,
    RUBIKS_MOVE_FRONT,
    RUBIKS_MOVE_RIGHT,
    // 
    RUBIKS_MOVE_BOTTOM,
    // 
    RUBIKS_MOVE_BACK,
};

#endif /* !MOVES_H_ */
