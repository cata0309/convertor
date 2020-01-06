#include "SFML/Graphics.hpp"
#include <cstring>
#include <iostream>
#define width 400
#define height 400
#define TITLE "VISUAL FEEDBACK"
using std::string;
int main() {
  sf::ContextSettings settings;
  settings.antialiasingLevel = 16;
  sf::RenderWindow window(sf::VideoMode(width, height), TITLE,
                          sf::Style::Default, settings);
  sf::RectangleShape rect(sf::Vector2f(30, 30));
  rect.setFillColor(sf::Color::Black);

  bool focus = false;

  sf::Clock clock;
  sf::Font font;
  bool carret = true;
  if (!font.loadFromFile("consola.ttf")) {
    std::cout << "FONT NOT FOUNDED!";
  }
  string sir;
  char c;
  sf::Text text;
  text.setPosition(30, 30);
  text.setFont(font);
  text.setCharacterSize(20);
  text.setFillColor(sf::Color(0, 0, 0));
  sf::FloatRect area = rect.getGlobalBounds();

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type ==
          sf::Event::EventType::
              Closed /*||sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)*/) {
        window.close();
      }
      if (event.type == sf::Event::MouseButtonPressed) {
        sf::Vector2i mouse = sf::Mouse::getPosition(window);

        if (mouse.x >= rect.getPosition().x &&
            mouse.x <= rect.getPosition().x + rect.getSize().x &&
            mouse.y >= rect.getPosition().y &&
            mouse.y <= rect.getPosition().y + rect.getSize().y) {
          focus = !focus;
        }
      }

      if (event.type == sf::Event::TextEntered && focus) {
        char c = static_cast<char>(event.text.unicode);

        std::cout << "ASCII character typed: ";
        switch (int(c)) {
        case 32:
          std::cout << "spacebar";
          break;
        case 13:
          std::cout << "enter";
          break;
        case 8:
          if (sir.size() > 0) {
            sir = sir.substr(0, sir.size() - 1);
          }
          std::cout << "backspace";
          break;
        default:
          std::cout << c;
        }

        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ||
            (c >= '0' && c <= '9') || strchr("?.,()+-*/[]{}", c) ||
            int(c) == 32) {
          sir.push_back(c);
        }
        std::cout << "\n";
      }
    }
    window.clear(sf::Color::White);

    string de_afisat = sir;
    if (sir.size() > 15) {
      de_afisat = de_afisat.substr(sir.size() - 15, 15);
    }

    string with_carret = de_afisat;
    with_carret.push_back('|');
    if (focus) {
      if (!carret)
        text.setString(de_afisat);
      else
        text.setString(with_carret);

      window.draw(text);
      sf::Time time = clock.getElapsedTime();
      //  std::cout<<time.asSeconds()<<"\n";
      if (time.asMilliseconds() > 450) {
        clock.restart().asMilliseconds();
        carret = !carret;
      }
    } else {
      text.setString(with_carret);
      window.draw(text);
    }
    // std::cout<<((focus)?"FOCUS":"NONE");
    // std::cout<<"backend str: "<<sir<<"*\n";
    window.draw(rect);
    window.display();
  }

  return 0;
}
