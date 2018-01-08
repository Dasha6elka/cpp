#include <SFML/Graphics.hpp>
#include <vector>

constexpr unsigned WINDOW_WIDTH = 800;
constexpr unsigned WINDOW_HEIGHT = 600;
const unsigned BALL_SIZE = 40;

struct Balls
{
    sf::CircleShape shapes;
    sf::Vector2f speed;
};

void init(std::vector<Balls> &balls)
{
    const std::vector<sf::Color> colors = {
        sf::Color(255, 0, 0),
        sf::Color(0, 255, 0),
        sf::Color(0, 0, 255),
        sf::Color(255, 255, 0),
        sf::Color(255, 0, 255)};
    const std::vector<sf::Vector2f> speeds = {
        {50.f, 50.f},
        {100.f, 100.f},
        {150.f, 150.f},
        {200.f, 200.f},
        {250.f, 250.f}};
    const std::vector<sf::Vector2f> positions = {
        {10, 10},
        {60, 60},
        {120, 120},
        {180, 180},
        {240, 240}};
    for (size_t i = 0; i < balls.size(); ++i)
    {
        balls[i].speed = speeds[i];
        balls[i].shapes.setPosition(positions[i]);
        balls[i].shapes.setRadius(BALL_SIZE);
        balls[i].shapes.setFillColor(colors[i]);
    }
}

void pollEvents(sf::RenderWindow &window)
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            window.close();
            break;
        default:
            break;
        }
    }
}

void update(std::vector<Balls> &balls, float &dt)
{
    for (size_t i = 0; i < balls.size(); ++i)
    {
        sf::Vector2f position = balls[i].shapes.getPosition();
        position += balls[i].speed * dt;

        if ((position.x + 2 * BALL_SIZE >= WINDOW_WIDTH) && (balls[i].speed.x > 0))
        {
            balls[i].speed.x = -balls[i].speed.x;
        }
        if ((position.x < 0) && (balls[i].speed.x < 0))
        {
            balls[i].speed.x = -balls[i].speed.x;
        }
        if ((position.y + 2 * BALL_SIZE >= WINDOW_HEIGHT) && (balls[i].speed.y > 0))
        {
            balls[i].speed.y = -balls[i].speed.y;
        }
        if ((position.y < 0) && (balls[i].speed.y < 0))
        {
            balls[i].speed.y = -balls[i].speed.y;
        }
        balls[i].shapes.setPosition(position);
    }
}

void redrawFrame(sf::RenderWindow &window, std::vector<Balls> &balls)
{
    window.clear();
    for (size_t i = 0; i < balls.size(); ++i)
    {
        window.draw(balls[i].shapes);
    }
    window.display();
}

int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode{WINDOW_WIDTH, WINDOW_HEIGHT}, "Balls", sf::Style::Default, settings);
    sf::Clock clock;

    std::vector<Balls> balls(5);
    init(balls);

    while (window.isOpen())
    {
        pollEvents(window);
        float dt = clock.restart().asSeconds();
        update(balls, dt);
        redrawFrame(window, balls);
    }
}