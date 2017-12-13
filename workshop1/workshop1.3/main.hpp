#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

static const unsigned WINDOW_WIDTH = 800;
static const unsigned WINDOW_HEIGHT = 600;
static const unsigned SPRITE_WIDTH = 38;
static const unsigned SPRITE_HEIGHT = 35;

struct Cat
{
    sf::Texture texture;

    sf::Sprite sprite;

    void initCat();
};

void init(Cat &cat);