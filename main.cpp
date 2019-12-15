#include"UserInterface.hpp"
#include<iostream>
int main() {
  //////////////////////////////////////// Crearea ferestrei ////////////////////////////////////////
  //se seteaza nivelul antialiasing mare pentru ca obiectele/formele geometrice sa nu fie desenate pixelat
  //crearea ferestrei
  sf::ContextSettings csettings;
  csettings.antialiasingLevel = 16;
  sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), TITLE, sf::Style::Close | sf::Style::Titlebar, csettings);
  bool loaded = true;
  struct UIData ui_data;
  loadResources(ui_data, loaded);
  if (!loaded) {
    std::cerr << "Nu au putut fi incarcate resursele!";
    return -1;
  }
  ui_data.switch_dark_mode = true;
  setupUI(ui_data);
  while (window.isOpen()) {
    sf::Event event = {};
    handleEvents(window, event, ui_data);
    setVolume(ui_data);
    drawUI(ui_data, window);
  }
  return 0;
}