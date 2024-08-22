#include "Player.hpp"
#include "../Settings.hpp"

Player::Player(const std::string& textureFile, float switchTime, float speed, sf::Vector2f startPosition) {
    // Cargar la textura
    if (!texture.loadFromFile(textureFile)) {
        throw std::runtime_error("Error al cargar la textura");
    }

    // Configurar el sprite usando el tamaño definido en Settings
    sprite.setTexture(texture);
    frameWidth = Settings::PLAYER_WIDTH;
    frameHeight = Settings::PLAYER_HEIGHT;
    sprite.setTextureRect(sf::IntRect(frameWidth, 0, frameWidth, frameHeight));

    // Centrar el sprite considerando el tamaño del frame
    sprite.setOrigin(frameWidth / 2.0f, frameHeight / 2.0f);
    sprite.setPosition(startPosition);

    // Configuración de la animación y estado
    this->switchTime = switchTime;
    this->speed = speed;
    frame = 1;
    moving = false;
    lastRow = 0;
    animationTimer = 0.0f;
    currentState = State::Idle; // Estado inicial
}

void Player::handleInput(float deltaTime) {
    sf::Vector2f movement(0.0f, 0.0f);
    int row = lastRow; // Usar la última dirección por defecto
    moving = false;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        movement.y -= speed * deltaTime;
        row = 3; // Fila 4 (mirando hacia atrás)
        moving = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        movement.y += speed * deltaTime;
        row = 0; // Fila 1 (mirando hacia el frente)
        moving = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        movement.x -= speed * deltaTime;
        row = 1; // Fila 2 (mirando hacia la izquierda)
        moving = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        movement.x += speed * deltaTime;
        row = 2; // Fila 3 (mirando hacia la derecha)
        moving = true;
    }

    // Cambiar de estado según el movimiento
    if (moving) {
        currentState = State::Moving;
        lastRow = row; // Actualizar la última dirección
    } else {
        currentState = State::Idle;
    }

    // Actualizar la posición del sprite
    sprite.move(movement);
    updateAnimation(deltaTime);
}

void Player::updateAnimation(float deltaTime) {
    switch (currentState) {
        case State::Idle:
            // Si está en Idle, usar la columna 2 (frame 1)
            frame = 1;
            break;

        case State::Moving:
            // Si está en movimiento, alternar entre las columnas 1 y 3
            animationTimer += deltaTime;
            if (animationTimer >= switchTime) {
                animationTimer = 0.0f;
                frame = (frame == 0) ? 2 : 0; // Alternar entre columna 1 y 3
            }
            break;
    }

    // Actualizar el cuadro del sprite
    sprite.setTextureRect(sf::IntRect(frame * frameWidth, lastRow * frameHeight, frameWidth, frameHeight));
}

void Player::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}
