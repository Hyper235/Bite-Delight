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
    sf::Sprite  bg;

    sf::Texture logoTexture;
    sf::Sprite  logo;

    sf::Font font;
    Button startButton;
    Button exitButton;

    void initMainMenu();
    void runMainMenuStep();
    void runGameStep();

    void handleMenuEvents();
    void updateMenu();
    void renderMenu();
};
#endif //OOP_GAME_H