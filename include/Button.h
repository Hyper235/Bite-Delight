//
// Created by Catalin on 12/4/2025.
//

#ifndef OOP_BUTTON_H
#define OOP_BUTTON_H
#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class Button {
public:
    Button(const sf::Vector2f& size,
           const sf::Font& font,
           const std::string& text)
        : m_shape(size)
        , m_text(font, text, 42)
    {
        // Stil buton
        m_shape.setFillColor(sf::Color(255, 160, 40));   // portocaliu
        m_shape.setOutlineThickness(4.f);
        m_shape.setOutlineColor(sf::Color(120, 60, 10));

        m_text.setFillColor(sf::Color::White);

        auto bounds = m_text.getLocalBounds();
        m_text.setOrigin({bounds.size.x / 2.f, bounds.size.y / 2.f});
    }

    void setPosition(const sf::Vector2f& pos) {
        m_shape.setPosition(pos);

        auto boxBounds = m_shape.getGlobalBounds();
        sf::Vector2f center{
            boxBounds.position.x + boxBounds.size.x / 2.f,
            boxBounds.position.y + boxBounds.size.y / 2.f
        };
        m_text.setPosition(center);
    }

    void draw(sf::RenderWindow& window) const {
        window.draw(m_shape);
        window.draw(m_text);
    }

    void setHover(bool hover) {
        if (hover) {
            m_shape.setFillColor(sf::Color(255, 190, 80));
        } else {
            m_shape.setFillColor(sf::Color(255, 160, 40));
        }
    }

    [[maybe_unused]]bool isMouseOver(const sf::RenderWindow& window) const {
        sf::Vector2i mousePosPixels = sf::Mouse::getPosition(window);
        sf::Vector2f mousePos{
            static_cast<float>(mousePosPixels.x),
            static_cast<float>(mousePosPixels.y)
        };

        return m_shape.getGlobalBounds().contains(mousePos);
    }

private:
    sf::RectangleShape m_shape;
    sf::Text           m_text;
};

#endif //OOP_BUTTON_H