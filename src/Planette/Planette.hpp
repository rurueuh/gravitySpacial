/*
** EPITECH PROJECT, 2022
** gravitySpacial
** File description:
** Planette
*/

#pragma once

#include "SFML.hpp"
#include "MouvementCompenant.hpp"

class Planette {
    public:
        Planette();
        ~Planette();

        virtual void _update() = 0;
        virtual void _draw(sf::RenderTarget &) = 0;

        void draw(sf::RenderTarget &target);
        void update();
        void collision();

        void initMouvementCompenant(double mass);
        void initSprite(std::string path);

        MouvementCompenant *_mouvementCompenant = nullptr;
        static std::vector<Planette *> _planetteList;

        sf::Sprite _sprite;
    protected:
        sf::Texture _texture;
        bool _alive = true;
    private:
};
