#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cmath>
#include <iostream>

struct Eye
{
    sf::ConvexShape bigEllipse;
    sf::ConvexShape littleEllipse;
    sf::Vector2f position;
    float rotation = 0;
};

sf::Vector2f toEuclidean(sf::Vector2f radius, float angle)
{
    return {
        float(radius.x * cos(angle)),
        float(radius.y * sin(angle))};
}

void updateEyesElements(Eye &eye1, Eye &eye2)
{
    const sf::Vector2f motionRadius = {45.f, 85.f};

    const sf::Vector2f bigEllipseOneOffset = toEuclidean(motionRadius, eye1.rotation);
    eye1.littleEllipse.setPosition(eye1.position + bigEllipseOneOffset);

    const sf::Vector2f bigEllipseTwoOffset = toEuclidean(motionRadius, eye2.rotation);
    eye2.littleEllipse.setPosition(eye2.position + bigEllipseTwoOffset);
}

void initEyes(Eye &eye1, Eye &eye2)
{
    constexpr int pointCount = 200;
    const sf::Vector2f bigEllipseRadius = {75.f, 150.f};
    const sf::Vector2f littleEllipseRadius = {25.f, 60.f};

    eye1.position = {300, 300};
    eye2.position = {500, 300};

    eye1.bigEllipse.setPosition(eye1.position);
    eye1.bigEllipse.setFillColor(sf::Color(0xFF, 0xFF, 0xFF));
    eye1.bigEllipse.setPointCount(pointCount);
    eye2.bigEllipse.setPosition(eye2.position);
    eye2.bigEllipse.setFillColor(sf::Color(0xFF, 0xFF, 0xFF));
    eye2.bigEllipse.setPointCount(pointCount);
    for (int pointNo = 0; pointNo < pointCount; ++pointNo)
    {
        float angle = float(2 * M_PI * pointNo) / float(pointCount);
        sf::Vector2f point = {
            bigEllipseRadius.x * std::sin(angle),
            bigEllipseRadius.y * std::cos(angle)};
        eye1.bigEllipse.setPoint(pointNo, point);
        eye2.bigEllipse.setPoint(pointNo, point);
    }

    eye1.littleEllipse.setFillColor(sf::Color(0x00, 0x00, 0x00));
    eye1.littleEllipse.setPointCount(pointCount);
    eye2.littleEllipse.setFillColor(sf::Color(0x00, 0x00, 0x00));
    eye2.littleEllipse.setPointCount(pointCount);
    for (int pointNo = 0; pointNo < pointCount; ++pointNo)
    {
        float angle = float(2 * M_PI * pointNo) / float(pointCount);
        sf::Vector2f point = {
            littleEllipseRadius.x * std::sin(angle),
            littleEllipseRadius.y * std::cos(angle)};
        eye1.littleEllipse.setPoint(pointNo, point);
        eye2.littleEllipse.setPoint(pointNo, point);
    }

    updateEyesElements(eye1, eye2);
}

void onMouseMove(const sf::Event::MouseMoveEvent &event, sf::Vector2f &mousePosition)
{
    std::cout << "mouse x=" << event.x << ", y=" << event.y << std::endl;
    mousePosition = {float(event.x), float(event.y)};
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

void update(const sf::Vector2f &mousePosition, Eye &eye1, Eye &eye2)
{
    const sf::Vector2f EyeOneDelta = mousePosition - eye1.position;
    eye1.rotation = atan2(EyeOneDelta.y, EyeOneDelta.x);

    const sf::Vector2f EyeTwoDelta = mousePosition - eye2.position;
    eye2.rotation = atan2(EyeTwoDelta.y, EyeTwoDelta.x);

    updateEyesElements(eye1, eye2);
}

void redrawFrame(sf::RenderWindow &window, Eye &eye1, Eye &eye2)
{
    window.clear();
    window.draw(eye1.bigEllipse);
    window.draw(eye1.littleEllipse);
    window.draw(eye2.bigEllipse);
    window.draw(eye2.littleEllipse);
    window.display();
}

int main()
{
    constexpr unsigned WINDOW_WIDTH = 800;
    constexpr unsigned WINDOW_HEIGHT = 600;
    sf::Clock clock;

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(
        sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}), "Eyes",
        sf::Style::Default, settings);

    Eye eye1;
    Eye eye2;
    sf::Vector2f mousePosition;

    initEyes(eye1, eye2);
    while (window.isOpen())
    {
        pollEvents(window, mousePosition);
        update(mousePosition, eye1, eye2);
        redrawFrame(window, eye1, eye2);
    }
}