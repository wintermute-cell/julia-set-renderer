#include <iostream>

#include "SFML/Graphics.hpp"

int main() {
    sf::Vector2f resolution(1920, 1080);

    sf::RenderWindow window(sf::VideoMode(resolution.x, resolution.y), "SFML works!", sf::Style::Close);

    if (!sf::Shader::isAvailable()) {
        std::cerr << "Shaders are not available on this system." << std::endl;
        return 1;
    }

    sf::RectangleShape baseRect(resolution);

    sf::Shader fractalShader;
    if (!fractalShader.loadFromFile("fractal.frag", sf::Shader::Fragment)) {
        std::cerr << "Failed to load shader. Is `fractal.frag` next to the executable?" << std::endl;
        return 1;
    }

    sf::Clock clock;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
            if (event.type == sf::Event::KeyPressed)
                if (event.key.code == sf::Keyboard::Escape) window.close();
        }

        fractalShader.setUniform("iResolution", resolution);
        fractalShader.setUniform("iTime", clock.getElapsedTime().asSeconds());
        fractalShader.setUniform("iEscapeRadius", 10.0f);

        window.clear();
        window.draw(baseRect, &fractalShader);
        window.display();
    }

    return 0;
}
