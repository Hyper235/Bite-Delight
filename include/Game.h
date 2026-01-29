#ifndef OOP_GAME_H
#define OOP_GAME_H

#include "Button.h"
#include "Customer.h"
#include "Menu.h"
#include "Player.h"
#include "StatsUpdater.h"
#include <SFML/Graphics.hpp>
#include <vector>

enum class GameState { MainMenu, CreatePlayer, Playing, Exit };

class Game {
public:
  Game();
  void run();

private:
  Player player;
  sf::RenderWindow window;
  GameState state{GameState::MainMenu};

  sf::Texture bgTexture;
  sf::Sprite bg{bgTexture};

  sf::Texture logoTexture;
  sf::Sprite logo{logoTexture};

  sf::Font font;
  Button startButton;
  Button exitButton;

  void initMainMenu();
  void runMainMenuStep();
  void runGameStep();

  void handleMenuEvents();
  void renderMenu();

  void initCreatePlayerScreen();
  void runCreatePlayerStep();
  void renderCreatePlayer();

  sf::RectangleShape nameBox;
  sf::Text nameText;
  sf::Text nameLabel;
  Button startGameButton;
  std::string enteredName;
      bool nameBoxActive = false;
  
          std::vector<Customer> m_customers;
  
          StatsUpdater m_statsUpdater;

};

#endif