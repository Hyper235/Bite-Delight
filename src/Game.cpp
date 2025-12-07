#include "../include/Game.h"
#include <iostream>

Game::Game()
    : window(sf::RenderWindow(sf::VideoMode({1920u, 1080u}), "Bite & Delight")),
      startButton({300.f, 80.f}, font, "Start Game"),
      exitButton ({300.f, 80.f}, font, "Exit")
{
    window.setVerticalSyncEnabled(false);
    window.setFramerateLimit(60);
    initMainMenu();
}

void Game::initMainMenu() {
    const unsigned int W = window.getSize().x;
    const unsigned int H = window.getSize().y;

    if (!bgTexture.loadFromFile("date/img/bg.png")) {
        std::cerr << "Nu pot incarca date/img/bg.png\n";
    }
    bg.setTexture(bgTexture,true);

    auto ts = bgTexture.getSize();
    bg.setScale({
        W / float(ts.x),
        H / float(ts.y)
    });

    if (!logoTexture.loadFromFile("date/img/logo.png")) {
        std::cerr << "Nu pot incarca date/img/logo.png\n";
    }
    logo.setTexture(logoTexture,true);

    auto lb = logo.getLocalBounds();
    logo.setOrigin({ lb.size.x / 2.f, lb.size.y / 2.f });
    logo.setScale({0.5f, 0.5f});
    logo.setPosition({ W / 2.f, 300.f });


    if (!font.openFromFile("fonts/arial.ttf")) {
        std::cerr << "Nu pot incarca fonts/arial.ttf\n";
    }

    startButton = Button({300.f, 80.f}, font, "Start Game");
    exitButton  = Button({300.f, 80.f}, font, "Exit");

    startButton.setPosition({W / 2.f - 150.f, 500.f});
    exitButton.setPosition   ({W / 2.f - 150.f, 620.f});
}

void Game::run() {
    while (window.isOpen() && state != GameState::Exit) {
        if (state == GameState::MainMenu) runMainMenuStep();
        else if (state == GameState::Playing) runGameStep();
    }
}

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
    bool hExit  = exitButton.isMouseOver(window);

    startButton.setHover(hStart);
    exitButton.setHover(hExit);

    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
        if (hStart) {
            std::cout << "Start Game apasat\n";

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

void Game::runGameStep() {
    window.clear(sf::Color::Black);
    window.display();
}
