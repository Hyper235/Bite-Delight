#include <SFML/Graphics.hpp>

class Button {
public:
  Button(const sf::Vector2f &size, const sf::Font &font,
         const std::string &text)
      : m_shape(size), m_text(font, text, 42) {
    m_shape.setFillColor(sf::Color(255, 160, 40));
    m_shape.setOutlineThickness(4.f);
    m_shape.setOutlineColor(sf::Color(120, 60, 10));

    m_text.setFillColor(sf::Color::White);
  }

  void setPosition(const sf::Vector2f &pos) {
    m_shape.setPosition(pos);

    const auto box = m_shape.getGlobalBounds();
    const auto text = m_text.getLocalBounds();

    m_text.setPosition(
        {box.position.x + (box.size.x - text.size.x) / 2.f - text.position.x,
         box.position.y + (box.size.y - text.size.y) / 2.f - text.position.y});
  }

  void draw(sf::RenderWindow &window) const {
    window.draw(m_shape);
    window.draw(m_text);
  }

  void setHover(bool hover) {
    m_shape.setFillColor(hover ? sf::Color(255, 190, 80)
                               : sf::Color(255, 160, 40));
  }

  bool isMouseOver(const sf::RenderWindow &window) const {
    auto mouse = sf::Mouse::getPosition(window);
    return m_shape.getGlobalBounds().contains(
        sf::Vector2f(static_cast<float>(mouse.x), static_cast<float>(mouse.y)));
  }

private:
  sf::RectangleShape m_shape;
  sf::Text m_text;
};
