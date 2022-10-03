/*
** EPITECH PROJECT, 2022
** gravitySpacial
** File description:
** View
*/

#include "View.hpp"
#include "Game.hpp"

View::View()
{
    _view.setSize(1920, 1080);
}

View::~View()
{
}

void View::update()
{
    // ZOOM
    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
        _view.zoom(0.99);
        this->_zoom *= 0.99;
    } else if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right)) {
        _view.zoom(1.01);
        this->_zoom *= 1.01;
    }

    // RESET
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
        _view.setSize(1920, 1080);
        _view.move(-this->_position);
        this->_position = sf::Vector2f(0, 0);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R)) {
        sf::Vector2f pos = {
            Game::getInstance()._terre->_sprite.getPosition().x + Game::getInstance()._terre->_sprite.getGlobalBounds().width / 2,
            Game::getInstance()._terre->_sprite.getPosition().y + Game::getInstance()._terre->_sprite.getGlobalBounds().height / 2
        };
        _view.setCenter(pos);
        Game::getInstance()._terre2->contollable = false;
        Game::getInstance()._terre->contollable = true;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::T)) {
        sf::Vector2f pos = {
            Game::getInstance()._terre2->_sprite.getPosition().x + Game::getInstance()._terre2->_sprite.getGlobalBounds().width / 2,
            Game::getInstance()._terre2->_sprite.getPosition().y + Game::getInstance()._terre2->_sprite.getGlobalBounds().height / 2
        };
        _view.setCenter(pos);
        Game::getInstance()._terre2->contollable = true;
        Game::getInstance()._terre->contollable = false;
    }

    // MOVE
    int speed = 10 * this->_zoom;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Z)) {
        _view.move(0, -speed);
        this->_position.y -= speed;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
        _view.move(0, speed);
        this->_position.y += speed;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q)) {
        _view.move(-speed, 0);
        this->_position.x -= speed;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
        _view.move(speed, 0);
        this->_position.x += speed;
    }
        
}
