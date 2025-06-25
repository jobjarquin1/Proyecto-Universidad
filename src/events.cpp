#include "events.hpp"
#include <optional>

void processEvents(sf::Window& window)
{
    while (auto event = window.pollEvent())
    {
        // Cerrar ventana si es Closed o Escape
        if (event->is<sf::Event::Closed>() ||
            (event->is<sf::Event::KeyPressed>() &&
             event->getIf<sf::Event::KeyPressed>()->code == sf::Keyboard::Key::Escape))
        {
            window.close();
        }
    }
}