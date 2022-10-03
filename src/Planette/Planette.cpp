/*
** EPITECH PROJECT, 2022
** gravitySpacial
** File description:
** Planette
*/

#include "Planette.hpp"

std::vector<Planette *> Planette::_planetteList = {};

void Planette::initMouvementCompenant(double mass)
{
    _mouvementCompenant = new MouvementCompenant(&this->_sprite, mass);
}

Planette::Planette()
{
    Planette::_planetteList.push_back(this);
}

Planette::~Planette()
{
    if (_mouvementCompenant)
        delete _mouvementCompenant;
}

void Planette::collision()
{
    for (auto &planette : Planette::_planetteList) {
        if (planette == this)
            continue;
        if (this->_sprite.getGlobalBounds().intersects(planette->_sprite.getGlobalBounds())) {
            std::cout << "Collision" << std::endl;
            this->_alive = false;
            planette->_alive = false;
        }
    }
}

void Planette::initSprite(std::string path)
{
    if (!_texture.loadFromFile(path))
        throw std::runtime_error("Can't load texture");
    _sprite.setTexture(_texture);
}

void Planette::draw(sf::RenderTarget &target)
{
    if (!_alive)
        return;
    _draw(target);
    if (_mouvementCompenant)
        _mouvementCompenant->draw(target);
}

void Planette::update()
{
    if (!_alive)
        return;
    _update();
    this->collision();
    if (_mouvementCompenant)
        _mouvementCompenant->update(this->_planetteList);
}
