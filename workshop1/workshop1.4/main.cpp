#include "main.hpp"
#include <iostream>

int main()
{
    sf::ContextSettings settings;
    sf::RenderWindow window(sf::VideoMode{WINDOW_WIDTH, WINDOW_HEIGHT}, "Go to pointer");
    sf::Clock clock;

    Cat cat;
    Pointer pointer;
    sf::Vector2f clickPosition = {WINDOW_WIDTH / 2.f, WINDOW_HEIGHT / 2.f};

    init(cat, pointer);

    while (window.isOpen())
    {
        pollEvents(window, clickPosition);
        const float deltaTime = clock.restart().asSeconds();
        update(clickPosition, cat, pointer, deltaTime);
        redrawFrame(window, cat, pointer);
    }
}

void init(Cat &cat, Pointer &pointer)
{
    cat.initCat();
    pointer.initPointer();
}

void Cat::initCat()
{
    texture.loadFromFile("./img/cat.png");

    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 0, SPRITE_WIDTH, SPRITE_HEIGHT));
    sprite.setPosition(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
    sprite.setOrigin(SPRITE_WIDTH / 2, SPRITE_HEIGHT / 2);
}

void Pointer::initPointer()
{
    texture.loadFromFile("./img/red_pointer.png");

    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
    sprite.setPosition(0, 0);
    sprite.setOrigin(18, 18);
}

void pollEvents(sf::RenderWindow &window, sf::Vector2f &clickPosition)
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            window.close();
            break;
        case sf::Event::MouseButtonPressed:
            onMouseClick(event.mouseButton, clickPosition);
            break;
        default:
            break;
        }
    }
}

void update(const sf::Vector2f &clickPosition, Cat &cat, Pointer &pointer, const float deltaTime)
{
    pointer.position = clickPosition;
    cat.position = cat.sprite.getPosition();

    const sf::Vector2f delta = pointer.position - cat.position;

    float angle = atan2(delta.x, delta.y);

    if (angle < 0)
    {
        angle = static_cast<float>(angle + 2 * M_PI);
    }
    angle = toDegrees(angle);

    if ((angle >= 0) && (angle <= 180))
    {
        cat.scale = {1, 1};
    }
    else
    {
        cat.scale = {-1, 1};
    }

    sf::Vector2f direction = {0, 0};
    const float deltaLenght = getLength(delta);
    if (deltaLenght != 0)
    {
        direction = normalizeVector(delta, deltaLenght);
        cat.position += direction * cat.speed * deltaTime;
    }
    updateElements(cat, pointer);
}

void updateElements(Cat &cat, Pointer &pointer)
{
    pointer.sprite.setPosition(pointer.position);
    cat.sprite.setPosition(cat.position);
    cat.sprite.setScale(cat.scale);
}

void redrawFrame(sf::RenderWindow &window, Cat &cat, Pointer &pointer)
{
    window.clear(sf::Color(0xFF, 0xFF, 0xFF));
    window.draw(pointer.sprite);
    window.draw(cat.sprite);
    window.display();
}

void onMouseClick(sf::Event::MouseButtonEvent &event, sf::Vector2f &clickPosition)
{
    clickPosition = {static_cast<float>(event.x), static_cast<float>(event.y)};
}

float toDegrees(float radians)
{
    return static_cast<float>(static_cast<double>(radians) * 180.0 / M_PI);
}

float getLength(const sf::Vector2f &vector)
{
    return std::sqrt(std::pow(vector.x, 2) + std::pow(vector.y, 2));
}

sf::Vector2f normalizeVector(const sf::Vector2f &vector, const float vectorLenght)
{
    return {vector.x / vectorLenght, vector.y / vectorLenght};
}