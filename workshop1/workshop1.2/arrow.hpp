struct Arrow
{
    sf::ConvexShape shape;

    float rotation = 0;
    sf::Vector2f position = {400, 300};
    float maxRotationSpeed = 90.f;
    float maxMotionSpeed = 20.f;

    void initShape();

    void updateRotation(const sf::Vector2f &delta, float dt);

    void updatePosition(const sf::Vector2f &delta, float dt);

    void updateElements();
};