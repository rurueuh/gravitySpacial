/*
** EPITECH PROJECT, 2022
** gravitySpacial
** File description:
** MouvementCompenant
*/

#pragma once

#include "SFML.hpp"
class Planette;

class MouvementCompenant {
    public:
        MouvementCompenant(sf::Sprite *sprite, double mass);
        ~MouvementCompenant();

        void update(std::vector<Planette *> &planetteList);
        void draw(sf::RenderTarget &target);

        void setVelocity(sf::Vector2f velocity) { _velocity = velocity; }
        void addVelocity(sf::Vector2f velocity) { _velocity += velocity; }

    protected:
    private:
        sf::Vector2f _velocity = {0, 0};
        double _mass = 0;
        float _gravity = 0;
        float _friction = 0;
        float _speed = 0;
        sf::Sprite *_sprite = nullptr;
};
