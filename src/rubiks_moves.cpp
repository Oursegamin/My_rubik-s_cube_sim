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

// void createRotationMatrix(const Vector3f angles, float matrix[3][3]) {
//     float cx = std::cos(angles.x), sx = std::sin(angles.x);
//     float cy = std::cos(angles.y), sy = std::sin(angles.y);
//     float cz = std::cos(angles.z), sz = std::sin(angles.z);

//     matrix[0][0] = cy * cz;
//     matrix[0][1] = cz * sx * sy - cx * sz;
//     matrix[0][2] = cx * cz * sy + sx * sz;

//     matrix[1][0] = cy * sz;
//     matrix[1][1] = cx * cz + sx * sy * sz;
//     matrix[1][2] = -cz * sx + cx * sy * sz;

//     matrix[2][0] = -sy;
//     matrix[2][1] = cy * sx;
//     matrix[2][2] = cx * cy;
// }

// action_t adjustAction(const Vector3f angles, const action_t &action) {
//     float rotationMatrix[3][3];
//     createRotationMatrix(angles, rotationMatrix);

//     int originalAxis = action.axis;
//     float originalDir[3] = {0.0f, 0.0f, 0.0f};
//     originalDir[originalAxis] = 1.0f;

//     float rotatedDir[3] = {0.0f, 0.0f, 0.0f};
//     for (int i = 0; i < 3; ++i) {
//         for (int j = 0; j < 3; ++j) {
//             rotatedDir[i] += rotationMatrix[i][j] * originalDir[j];
//         }
//     }

//     int adjustedAxis = 0;
//     for (int i = 0; i < 3; ++i) {
//         if (std::abs(rotatedDir[i]) > std::abs(rotatedDir[adjustedAxis])) {
//             adjustedAxis = i;
//         }
//     }

//     float adjustedDir = (rotatedDir[adjustedAxis] > 0) ? action.dir : -action.dir;

//     return {adjustedAxis, action.layer, adjustedDir};
// }

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
