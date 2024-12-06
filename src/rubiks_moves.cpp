/*
** EPITECH PROJECT, 2024
** My_rubik-s_cube_sim
** File description:
** rubiks_moves
*/

#include "main.h"

action_s::action_s() : axis(0), slice(0), dir(0) {}

action_s::action_s(int axis, int slice, float dir) :
    axis(axis),
    slice(slice),
    dir(dir) {}

action_s::action_s(const action_s &other) {
    axis = other.axis;
    slice = other.slice;
    dir = other.dir;
}

action_s::~action_s() {}

inline void action_s::operator=(const action_s &other) {
    axis = other.axis;
    slice = other.slice;
    dir = other.dir;
}

inline action_s action_s::operator*(const float clock) const {
    return {
        axis,
        slice,
        dir * clock
    };
}

inline void action_s::operator*=(const float clock) {
    *this = *this * clock;
}

Rubiks_moves::Rubiks_moves() {}

Rubiks_moves::~Rubiks_moves() {}

void Rubiks_moves::Randomize(sf::Event *event) {
    if (rotating)
        return;
    if (!randomizing) {
        if (event->type == sf::Event::KeyPressed &&
            event->key.code == sf::Keyboard::M) {
            randomizing = true;
            animation_speed = RUBIKS_CUBE_RANDOM_MOVE_SPEED;
            std::srand(std::time(nullptr));
            for (int i = 0; i < RUBIKS_CUBE_RANDOM_MOVE_NUMBER; i++) {
                int rand = std::rand() % all_rubiks_possible_actions.size();
                random_actions.push_back(all_rubiks_possible_actions[rand]);
            }
        } else
            return;
    }
}

void Rubiks_moves::Update_randomization(action_t *action) {
    if (!randomizing || rotating)
        return;
    if (random_actions.empty()) {
        randomizing = false;
        animation_speed = RUBIKS_CUBE_DEFAULT_MOVE_SPEED;
    } else {
        action_t _action = random_actions.back();
        random_actions.pop_back();
        rotating = true;
        *action = _action;
    }
}

void Rubiks_moves::Check_clockwise(sf::Event *event) {
    if (event->key.code == sf::Keyboard::LShift ||
        event->key.code == sf::Keyboard::RShift) {
        if (clockwise != -1 && event->type == sf::Event::KeyPressed)
            clockwise = -1;
        if (clockwise != 1 && event->type == sf::Event::KeyReleased)
            clockwise = 1;
    }
}

void Rubiks_moves::Moves(sf::Event *event, action_t *action) {
    Check_clockwise(event);
    if (rotating)
        return;
    if (event->type == sf::Event::KeyPressed) {
        // CHECK STANDART KEYS
        for (size_t i = 0; i < keyboard_moves.size(); i++) {
            if (event->key.code == keyboard_moves[i]) {
                rotating = true;
                *action = clockwise_moves[i] * clockwise;
                return;
            }
        }

        // CHECK NUMPAD KEYS
        for (size_t i = 0; i < numpadkey_moves.size(); i++) {
            if (event->key.code == numpadkey_moves[i]) {
                rotating = true;
                *action = numpad_moves[i] * clockwise;
                return;
            }
        }
    }
}
