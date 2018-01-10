#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>
#include <random>
#include <ctime>

constexpr unsigned WINDOW_WIDTH = 800;
constexpr unsigned WINDOW_HEIGHT = 600;
constexpr unsigned BALL_SIZE = 40;
constexpr float MIN_SPEED = 50;
constexpr float MAX_SPEED = 300;

struct Balls
{
    sf::CircleShape shapes;
    sf::Vector2f speed;
};

struct PRNG
{
    std::mt19937 engine;
};

void initGenerator(PRNG &generator)
{
    const unsigned seed = unsigned(std::time(nullptr));
    generator.engine.seed(seed);
}

float getRandomSpeed(PRNG &generator, float minValue, float maxValue)
{
    std::uniform_real_distribution<float> distribution(minValue, maxValue);
    return distribution(generator.engine);
}

void init(std::vector<Balls> &balls)
{
    const std::vector<sf::Color> colors = {
        sf::Color(255, 0, 0),
        sf::Color(0, 255, 0),
        sf::Color(0, 0, 255),
        sf::Color(255, 255, 0),
        sf::Color(255, 0, 255)};

    const std::vector<sf::Vector2f> positions = {
        {10, 10},
        {100, 100},
        {200, 200},
        {300, 300},
        {400, 400}};

    PRNG generator;
    initGenerator(generator);

    for (size_t i = 0; i < balls.size(); ++i)
    {
        float minSpeed = getRandomSpeed(generator, MIN_SPEED, MAX_SPEED);
        float maxSpeed = getRandomSpeed(generator, MIN_SPEED, MAX_SPEED);

        balls[i].speed = {minSpeed, maxSpeed};
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

void updateBalls(std::vector<Balls> &balls)
{
    for (size_t i = 0; i < balls.size(); ++i)
    {
        for (size_t j = i + 1; j < balls.size(); ++j)
        {
            sf::Vector2f deltaPosition = balls[i].shapes.getPosition() - balls[j].shapes.getPosition();
            float distanceMin = hypot(deltaPosition.x, deltaPosition.y); //Сумма квадратов и всё это под корнем
            float distanceMax = BALL_SIZE * 2;
            if (distanceMin <= distanceMax)
            {
                sf::Vector2f deltaSpeed = balls[i].speed - balls[j].speed;
                float scalar = deltaPosition.x * deltaSpeed.x + deltaPosition.y * deltaSpeed.y;
                balls[i].speed = balls[i].speed - scalar * deltaPosition / float(std::pow(distanceMin, 2));
                balls[j].speed = balls[j].speed + scalar * deltaPosition / float(std::pow(distanceMin, 2));
            }
        }
    }
}

void update(std::vector<Balls> &balls, float dt)
{
    updateBalls(balls);

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