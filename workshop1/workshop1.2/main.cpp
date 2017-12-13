#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <cmath>
#include "arrow.hpp"

void Arrow::initShape()
{
    this->shape.setPosition(this->position);
    this->shape.setRotation(this->rotation);
    this->shape.setOutlineThickness(5);
    this->shape.setOutlineColor(sf::Color(0, 0, 0));
    this->shape.setPointCount(7);
    this->shape.setPoint(0, {0, 80});
    this->shape.setPoint(1, {80, 0});
    this->shape.setPoint(2, {0, -80});
    this->shape.setPoint(3, {0, -40});
    this->shape.setPoint(4, {-80, -40});
    this->shape.setPoint(5, {-80, 40});
    this->shape.setPoint(6, {0, 40});
    this->shape.setFillColor(sf::Color(0xFF, 0xFF, 0x00));
}

void init(Arrow &arrow)
{
    arrow.initShape();
}

float toDegrees(float radians)
{
    return float(double(radians) * 180.0 / M_PI);
}

void onMouseMove(sf::Event::MouseMoveEvent &event, sf::Vector2f &mousePosition)
{
    mousePosition = {static_cast<float>(event.x), static_cast<float>(event.y)};
}

void pollEvents(sf::RenderWindow &window, sf::Vector2f &mousePosition)
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            window.close();
            break;
        case sf::Event::MouseMoved:
            onMouseMove(event.mouseMove, mousePosition);
            break;
        default:
            break;
        }
    }
}

void Arrow::updateRotation(const sf::Vector2f &delta, float dt)
{
    float angle = atan2(delta.y, delta.x);
    if (angle < 0)
    {
        angle = static_cast<float>(angle + 2 * M_PI);
    }
    angle = toDegrees(angle);
    const float maxRotation = this->maxRotationSpeed * dt;
    const float prevRotation = this->shape.getRotation();
    const float rotation = std::abs(angle - prevRotation);
    if (angle != prevRotation)
    {
        if (angle < prevRotation)
        {
            if ((angle + 180) < prevRotation)
            {
                this->rotation = prevRotation + std::min(maxRotation, rotation);
            }
            else
            {
                this->rotation = prevRotation - std::min(maxRotation, rotation);
            }
        }
        else
        {
            if ((angle - 180) > prevRotation)
            {
                this->rotation = prevRotation - std::min(maxRotation, rotation);
            }
            else
            {
                this->rotation = prevRotation + std::min(maxRotation, rotation);
            }
        }
    }
}

void Arrow::updatePosition(const sf::Vector2f &delta, float dt)
{
    const float deltaLength = std::sqrt(std::pow(delta.x, 2) + std::pow(delta.y, 2));
    sf::Vector2f direction = {0, 0};
    if (deltaLength != 0)
    {
        direction = {(delta.x / deltaLength), (delta.y / deltaLength)};
    }
    this->position = this->position + direction * this->maxMotionSpeed * dt;
}

void Arrow::updateElements()
{
    this->shape.setRotation(this->rotation);
    this->shape.setPosition(this->position);
}

void update(Arrow &arrow, sf::Vector2f &mousePosition, float dt)
{
    const sf::Vector2f delta = mousePosition - arrow.shape.getPosition();
    arrow.updateRotation(delta, dt);
    arrow.updatePosition(delta, dt);
    arrow.updateElements();
}

void redrawFrame(sf::RenderWindow &window, Arrow &arrow)
{
    window.clear(sf::Color(0xFF, 0xFF, 0xFF));
    window.draw(arrow.shape);
    window.display();
}

int main()
{
    constexpr unsigned WINDOW_WIDTH = 800;
    constexpr unsigned WINDOW_HEIGHT = 600;
    sf::Clock clock;

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}), "Arrow", sf::Style::Default, settings);

    Arrow arrow;
    sf::Vector2f mousePosition;

    init(arrow);

    while (window.isOpen())
    {
        pollEvents(window, mousePosition);
        float dt = clock.restart().asSeconds();
        update(arrow, mousePosition, dt);
        redrawFrame(window, arrow);
    }
}