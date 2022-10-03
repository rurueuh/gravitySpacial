/*
** EPITECH PROJECT, 2022
** gravitySpacial
** File description:
** Terre
*/

#include "Terre.hpp"
#include "Game.hpp"

Terre::Terre()
{
    this->initSprite("assets/planet.png");
    this->_sprite.setTextureRect(sf::IntRect(8, 6, 153, 153));
    static bool first = true;
    if (first) {
        this->_sprite.setPosition(100, 100);
        first = false;
        this->contollable = true;
    } else {
        this->_sprite.setPosition(50000000, 50000000);
    }
    // mass of earth
    int scale = 100;
    this->_sprite.setScale(scale, scale);
    this->initMouvementCompenant(5.972e24);
}

Terre::~Terre()
{
}

void Terre::_update()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
        if (this->contollable) {
            this->_sprite.setPosition(1000, 800);
        } else {
            this->_sprite.setPosition(100, 100);
        }
        this->_mouvementCompenant->setVelocity({0, 0});
    }
    if (this->contollable == false)
        return;
    int speed = 0.2 * Game::getInstance()._view->getZoom();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        this->_mouvementCompenant->addVelocity(sf::Vector2f(-speed, 0));
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        this->_mouvementCompenant->addVelocity(sf::Vector2f(speed, 0));
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        this->_mouvementCompenant->addVelocity(sf::Vector2f(0, -speed));
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        this->_mouvementCompenant->addVelocity(sf::Vector2f(0, speed));
}

void Terre::_draw(sf::RenderTarget &target)
{
    target.draw(this->_sprite);
}
