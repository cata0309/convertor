#include"UserInterface.hpp"

void setupAliases(BaseData &base_data, std::ifstream &fin) {
  Aliases aliases[MAX_ENTRIES];
  int dimension = 0;
  char word[MAX_KEY_DIM];
  int value;
  while (fin >> word && fin >> value) {
    strcpy(aliases[dimension].letters, word);
    aliases[dimension++].digits = value;
  }
  for (int i = 0; i < dimension; ++i) {
    strcpy(base_data.aliases[i].letters, aliases[i].letters);
    base_data.aliases[i].digits = aliases[i].digits;
  }
  strcpy(base_data.aliases[dimension-1].letters, aliases[dimension-1].letters);
  std::cout<<"check:"<< aliases[dimension-1].letters<<":"<<base_data.aliases[dimension-1].letters<<"\n";
  base_data.dimension = dimension;

  fin.close();
}
int main() {
  sf::Clock clock_fps;

  sf::ContextSettings csettings;
  csettings.antialiasingLevel = 16;
  sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), TITLE, sf::Style::Close | sf::Style::Titlebar, csettings);
  window.setFramerateLimit(30);
  bool loaded = true;
  struct BaseData base_data;
  loadAssets(base_data, loaded);
  if (!loaded) {
    std::cerr << "The resource cannot be loaded!";
    return -1;
  }
  int duration = 450;
  sf::Clock clock_carret;
//  base_data.switch_dark_mode = true;
  base_data.switches.is_music = false;
  base_data.switches.is_sfx = false;
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
    std::cout << "output:" << (base_data.output_string.toAnsiString()) << "\n";
    sf::Event event = {};
    handleEvents(window, event, base_data);
//    setSongVolume(base_data);
    sf::Time time_fps = clock_fps.getElapsedTime();
//    std::cout <<"fps: "<< 1.f/time_fps.asSeconds() << std::endl;
    clock_fps.restart().asSeconds();
    window.clear(base_data.colors.back);
    updateViewedString(base_data.input_form);

    sf::Time time_carret = clock_carret.getElapsedTime();
    if (time_carret.asMilliseconds() > duration) {
      clock_carret.restart().asMilliseconds();
      base_data.input_form.carret = !base_data.input_form.carret;
    }

//    base_data.output.setString("dsds");
std::cout<<"input:"<<base_data.input_form.input.toAnsiString()<<"\n";
    base_data.output.setPosition(300, 300);
    base_data.output.setFillColor(sf::Color::Black);
    window.draw(base_data.output);
    drawStaticElements(base_data,
                       window);
  }
  return 0;
}

/*
 * //
//`input` is a temporary C type string where we store our raw input: First phase of input manipulation: Getting it
  char input[MAX_INPUT];


  //the reading process is done via the console(it will be changed by SFML `interpretation of GUI` mimics
  std::cin.get(input, MAX_INPUT);

  bool success = true;
  double result = 0;
  if (strlen(input)==0) {
    success = false;
  } else {
    processingInput(input, success, result, aliases, dimension);
  }
  if (success) {
    std::cout << "Notatia postfixata este corecta iar rezultatul este: " << result;
  } else {
    std::cout << "Wrong input!";
  }
 * */