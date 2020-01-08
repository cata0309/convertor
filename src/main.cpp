#include"UserInterface.hpp"
int main() {
  std::cout.precision(6);
  std::cout.setf(std::ios::fixed);
  sf::ContextSettings csettings;
  csettings.antialiasingLevel = 16;
  sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), TITLE, sf::Style::Close | sf::Style::Titlebar, csettings);
  window.setFramerateLimit(45);
  bool loaded = true;
  struct BaseData base_data;
  loadAssets(base_data, loaded);
  if (!loaded) {
    std::cerr << "The resource cannot be loaded!";
    return -1;
  }
//  base_data.switches.is_music = false;
//  base_data.switches.is_sfx = false;
  int duration = 450;
  sf::Clock clock_carret;
  initialSetup(base_data);
  //the file that contains the key words associated with their digit representation in base 10
  std::ifstream fin_en("defines_en.txt");
  if (!fin_en.is_open()) {
    std::cout << "NU";
    return -1;
  }
//it is initially configured and after this function call it stores all the content of the `fin_en` file
  setupAliases(base_data, fin_en);
  while (window.isOpen()) {
    sf::Event event = {};
    handleEvents(window, event, base_data);
    window.clear(base_data.colors.back);
//    window.draw(base_data.cross_background);
    updateViewedString(base_data.input_form);
    sf::Time time_carret = clock_carret.getElapsedTime();
    if (time_carret.asMilliseconds() > duration) {
      clock_carret.restart().asMilliseconds();
      base_data.input_form.carret = !base_data.input_form.carret;
    }
    drawStaticElements(base_data, window);
  }
  return 0;
}
