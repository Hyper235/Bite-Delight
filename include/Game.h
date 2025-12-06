//
// Created by Catalin on 12/6/2025.
//

#ifndef OOP_GAME_H
#define OOP_GAME_H
#include <SFML/Graphics.hpp>
#include "Button.h"

enum class GameState {
    MainMenu,
    Playing,
    Exit
};

class Game {
public:
    Game();
    void run();

private:
    sf::RenderWindow window;
    GameState state{GameState::MainMenu};
    //texturi
    sf::Texture bgTexture;
    sf::Sprite  bg{bgTexture};

    sf::Texture logoTexture;
    sf::Sprite  logo{logoTexture};

    sf::Font font;
    Button startButton;
    Button exitButton;

    [[maybe_unused]]void initMainMenu();
    [[maybe_unused]]void runMainMenuStep();
    [[maybe_unused]]void runGameStep();

    [[maybe_unused]]void handleMenuEvents();
    [[maybe_unused]]void updateMenu();
    [[maybe_unused]]void renderMenu();
};
#endif //OOP_GAME_H