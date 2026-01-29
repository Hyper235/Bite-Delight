#include "../include/Game.h"
#include "Player.h"
#include "SaveManager.h"
#include <cstdlib>
#include <iostream>
// ================= CONSTRUCTOR =================

Game::Game()
    : window(sf::VideoMode({1920u, 1080u}), "Bite & Delight"),
      startButton({300.f, 80.f}, font, "Start Game"),
      exitButton({300.f, 80.f}, font, "Exit"), nameText(font), nameLabel(font),
      startGameButton({300.f, 80.f}, font, "Start Game") {
  window.setFramerateLimit(60);

  if (!font.openFromFile("fonts/arial.ttf")) {
    std::cerr << "Nu pot incarca fontul\n";
  }

  initMainMenu();
}

// ================= INIT MAIN MENU =================

void Game::initMainMenu() {
  const float W = window.getSize().x;
  const float H = window.getSize().y;

  if (!bgTexture.loadFromFile("date/img/bg.png")) {
    std::cerr << "Nu pot incarca background\n";
  }
  bg.setTexture(bgTexture, true);

  auto ts = bgTexture.getSize();
  bg.setScale(
      sf::Vector2f(static_cast<float>(W) / ts.x, static_cast<float>(H) / ts.y));

  if (!logoTexture.loadFromFile("date/img/logo.png")) {
    std::cerr << "Nu pot incarca logo\n";
  }
  logo.setTexture(logoTexture, true);
  logo.setOrigin(logo.getLocalBounds().size / 2.f);
  logo.setPosition({W / 2.f, 300.f});
  logo.setScale({0.5f, 0.5f});

  startButton.setPosition({W / 2.f - 150.f, 500.f});
  exitButton.setPosition({W / 2.f - 150.f, 620.f});
}

// ================= RUN =================

void Game::run() {
  while (window.isOpen() && state != GameState::Exit) {
    if (state == GameState::MainMenu)
      runMainMenuStep();
    else if (state == GameState::CreatePlayer)
      runCreatePlayerStep();
    else if (state == GameState::Playing)
      runGameStep();
  }
}

// ================= MAIN MENU =================

void Game::runMainMenuStep() {
  handleMenuEvents();
  renderMenu();
}

void Game::handleMenuEvents() {
  while (auto event = window.pollEvent()) {
    if (event->is<sf::Event::Closed>())
      window.close();
  }

  bool hStart = startButton.isMouseOver(window);
  bool hExit = exitButton.isMouseOver(window);

  startButton.setHover(hStart);
  exitButton.setHover(hExit);

  if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
    if (hStart && state == GameState::MainMenu) {

      if (SaveManager::getInstance().hasSave()) {

        if (!SaveManager::getInstance().loadPlayer(player)) {
          std::cerr << "Eroare la incarcare save!\n";
          return;
        }

        std::cout << "Loaded player: " << player.getName()
                  << " | Cash: " << player.getBalance()
                  << " | Days: " << player.getDays() << "\n";

        state = GameState::Playing;
      } else {
        state = GameState::CreatePlayer;
        initCreatePlayerScreen();
      }
    }
    if (hExit) {
      window.close();
    }
  }
}

void Game::renderMenu() {
  window.clear();
  window.draw(bg);
  window.draw(logo);
  startButton.draw(window);
  exitButton.draw(window);
  window.display();
}

// ================= CREATE PLAYER =================
void Game::initCreatePlayerScreen() {
  enteredName.clear();
  nameBoxActive = false;

  nameLabel.setFont(font);
  nameLabel.setString("Enter your name");
  nameLabel.setCharacterSize(36);
  nameLabel.setFillColor(sf::Color::White);
  nameLabel.setPosition({760.f, 380.f});

  nameBox.setSize({400.f, 60.f});
  nameBox.setFillColor(sf::Color(20, 20, 20, 200));
  nameBox.setOutlineThickness(3.f);
  nameBox.setOutlineColor(sf::Color::White);
  nameBox.setPosition({760.f, 430.f});

  nameText.setFont(font);
  nameText.setCharacterSize(28);
  nameText.setFillColor(sf::Color::White);
  nameText.setString("");

  startGameButton = Button({300.f, 80.f}, font, "Start Game");
  startGameButton.setPosition({810.f, 520.f});
}

void Game::runCreatePlayerStep() {

  while (auto event = window.pollEvent()) {

    // Închidere fereastră
    if (event->is<sf::Event::Closed>()) {
      window.close();
    }

    // CLICK mouse
    if (event->is<sf::Event::MouseButtonPressed>()) {

      auto mouse = sf::Mouse::getPosition(window);
      sf::Vector2f mpos{static_cast<float>(mouse.x),
                        static_cast<float>(mouse.y)};

      // activare / dezactivare casetă nume
      nameBoxActive = nameBox.getGlobalBounds().contains(mpos);
      nameBox.setOutlineColor(nameBoxActive ? sf::Color::Yellow
                                            : sf::Color::White);

      // CLICK pe Start Game
      if (startGameButton.isMouseOver(window)) {
        if (!enteredName.empty()) {

          // 1️⃣ Creezi Player
          player = Player(enteredName, 100.f); // Assign to member 'player'
          player.setDays(0);

          // 2️⃣ Salvezi (Singleton)
          if (!SaveManager::getInstance().savePlayer(player)) { // Now saves the member 'player'
            std::cerr << "Eroare: nu pot salva playerul!\n";
            return;
          }

          std::cout << "Save creat pentru: " << enteredName << "\n";

          // 3️⃣ Intri în joc
          state = GameState::Playing;
          return;
        }
      }
    }

    // INPUT TEXT (SFML 3 corect)
    if (nameBoxActive) {
      if (auto *textEvent = event->getIf<sf::Event::TextEntered>()) {

        char32_t code = textEvent->unicode;

        // ENTER → confirmare
        if (code == 13) {
          if (!enteredName.empty()) {

            this->player = Player(enteredName, 100.f); // Assign to member 'player'
            this->player.setDays(0);

            if (!SaveManager::getInstance().savePlayer(this->player)) {
              std::cerr << "Eroare: nu pot salva playerul!\n";
              return;
            }

            state = GameState::Playing;
            return;
          }
        }
        // BACKSPACE
        else if (code == 8) {
          if (!enteredName.empty())
            enteredName.pop_back();
        }
        // caractere ASCII valide
        else if (code >= 32 && code < 127 && enteredName.size() < 16) {
          enteredName += static_cast<char>(code);
        }

        nameText.setString(enteredName);

        // realiniere text în casetă (SFML 3)
        auto box = nameBox.getGlobalBounds();
        auto text = nameText.getLocalBounds();

        nameText.setPosition({box.position.x + 10.f - text.position.x,
                              box.position.y +
                                  (box.size.y - text.size.y) / 2.f -
                                  text.position.y});
      }
    }
  }

  renderCreatePlayer();
}

void Game::renderCreatePlayer() {
  window.clear();
  window.draw(bg);
  window.draw(nameLabel);
  window.draw(nameBox);
  window.draw(nameText);
  startGameButton.draw(window);
  window.display();
}
void Game::handleCreatePlayerEvents() {
  while (auto event = window.pollEvent()) {
    if (event->is<sf::Event::Closed>()) {
      window.close();
      state = GameState::Exit;
    }
  }
}

void Game::runGameStep() {
  window.clear(sf::Color::Black);
  window.display();
}

