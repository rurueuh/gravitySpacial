/*
** EPITECH PROJECT, 2022
** gravitySpacial
** File description:
** Terre
*/

#pragma once

#include "Planette.hpp"

class Terre : public Planette {
    public:
        Terre();
        ~Terre();

        void _update();
        void _draw(sf::RenderTarget &target);

        bool contollable = false;
    protected:
    private:    
};
