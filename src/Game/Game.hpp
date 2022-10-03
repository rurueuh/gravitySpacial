/*
** EPITECH PROJECT, 2022
** advencedCollision
** File description:
** Game
*/

#pragma once

#include "SFML.hpp"
#include "Terre.hpp"
#include "View.hpp"

class Game {
    public:
        Game();
        ~Game();

        static Game &getInstance() {
            static Game instance;
            return instance;
        }

        void run();

        Terre *_terre = nullptr;
        Terre *_terre2 = nullptr;
        View *_view = nullptr;

    protected:
    private:
        void update();
        void draw();

        sf::Font _font;

        sf::RenderWindow _window;
};
