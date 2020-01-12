#include"UserInterface.hpp"
#include<random>

static std::random_device rd;
static std::mt19937 rng(rd());
int randomizator(int a, int b) {
  std::uniform_int_distribution<int> uid(a, b); // not static
  return uid(rng);
}
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
  base_data.theme_index = randomizator(0, base_data.number_of_themes - 1);

  std::ifstream fin("defines.txt");
  if (!fin.is_open()) {
    std::cout << "The definition file cannot be opened";
    return -1;
  }
  setupAliases(base_data, fin);

//  base_data.switches.is_music = false;
//  base_data.switches.is_sfx = false;
//  base_data.switches.is_dark_mode = true;
//base_data.switches.is_english_language=false;

  int duration = 450;
  sf::Clock clock_carret;
  initialSetup(base_data);
  //the file that contains the key words associated with their digit representation in base 10
//it is initially configured and after this function call it stores all the content of the `fin_en` file
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
    drawStaticElements(base_data, window);
  }
  return 0;
}
