#include "main.hpp"

int main()
{
    sf::ContextSettings settings;
    sf::RenderWindow window(sf::VideoMode{WINDOW_WIDTH, WINDOW_HEIGHT}, "Cat");

    Cat cat;

    init(cat);

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

        window.clear(sf::Color(0xFF, 0xFF, 0xFF));
        window.draw(cat.sprite);
        window.display();
    }
}

void init(Cat &cat)
{
    cat.initCat();
}

void Cat::initCat()
{
    this->texture.loadFromFile("./img/cat.png");

    this->sprite.setTexture(this->texture);
    this->sprite.setTextureRect(sf::IntRect(0, 0, SPRITE_WIDTH, SPRITE_HEIGHT));
    this->sprite.setPosition(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
    this->sprite.setOrigin(SPRITE_WIDTH / 2, SPRITE_HEIGHT / 2);
}
