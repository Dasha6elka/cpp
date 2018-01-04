#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <cmath>

static const unsigned WINDOW_WIDTH = 800;
static const unsigned WINDOW_HEIGHT = 600;
static const unsigned SPRITE_WIDTH = 38;
static const unsigned SPRITE_HEIGHT = 35;

struct Cat
{
    sf::Texture texture;

    sf::Sprite sprite;

    void initCat();

    sf::Vector2f position;
    sf::Vector2f scale;
    const float speed = 100.f;
};

struct Pointer
{
    sf::Texture texture;

    sf::Sprite sprite;

    void initPointer();

    sf::Vector2f position;
};

void updateElements(Cat &cat, Pointer &pointer);

void init(Cat &cat, Pointer &pointer);

void pollEvents(sf::RenderWindow &window, sf::Vector2f &clickPosition);

void update(const sf::Vector2f &clickPosition, Cat &cat, Pointer &pointer, const float deltaTime);

void redrawFrame(sf::RenderWindow &window, Cat &cat, Pointer &pointer);

void onMouseClick(sf::Event::MouseButtonEvent &event, sf::Vector2f &clickPosition);

float toDegrees(float radians);

float getLength(const sf::Vector2f &vector);

sf::Vector2f normalizeVector(const sf::Vector2f &vector, const float vectorLenght);