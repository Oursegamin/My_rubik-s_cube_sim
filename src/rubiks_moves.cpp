/*
** EPITECH PROJECT, 2024
** My_rubik-s_cube_sim
** File description:
** rubiks_moves
*/

#include "main.h"

action_s::action_s() : axis(0), layer(0), dir(0) {}

action_s::action_s(int axis, int layer, float dir) :
    axis(axis),
    layer(layer),
    dir(dir) {}

action_s::action_s(const action_s &other) {
    axis = other.axis;
    layer = other.layer;
    dir = other.dir;
}

action_s::~action_s() {}

inline void action_s::operator=(const action_s &other) {
    axis = other.axis;
    layer = other.layer;
    dir = other.dir;
}

inline action_s action_s::operator*(const float clock) const {
    return {
        axis,
        layer,
        dir * clock
    };
}

inline void action_s::operator*=(const float clock) {
    *this = *this * clock;
}

Rubiks_moves::Rubiks_moves() {}

Rubiks_moves::~Rubiks_moves() {}


int Rubiks_moves::Get_true_face(Vector3f rotated_vector) {
    int index = 0;
    float current_max = 0;

    float dots[6] = {
        rotated_vector.Dot(ORIGINAL_TOP),
        rotated_vector.Dot(ORIGINAL_BOTTOM),
        rotated_vector.Dot(ORIGINAL_LEFT),
        rotated_vector.Dot(ORIGINAL_RIGHT),
        rotated_vector.Dot(ORIGINAL_FRONT),
        rotated_vector.Dot(ORIGINAL_BACK),
    };

    for (int i = 0; i < 6; i++) {
        if (current_max < dots[i]) {
            index = i;
            current_max = dots[i];
        }
    }

    return index;
}

action_t Rubiks_moves::Get_real_action(const Matrix4f &current_matrix, const Rubiks_faces_t face) {
    Rubiks_faces_t taken_face = face >= RUBIKS_MID_H ?
        (face == RUBIKS_MID_H ? RUBIKS_TOP : RUBIKS_LEFT) : face;
    int index = Get_true_face(current_matrix.TransformDirection(orginals_faces_vector[taken_face]));

    action_t action = actions[index];
    if (face >= RUBIKS_MID_H)
        return (action_t){
            action.axis,
            1,
            face == RUBIKS_MID_V ? action.dir * -1 : action.dir};
    return action;
}


void Rubiks_moves::Randomize(sf::Event *event) {
    if (rotating)
        return;
    if (!randomizing) {
        if (event->type == sf::Event::KeyPressed &&
            event->key.code == sf::Keyboard::M) {
            randomizing = true;
            animation_speed = RUBIKS_CUBE_RANDOM_MOVE_SPEED;
            if (!random_actions.empty())
                random_actions.clear();
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
                *action = Get_real_action(current_matrix, clockwise_moves[i]) * clockwise;
                return;
            }
        }

        // CHECK NUMPAD KEYS
        for (size_t i = 0; i < numpadkey_moves.size(); i++) {
            if (event->key.code == numpadkey_moves[i]) {
                rotating = true;
                *action = Get_real_action(current_matrix, numpad_moves[i]) * clockwise;
                return;
            }
        }
    }
}
