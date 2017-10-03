#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cmath>

constexpr unsigned WINDOW_WIDTH = 800;
constexpr unsigned WINDOW_HEIGHT = 600;

int main()
{
    constexpr int pointCount = 300;

    sf::ContextSettings setting;
    setting.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}), "Polar Rose", sf::Style::Default, setting);
    sf::Clock clock;

    sf::ConvexShape rose;
    const sf::Vector2f position = {WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2};
    rose.setFillColor(sf::Color(0x0, 0x0, 0xDD));

    const float bigRadius = 150;
    rose.setPointCount(pointCount);
    for (int pointNo = 0; pointNo < pointCount; ++pointNo)
    {
        float angle = float(2 * M_PI * pointNo) / float(pointCount);
        float radius = bigRadius * sin(6 * angle);
        sf::Vector2f point = {
            radius * std::sin(angle),
            radius * std::cos(angle)};
        rose.setPoint(pointNo, point);
    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        const float period = 3;
        float time = clock.getElapsedTime().asSeconds();
        float wavePhase = time * float(2 * M_PI);
        float x = bigRadius * std::cos(wavePhase / period);
        float y = bigRadius * std::sin(wavePhase / period);
        const sf::Vector2f offset = {x, y};

        rose.setPosition(position + offset);

        window.clear();
        window.draw(rose);
        window.display();
    }
}