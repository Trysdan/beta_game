#pragma once

#include <SFML/Graphics.hpp>

class Player {
public:
    // Enumeración para los estados
    enum class State {
        Idle,    // Estado quieto
        Moving   // Estado en movimiento
    };

    Player(const std::string& textureFile, float switchTime, float speed, sf::Vector2f startPosition);

    void handleInput(float deltaTime);
    void draw(sf::RenderWindow& window);

private:
    sf::Texture texture;
    sf::Sprite sprite;
    int frameWidth, frameHeight;
    float switchTime, animationTimer, speed;
    int frame, lastRow;
    bool moving;

    State currentState; // Estado actual del personaje

    void updateAnimation(float deltaTime);
};