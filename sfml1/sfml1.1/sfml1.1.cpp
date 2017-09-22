#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode({120, 290}), "Traffic light");

    window.clear();

    sf::RectangleShape shapel;
    shapel.setSize({100, 275});
    shapel.setPosition({10, 5});
    shapel.setFillColor(sf::Color(0x40, 0x40, 0x40));
    window.draw(shapel);

    sf::CircleShape shape2(40);
    shape2.setPosition({20, 10});
    shape2.setFillColor(sf::Color(0x0, 0x80, 0x0));
    window.draw(shape2);

    sf::CircleShape shape3(40);
    shape3.setPosition({20, 100});
    shape3.setFillColor(sf::Color(0xFF, 0xCC, 0x0));
    window.draw(shape3);

    sf::CircleShape shape4(40);
    shape4.setPosition({20, 190});
    shape4.setFillColor(sf::Color(0xEE, 0x0, 0x0));
    window.draw(shape4);

    window.display();

    sf::sleep(sf::seconds(5));
}