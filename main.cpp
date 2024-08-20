#include <SFML/Window.hpp>

int main(int argc, char** argv)
{
    sf::Window window(sf::VideoMode(1024, 768),
        "SFML Example - CodigoGrafico");
    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // when we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }
    return 0;
}