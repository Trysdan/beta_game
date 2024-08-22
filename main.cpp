#include <SFML/Graphics.hpp>
#include "Player.hpp"
#include "Settings.hpp"

int main() {
    // Crear la ventana usando los valores de Settings
    sf::RenderWindow window(sf::VideoMode(Settings::WINDOW_WIDTH, Settings::WINDOW_HEIGHT), "Sprite Movement");

    // Obtener la resolución de la pantalla y calcular la posición centrada
    sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();
    int posX = (desktopMode.width - Settings::WINDOW_WIDTH) / 2;
    int posY = (desktopMode.height - Settings::WINDOW_HEIGHT) / 2;
    window.setPosition(sf::Vector2i(posX, posY));

    // Limitar a FPS especificados en Settings
    window.setFramerateLimit(Settings::FPS);

    // Cargar la textura del fondo desde GRAPHICS_PATH
    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile((Settings::GRAPHICS_PATH / "village.png").string())) {
        return -1;
    }
    sf::Sprite background(backgroundTexture);

    // Crear el personaje
    Player player((Settings::GRAPHICS_PATH / "warrior.png").string(), 0.1f, 100.0f, sf::Vector2f(400, 300));

    sf::Clock clock;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Obtener el tiempo transcurrido
        float deltaTime = clock.restart().asSeconds();

        // Manejar la entrada del usuario y mover al personaje
        player.handleInput(deltaTime);

        // Dibujar en la ventana
        window.clear();
        window.draw(background); // Dibujar el fondo
        player.draw(window);     // Dibujar al personaje
        window.display();
    }

    return 0;
}
