#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Initials");

    window.clear();

    sf::RectangleShape shapel;
    shapel.setSize({100, 10});
    shapel.setPosition({200, 120});
    shapel.setFillColor(sf::Color(0xFF, 0xFF, 0xFF));
    window.draw(shapel);

    sf::RectangleShape shape2;
    shape2.setSize({110, 10});
    shape2.setRotation(90);
    shape2.setPosition({200, 120});
    shape2.setFillColor(sf::Color(0xFF, 0xFF, 0xFF));
    window.draw(shape2);

    sf::RectangleShape shape3;
    shape3.setSize({100, 10});
    shape3.setPosition({200, 220});
    shape3.setFillColor(sf::Color(0xFF, 0xFF, 0xFF));
    window.draw(shape3);

    sf::RectangleShape shape4;
    shape4.setSize({100, 10});
    shape4.setRotation(90);
    shape4.setPosition({300, 230});
    shape4.setFillColor(sf::Color(0xFF, 0xFF, 0xFF));
    window.draw(shape4);

    sf::RectangleShape shape5;
    shape5.setSize({110, 10});
    shape5.setPosition({190, 320});
    shape5.setFillColor(sf::Color(0xFF, 0xFF, 0xFF));
    window.draw(shape5);

    sf::RectangleShape shape6;
    shape6.setSize({210, 10});
    shape6.setRotation(90);
    shape6.setPosition({340, 120});
    shape6.setFillColor(sf::Color(0xFF, 0xFF, 0xFF));
    window.draw(shape6);

    sf::RectangleShape shape7;
    shape7.setSize({99.5, 10});
    shape7.setRotation(25);
    shape7.setPosition({340, 120});
    shape7.setFillColor(sf::Color(0xFF, 0xFF, 0xFF));
    window.draw(shape7);

    sf::RectangleShape shape8;
    shape8.setSize({103, 10});
    shape8.setRotation(-25);
    shape8.setPosition({332.5, 321.75});
    shape8.setFillColor(sf::Color(0xFF, 0xFF, 0xFF));
    window.draw(shape8);

    sf::RectangleShape shape9;
    shape9.setSize({124, 10});
    shape9.setRotation(90);
    shape9.setPosition({430, 161.25});
    shape9.setFillColor(sf::Color(0xFF, 0xFF, 0xFF));
    window.draw(shape9);

    sf::RectangleShape shape10;
    shape10.setSize({100, 10});
    shape10.setPosition({470, 220});
    shape10.setFillColor(sf::Color(0xFF, 0xFF, 0xFF));
    window.draw(shape10);

    sf::RectangleShape shape11;
    shape11.setSize({110, 10});
    shape11.setRotation(90);
    shape11.setPosition({470, 120});
    shape11.setFillColor(sf::Color(0xFF, 0xFF, 0xFF));
    window.draw(shape11);

    sf::RectangleShape shape12;
    shape12.setSize({100, 10});
    shape12.setPosition({470, 120});
    shape12.setFillColor(sf::Color(0xFF, 0xFF, 0xFF));
    window.draw(shape12);

    sf::RectangleShape shape13;
    shape13.setSize({110, 10});
    shape13.setRotation(90);
    shape13.setPosition({570, 220});
    shape13.setFillColor(sf::Color(0xFF, 0xFF, 0xFF));
    window.draw(shape13);

    sf::RectangleShape shape14;
    shape14.setSize({110, 10});
    shape14.setPosition({460, 320});
    shape14.setFillColor(sf::Color(0xFF, 0xFF, 0xFF));
    window.draw(shape14);

    window.display();

    sf::sleep(sf::seconds(10));
}