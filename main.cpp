#include"UserInterface.hpp"
#include<iostream>
int main() {
  sf::ContextSettings csettings;
  csettings.antialiasingLevel = 16;
  sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), TITLE, sf::Style::Close | sf::Style::Titlebar, csettings);
  bool loaded = true;
  struct BaseData base_data;
  loadAssets(base_data, loaded);
  if (!loaded) {
    std::cerr << "Nu au putut fi incarcate resursele!";
    return -1;
  }
//  base_data.switch_dark_mode = true;
  initialSetup(base_data);
  while (window.isOpen()) {
    sf::Event event = {};
    handleEvents(window, event, base_data);
//    setSongVolume(base_data);
    drawStaticElements(base_data,
                       window);
  }
  return 0;
}