/*
** EPITECH PROJECT, 2022
** advencedCollision
** File description:
** Game
*/

#include "Game.hpp"

Game::Game()
{
    _window.create(sf::VideoMode(1920, 1080), "SPRITE CREATOR!");
    _window.setFramerateLimit(144);

    _font.loadFromFile("assets/font.ttf");

    _view = new View();
    _terre = new Terre();
    _terre2 = new Terre();
    _terre2->_mouvementCompenant->setVelocity(sf::Vector2f(16, 9));
}

Game::~Game()
{
    delete _terre;
    delete _terre2;
    delete _view;
}

void Game::run()
{
    while (_window.isOpen()) {
        sf::Event event;
        while (_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                _window.close();
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                _window.close();
        }
        update();
        draw();
    }
}

void Game::update()
{
    _terre->update();
    _terre2->update();
    _view->update();
}

void Game::draw()
{
    _window.clear();
    _window.setView(_view->getView());
    _terre->draw(_window);
    _terre2->draw(_window);
    _window.display();
}
