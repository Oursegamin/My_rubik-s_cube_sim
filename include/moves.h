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

typedef enum Rubiks_faces_s {
    RUBIKS_TOP,
    RUBIKS_BOTTOM,
    RUBIKS_LEFT,
    RUBIKS_RIGHT,
    RUBIKS_FRONT,
    RUBIKS_BACK,
    RUBIKS_MID_H,
    RUBIKS_MID_V,
    RUBIKS_MID_D,
    RUBIKS_FACES_SIZE
} Rubiks_faces_t;

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


#define RUBIKS_CUBE_X_ANGLE -M_PI / 9.f
#define RUBIKS_CUBE_Y_ANGLE M_PI / 6.f
#define RUBIKS_CUBE_Z_ANGLE 0.f

#define RUBIKS_CUBE_SENSITIVITY 0.01f
#define RUBIKS_CUBE_DEFAULT_MOVE_SPEED 10

#define RUBIKS_CUBE_RANDOM_MOVE_NUMBER 75
#define RUBIKS_CUBE_RANDOM_MOVE_SPEED 45

#define RUBIKS_MOVE_TOP     (action_t){1, 2, -1}
#define RUBIKS_MOVE_BOTTOM  (action_t){1, 0,  1}
#define RUBIKS_MOVE_LEFT    (action_t){0, 0,  1}
#define RUBIKS_MOVE_RIGHT   (action_t){0, 2, -1}
#define RUBIKS_MOVE_FRONT   (action_t){2, 2, -1}
#define RUBIKS_MOVE_BACK    (action_t){2, 0,  1}
#define RUBIKS_MOVE_MID_H   (action_t){0, 1, -1}
#define RUBIKS_MOVE_MID_V   (action_t){1, 1, -1}
#define RUBIKS_MOVE_MID_D   (action_t){2, 1, -1}

#define ORIGINAL_TOP    Vector3f( 0.0f,  1.0f,  0.0f)
#define ORIGINAL_BOTTOM Vector3f( 0.0f, -1.0f,  0.0f)
#define ORIGINAL_LEFT   Vector3f(-1.0f,  0.0f,  0.0f)
#define ORIGINAL_RIGHT  Vector3f( 1.0f,  0.0f,  0.0f)
#define ORIGINAL_FRONT  Vector3f( 0.0f,  0.0f,  1.0f)
#define ORIGINAL_BACK   Vector3f( 0.0f,  0.0f, -1.0f)

UNUSED static std::vector<Rubiks_faces_t> Rubiks_faces = {
    RUBIKS_TOP,
    RUBIKS_BOTTOM,
    RUBIKS_LEFT,
    RUBIKS_RIGHT,
    RUBIKS_FRONT,
    RUBIKS_BACK,
    RUBIKS_MID_H,
    RUBIKS_MID_V
};

UNUSED static std::vector<action_t> actions = {
    RUBIKS_MOVE_TOP,
    RUBIKS_MOVE_BOTTOM,
    RUBIKS_MOVE_LEFT,
    RUBIKS_MOVE_RIGHT,
    RUBIKS_MOVE_FRONT,
    RUBIKS_MOVE_BACK,
    RUBIKS_MOVE_MID_H,
    RUBIKS_MOVE_MID_V
};

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

UNUSED static std::vector<Vector3f> orginals_faces_vector = {
    ORIGINAL_TOP,
    ORIGINAL_BOTTOM,
    ORIGINAL_LEFT,
    ORIGINAL_RIGHT,
    ORIGINAL_FRONT,
    ORIGINAL_BACK
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

UNUSED static std::vector<Rubiks_faces_t> clockwise_moves = {
    RUBIKS_TOP,
    RUBIKS_BOTTOM,
    RUBIKS_LEFT,
    RUBIKS_RIGHT,
    RUBIKS_FRONT,
    RUBIKS_BACK,
    RUBIKS_MID_H,
    RUBIKS_MID_V
};

UNUSED static std::vector<sf::Keyboard::Key> numpadkey_moves = {
    /*  NUMPAD 1 */     // sf::Keyboard::Numpad7,
    /*  NUMPAD 2 */     sf::Keyboard::Numpad8,
    /*  NUMPAD 3 */     // sf::Keyboard::Numpad9,
    /*  NUMPAD 4 */     sf::Keyboard::Numpad4,
    /*  NUMPAD 5 */     sf::Keyboard::Numpad5,
    /*  NUMPAD 6 */     sf::Keyboard::Numpad6,
    /*  NUMPAD 7 */     // sf::Keyboard::Numpad1,
    /*  NUMPAD 8 */     sf::Keyboard::Numpad2,
    /*  NUMPAD 9 */     // sf::Keyboard::Numpad3,
    /*  NUMPAD 0 */     sf::Keyboard::Numpad0,
};

UNUSED static std::vector<Rubiks_faces_t> numpad_moves = {
    /*  NUMPAD 1 */     // 
    /*  NUMPAD 2 */     RUBIKS_TOP,
    /*  NUMPAD 3 */     // 
    /*  NUMPAD 4 */     RUBIKS_LEFT,
    /*  NUMPAD 5 */     RUBIKS_FRONT,
    /*  NUMPAD 6 */     RUBIKS_RIGHT,
    /*  NUMPAD 7 */     // 
    /*  NUMPAD 8 */     RUBIKS_BOTTOM,
    /*  NUMPAD 9 */     // 
    /*  NUMPAD 0 */     RUBIKS_BACK,
};

#endif /* !MOVES_H_ */
