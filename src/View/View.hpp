/*
** EPITECH PROJECT, 2022
** gravitySpacial
** File description:
** View
*/

#pragma once

#include "SFML.hpp"

class View {
    public:
        View();
        ~View();

        void update();

        sf::View &getView() { return _view; }
        float getZoom() const { return _zoom; }
    protected:
    private:
        sf::View _view;
        float _zoom = 1;
        sf::Vector2f _position;
};
