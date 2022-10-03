/*
** EPITECH PROJECT, 2022
** gravitySpacial
** File description:
** MouvementCompenant
*/

#include "MouvementCompenant.hpp"
#include "Planette.hpp"

MouvementCompenant::MouvementCompenant(sf::Sprite *sprite, double mass)
{
    _sprite = sprite;
    _mass = mass;
}

MouvementCompenant::~MouvementCompenant()
{
}

void MouvementCompenant::update(std::vector<Planette *> &planetteList)
{
    for (auto &planette : planetteList) {
        if (planette->_mouvementCompenant == this)
            continue;
        sf::Vector2f distance = {_sprite->getPosition().x - planette->_sprite.getPosition().x, _sprite->getPosition().y - planette->_sprite.getPosition().y};
        float distanceLength = sqrt(pow(distance.x, 2) + pow(distance.y, 2));
        if (distanceLength < 10)
            distanceLength = 10;
        float force = 0.0000000000667 * _mass * planette->_mouvementCompenant->_mass / pow(distanceLength, 2);
        sf::Vector2f forceVector = {force * distance.x / distanceLength, force * distance.y / distanceLength};
        _velocity.x -= forceVector.x / _mass;
        _velocity.y -= forceVector.y / _mass;
    }
    _sprite->move({_velocity.x / 4, _velocity.y / 4});
    // _velocity.x *= 0.99;
    // _velocity.y *= 0.99;
}

void MouvementCompenant::draw(sf::RenderTarget &target)
{
    sf::Vector2f pos = {
        _sprite->getPosition().x, //+ _sprite->getGlobalBounds().width / 2,
        _sprite->getPosition().y  //+ _sprite->getGlobalBounds().height / 2
    };
    sf::Vertex line[2] = {
        sf::Vertex(pos, sf::Color::White),
        sf::Vertex(pos + (sf::Vector2f) {this->_velocity.x * 4, this->_velocity.y * 4}, sf::Color::White),
    };
    target.draw(line, 2, sf::Lines);
}
