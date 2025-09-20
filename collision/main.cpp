#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Collision");

    sf::RectangleShape rect(sf::Vector2f(100.f, 100.f)); // ширина 120, висота 50
    sf::Vector2f rectanglePosition(400.f, 300.f);
    rect.setPosition(rectanglePosition);
    rect.setFillColor(sf::Color::White);

    float xVelocity = 1.5;
    float yVelocity= 1.5;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed){
                window.close();
            }
                
        }
        // physics

        if (rectanglePosition.x < 0|| rectanglePosition.x > 800-100 )
        {
            xVelocity *= -1;
        }
        if (rectanglePosition.y < 0|| rectanglePosition.y > 600 - 100)
        {
            yVelocity *= -1;
        }

        rectanglePosition.x += xVelocity;
        rectanglePosition.y += yVelocity;

        rect.setPosition(rectanglePosition);

        //rendering
        window.clear();
        window.draw(rect);
        window.display();
    }

    return 0;
}
