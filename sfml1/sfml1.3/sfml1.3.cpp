#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode({800, 600}), "House");

    window.clear();

    sf::RectangleShape shapel;
    shapel.setSize({350, 200});
    shapel.setPosition({225, 300});
    shapel.setFillColor(sf::Color(0x31, 0x33, 0x0));
    window.draw(shapel);

    sf::RectangleShape shape2;
    shape2.setSize({50, 125});
    shape2.setPosition({250, 375});
    shape2.setFillColor(sf::Color(0x20, 0x20, 0x20));
    window.draw(shape2);

    sf::ConvexShape trapeze;
    trapeze.setFillColor(sf::Color(0x70, 0x0, 0x0));
    trapeze.setPosition({400, 200});
    trapeze.setPointCount(4);
    trapeze.setPoint(0, {-100, 0});
    trapeze.setPoint(1, {+100, 0});
    trapeze.setPoint(2, {+225, 120});
    trapeze.setPoint(3, {-225, 120});
    window.draw(trapeze);

    sf::RectangleShape shape3;
    shape3.setSize({31, 60});
    shape3.setPosition({460, 175});
    shape3.setFillColor(sf::Color(0x40, 0x40, 0x40));
    window.draw(shape3);

    sf::CircleShape shape4(15);
    shape4.setPosition({465, 125});
    shape4.setFillColor(sf::Color(0xC0, 0xC0, 0xC0));
    window.draw(shape4);

    sf::RectangleShape shape5;
    shape5.setSize({50, 40});
    shape5.setPosition({450, 150});
    shape5.setFillColor(sf::Color(0x40, 0x40, 0x40));
    window.draw(shape5);

    sf::CircleShape shape6(15);
    shape6.setPosition({475, 105});
    shape6.setFillColor(sf::Color(0xC0, 0xC0, 0xC0));
    window.draw(shape6);

    sf::CircleShape shape7(20);
    shape7.setPosition({485, 90});
    shape7.setFillColor(sf::Color(0xC0, 0xC0, 0xC0));
    window.draw(shape7);

    sf::CircleShape shape8(25);
    shape8.setPosition({495, 65});
    shape8.setFillColor(sf::Color(0xC0, 0xC0, 0xC0));
    window.draw(shape8);

    window.display();

    sf::sleep(sf::seconds(10));
}