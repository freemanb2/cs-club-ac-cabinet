#include <iostream>

#include "State_MainMenu.hpp"
#include "State_SplashScreen.hpp"
#include "Game.hpp"

State_MainMenu::State_MainMenu(SharedContext & ctx) : State_Base(ctx),
playBtn(), instructionsBtn() {
  if (!font.loadFromFile("assets/font/Regular.ttf")) {
    std::cerr << "State_SplashScreen could not load font from file: assets/font/Regular.ttf" << std::endl;
    exit(1);
  }

  titleText.setFont(font);
  titleText.setFillColor(sf::Color::Red);
  titleText.setCharacterSize(140);
  titleText.setString("Main Menu");
  sf::FloatRect titleTextBounds = titleText.getLocalBounds();
  titleText.setOrigin(titleTextBounds.width / 2, titleTextBounds.height / 2);

  sf::Vector2u windowSize = ctx.window.getSize();
  titleText.setPosition(windowSize.x / 2, windowSize.y / 2 - 400);

  playBtn.setBackgroundColor(sf::Color::Red);
  playBtn.setLabel("Play Cube Checkers");
  playBtn.setOrigin(sf::Vector2f(playBtn.getSize().x / 2, playBtn.getSize().y / 2));
  playBtn.setPosition(sf::Vector2f(windowSize.x / 2, windowSize.y / 2 - 150));
  playBtn.setSelected(true);

  instructionsBtn.setBackgroundColor(sf::Color::Red);
  instructionsBtn.setLabel("How to Play");
  instructionsBtn.setOrigin(sf::Vector2f(instructionsBtn.getSize().x / 2, instructionsBtn.getSize().y / 2));
  instructionsBtn.setPosition(sf::Vector2f(windowSize.x / 2, windowSize.y / 2));
}

State_MainMenu::~State_MainMenu() {}

void State_MainMenu::handleEvent(sf::Event e) {
  if (e.type == sf::Event::Closed) {
    ctx.window.close();
  } else if (e.type == sf::Event::KeyPressed) {
    switch(e.key.code) {
      case sf::Keyboard::W:
      case sf::Keyboard::S:
      case sf::Keyboard::I:
      case sf::Keyboard::K:
        playBtn.toggleSelected();
        instructionsBtn.toggleSelected();
        break;
      default:
        break;
    }
  }
}

void State_MainMenu::update() {}

void State_MainMenu::render() {
  ctx.window.draw(titleText);
  ctx.window.draw(playBtn);
  ctx.window.draw(instructionsBtn);
}
