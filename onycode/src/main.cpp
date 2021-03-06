#include"UserInterface.hpp"
int main() {
  std::cout.precision(6);
  std::cout.setf(std::ios::fixed);
  sf::ContextSettings csettings;
  csettings.antialiasingLevel = 16;

  bool loaded = true;
  struct BaseData base_data;
  loadAssets(base_data, loaded);
  if (!loaded) {
    std::cerr << "The resource cannot be loaded!";
    return -1;
  }
  std::ifstream fin("defines.txt");
  if (!fin.is_open()) {
    std::cout << "The definition file cannot be opened";
    return -1;
  }
  setupAliases(base_data, fin);
  int duration = 450;
  sf::Clock clock_carret;
  sf::Clock elapsed_time;
  initialSetup(base_data);
  //the file that contains the key words associated with their digit representation in base 10
//it is initially configured and after this function call it stores all the content of the `fin_en` file
  sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT),
                          (base_data.switches.is_english_language ? TITLE_EN : TITLE_RO),
                          sf::Style::Close | sf::Style::Titlebar,
                          csettings);
  window.setFramerateLimit(45);
  while (window.isOpen()) {
    sf::Event event = {};
    handleEvents(window, event, base_data);
    window.clear(base_data.colors.back);
    updateViewedString(base_data.input_form);
    sf::Time time_carret = clock_carret.getElapsedTime();
    if (time_carret.asMilliseconds() > duration) {
      clock_carret.restart().asMilliseconds();
      base_data.input_form.caret = !base_data.input_form.caret;
    }
    base_data.time_string = std::to_string(int(elapsed_time.getElapsedTime().asSeconds()));
    base_data.time.setString(base_data.time_string);
    base_data.time.setPosition(WIDTH - IMG_SCALED - 2*PADDING - base_data.time.getLocalBounds().width,
                               HEIGHT - IMG_SCALED - 2*PADDING);
    drawStaticElements(base_data, window);
  }
  return 0;
}
