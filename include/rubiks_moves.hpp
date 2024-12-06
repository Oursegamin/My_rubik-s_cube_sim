/*
** EPITECH PROJECT, 2024
** My_rubik-s_cube_sim
** File description:
** rubiks_moves
*/

#pragma once
#ifndef RUBIKS_MOVES_HPP_
#define RUBIKS_MOVES_HPP_

#include <SFML/Graphics.hpp>
#include "moves.h"

class Rubiks_moves {
    float clockwise = 1.f;

    bool randomizing = false;
    std::vector<action_t> random_actions;

    protected:
        bool rotating = false;
        Matrix4f current_matrix; 

        float animation_angle = 0.f;
        int animation_speed = RUBIKS_CUBE_DEFAULT_MOVE_SPEED;

    public:
        Rubiks_moves();
        ~Rubiks_moves();

        void Randomize(sf::Event *event);
        void Update_randomization(action_t *action);

        void Check_clockwise(sf::Event *event);
        void Moves(sf::Event *event, action_t *action);
};

#endif /* !RUBIKS_MOVES_HPP_ */
