#include <SFML/Graphics.hpp>
#include <iostream>

int main() {

    sf::Time dt;
    sf::Clock speedClock;
    sf::Clock gameClock;
    sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();

    const float SCREEN_W = desktopMode.width;
    const float SCREEN_H = desktopMode.height;

    bool upPressed = false;
    bool dnPressed = false;
    bool rtPressed = false;
    bool lfPressed = false;

    float screenX = SCREEN_W/2;
    float screenY = SCREEN_H/2;

    const int USER_RADIUS = 50;
    int USER_SPEED = 1000; // px/s
    float FPS = (float)(1.0/120);
    sf::RenderWindow window(sf::VideoMode(SCREEN_W, SCREEN_H), "Bumpy Circles", sf::Style::Fullscreen);

    /*
     CIRCLE SHAPE
     */
    sf::CircleShape circle(USER_RADIUS);

    // radius and point count can be set after as well
    //shape.setRadius(100);
    //shape.setPointCount(3);

    // Red, Green and Blue from 0 to 255
    circle.setFillColor(sf::Color(66,135,245));
    circle.setOrigin(50,50);

    circle.setPosition(SCREEN_W/2, SCREEN_H/2);

    while (window.isOpen()) {
      dt += gameClock.restart();
        sf::Event event;

        while (window.pollEvent(event)) {

          switch (event.type) {

            case sf::Event::Closed:
              window.close();
              break;

            case sf::Event::KeyPressed: {
              switch (event.key.code){
                case sf::Keyboard::Slash:
                  window.close();
                  break;

                case sf::Keyboard::W:
                  upPressed = true;
                  break;

                case sf::Keyboard::S:
                  dnPressed = true;
                  break;

                case sf::Keyboard::A:
                  lfPressed = true;
                  break;

                case sf::Keyboard::D:
                  rtPressed = true;
                  break;
              }
              break;
            }

            case sf::Event::KeyReleased: {
              switch (event.key.code){
                case sf::Keyboard::W:
                  upPressed = false;
                  break;

                case sf::Keyboard::S:
                  dnPressed = false;
                  break;

                case sf::Keyboard::A:
                  lfPressed = false;
                  break;

                case sf::Keyboard::D:
                  rtPressed = false;
                  break;
              }

            default:
              // std::cout << "Unknown event" << std::endl;
            break;
          }
          break;
        }

      }

        if (dt.asSeconds() > FPS) {
          if (upPressed){
            if (screenY - (USER_SPEED * dt.asSeconds()) > circle.getRadius()){
              circle.move(0,-USER_SPEED * dt.asSeconds());
              screenY -= USER_SPEED * dt.asSeconds();
            }
          }
          if (dnPressed){
            if ((screenY + circle.getRadius()) + (USER_SPEED * dt.asSeconds()) < SCREEN_H){
              circle.move(0,USER_SPEED * dt.asSeconds());
              screenY += USER_SPEED * dt.asSeconds();
            }
          }
          if (rtPressed){
            if ((screenX + circle.getRadius()) + (USER_SPEED * dt.asSeconds()) < SCREEN_W){
              circle.move(USER_SPEED * dt.asSeconds(),0);
              screenX += USER_SPEED * dt.asSeconds();
            }
          }
          if (lfPressed){
            if (screenX - (USER_SPEED * dt.asSeconds()) > circle.getRadius()){
              circle.move(-USER_SPEED * dt.asSeconds(),0);
              screenX -= USER_SPEED * dt.asSeconds();
            }
          }
            dt -= sf::seconds(FPS);
        }

        window.clear();

        window.draw(circle);

        window.display();

    }
}
